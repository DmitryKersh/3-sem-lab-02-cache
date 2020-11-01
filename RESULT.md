#Investigation:
###Forward
experiments:

	 - experiment:
		number: 1
		input_data:
			buffer_size: 32 KB
		results:
			duration: 3.0755

	 - experiment:
		number: 2
		input_data:
			buffer_size: 64 KB
		results:
			duration: 3.02554

	 - experiment:
		number: 3
		input_data:
			buffer_size: 256 KB
		results:
			duration: 2.97072

	 - experiment:
		number: 4
		input_data:
			buffer_size: 1536 KB
		results:
			duration: 2.95653

	 - experiment:
		number: 5
		input_data:
			buffer_size: 2304 KB
		results:
			duration: 3.05477

#Investigation:
###Reverse
experiments:

	 - experiment:
		number: 1
		input_data:
			buffer_size: 32 KB
		results:
			duration: 2.99408

	 - experiment:
		number: 2
		input_data:
			buffer_size: 64 KB
		results:
			duration: 2.94221

	 - experiment:
		number: 3
		input_data:
			buffer_size: 256 KB
		results:
			duration: 2.8578

	 - experiment:
		number: 4
		input_data:
			buffer_size: 1536 KB
		results:
			duration: 2.9231

	 - experiment:
		number: 5
		input_data:
			buffer_size: 2304 KB
		results:
			duration: 2.99682

#Investigation:
###Random
experiments:

	 - experiment:
		number: 1
		input_data:
			buffer_size: 32 KB
		results:
			duration: 7.17749

	 - experiment:
		number: 2
		input_data:
			buffer_size: 64 KB
		results:
			duration: 8.66699

	 - experiment:
		number: 3
		input_data:
			buffer_size: 256 KB
		results:
			duration: 16.3362

	 - experiment:
		number: 4
		input_data:
			buffer_size: 1536 KB
		results:
			duration: 38.6119

	 - experiment:
		number: 5
		input_data:
			buffer_size: 2304 KB
		results:
			duration: 63.1844

