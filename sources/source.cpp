// Copyright 2020 Dmitry Karpukhin d.karpukhin@mail.ru

#include <algorithm>
#include <vector>
#include <header.hpp>

enum Direction{
  forward,
  reverse,
  randomm
};

double run_experiment(size_t arr_size, Direction dir, size_t iterations){
  int* arr = new int[arr_size];
  // initializing array
  for (size_t i = 0; i < arr_size; i++){
    arr[i] = rand();
  }
  int k;
  clock_t time;

  switch (dir) {
    case Direction::forward:{
      // warming up
      for (size_t i = 0; i < arr_size; i += 16) {
        k = arr[i];
      }

      // working
      time = clock();
      for (size_t iter_number = 0; iter_number < iterations; iter_number++) {
        for (size_t i = 0; i < arr_size; i += 16) {
          k = arr[i];
        }
      }
      time = clock() - time;
      break;
    }
    case Direction::reverse:{
      // warming up
      for (size_t i = arr_size; i > 0; i -= 16){
        k = arr[i];
      }

      // working
      time = clock();
      for (size_t iter_number = 0; iter_number < iterations; iter_number++) {
        for (size_t i = arr_size; i > 0; i -= 16) {
          k = arr[i];
        }
      }
      time = clock() - time;
      break;
    }
    case Direction::randomm:{
      /*
      // preparing random order
      std::vector<size_t> order(arr_size / 16);
      for (size_t i = 0; i < arr_size; i++){
        order[i] = i;
      }
      std::shuffle(order.begin(), order.end(), rand());
       */
      // warming up
      for (size_t i = 0; i < arr_size; i++){
        //k = arr[16 * order[i]];
        k = arr[(rand() % arr_size)/16];
      }
      // working
      time = clock();
      for (size_t iter_number = 0; iter_number < iterations; iter_number++){
        for (size_t i = 0; i < arr_size; i++) {
          // k = arr[16 * order[i]];
          k = arr[(rand() % arr_size) / 16];
        }
      }
      time = clock() - time;
      break;
    }
  }

  return long(time) / CLOCKS_PER_SEC;
}

int main() {

  return 0;
}
