// Copyright 2020 Dmitry Karpukhin d.karpukhin@mail.ru

#include <header.hpp>

enum Direction { forward, reverse, randomm };

std::string to_string(const Direction& d) {
  switch (d) {
    case Direction::forward:
      return "Forward";
    case Direction::randomm:
      return "Random";
    case Direction::reverse:
      return "Reverse";
  }
  return "error";
}

double run_experiment(size_t arr_size, Direction dir, size_t iterations) {
  std::vector<int> arr(arr_size);
  // initializing array with order
  for (size_t i = 0; i < arr_size; i++) {
    arr[i] = i;
  }
  std::random_shuffle(arr.begin(), arr.end());

  int k;
  clock_t time;

  switch (dir) {
    case Direction::forward: {
      // warming up
      for (size_t i = 0; i < arr_size; i += 16) {
        k = arr[i];
      }

      // working
      time = clock();
      for (size_t iter_number = 0; iter_number < iterations; iter_number++) {
        for (size_t i = 0; i < arr_size; i++) {
          k = arr[i];
        }
      }
      time = clock() - time;
      break;
    }
    case Direction::reverse: {
      // warming up
      for (size_t i = arr_size; i > 0; i -= 16) {
        k = arr[i];
      }

      // working
      time = clock();
      for (size_t iter_number = 0; iter_number < iterations; iter_number++) {
        for (size_t i = arr_size; i > 0; i--) {
          k = arr[i];
        }
      }
      time = clock() - time;
      break;
    }
    case Direction::randomm: {
      // warming up
      for (size_t i = 0; i < arr_size; i += 16) {
        k = arr[i];
      }

      // working
      auto* seed = new unsigned int;
      *seed = 1231323;
      k = rand_r(seed) % arr_size;
      time = clock();
      for (size_t iter_number = 0; iter_number < iterations; iter_number++) {
        for (size_t i = 0; i < arr_size; i++) {
          k = arr[k];
        }
      }
      time = clock() - time;
      break;
    }
  }
  time = time + k - k;  // to avoid warning 'k is unused'
  // std::cout << "Experiment done in " << time / 1000000.0 << "s." <<
  // std::endl;
  return static_cast<double>(time) / iterations / arr_size *
         1000.0;  // returns nanoseconds
}

void report_multiple_experiments(const std::vector<ulong>& sizes,
                                 std::ostream& os, Direction d) {
  os << "#Investigation:\n###" << to_string(d) << std::endl
     << "experiments:\n"
     << std::endl;

  for (size_t exp_n = 0; exp_n < sizes.size(); exp_n++) {
    os << "\t - experiment:\n"
          "\t\tnumber: "
       << exp_n + 1 << std::endl
       << "\t\tinput_data:\n"
          "\t\t\tbuffer_size: "
       << sizes[exp_n] / 1024
       << " KB\n"
          "\t\tresults:\n"
          "\t\t\tduration: "
       << run_experiment(sizes[exp_n], d, 1000) << std::endl
       << std::endl;
  }
}

int main() {
  // Intel® Core™ i5-6300HQ 2.30 GHz
  //
  // L1, KB    4x32 + 4x32
  // L2, KB    4x256
  // L3, KB    6144
  // ________________________________________
  // |   1   |   2   |   3   |   4   |   5  |
  // ----------------------------------------
  // | 128kb | 256kb |  1mb  | 6mb   | 9mb  |
  // ----------------------------------------
  // |  32k  |  64k  | 256k  | 1.5m  | 2.25m|
  // ----------------------------------------

  std::vector<ulong> arr_sizes = {32 * 1024, 64 * 1024, 256 * 1024,
                                  3 * 512 * 1024, 9 * 256 * 1024};
  std::ofstream ofs("../RESULT.md");

  if (!ofs) {
    std::cerr << "File not found!" << std::endl;
  } else {
    clock_t time = clock();
    report_multiple_experiments(arr_sizes, ofs, Direction::forward);
    time = clock() - time;
    std::cout << "Forward access done in "
              << static_cast<double>(time) / 1000000.0 << "s." << std::endl;

    time = clock();
    report_multiple_experiments(arr_sizes, ofs, Direction::reverse);
    time = clock() - time;
    std::cout << "Reverse access done in "
              << static_cast<double>(time) / 1000000.0 << "s." << std::endl;

    time = clock();
    report_multiple_experiments(arr_sizes, ofs, Direction::randomm);
    time = clock() - time;
    std::cout << "Random access done in "
              << static_cast<double>(time) / 1000000.0 << "s." << std::endl;

    std::cout << "Success! Detailed report in RESULT.md" << std::endl;
  }
  return 0;
}
