#Investigation:
###Forward
experiments:

	 - experiment:
		number: 1
		input_data:
			buffer_size: 32 KB
		results:
			duration: 2.86011

	 - experiment:
		number: 2
		input_data:
			buffer_size: 64 KB
		results:
			duration: 2.65846

	 - experiment:
		number: 3
		input_data:
			buffer_size: 256 KB
		results:
			duration: 2.62509

	 - experiment:
		number: 4
		input_data:
			buffer_size: 1536 KB
		results:
			duration: 2.6706

	 - experiment:
		number: 5
		input_data:
			buffer_size: 2304 KB
		results:
			duration: 2.69173

#Investigation:
###Reverse
experiments:

	 - experiment:
		number: 1
		input_data:
			buffer_size: 32 KB
		results:
			duration: 2.60205

	 - experiment:
		number: 2
		input_data:
			buffer_size: 64 KB
		results:
			duration: 2.64302

	 - experiment:
		number: 3
		input_data:
			buffer_size: 256 KB
		results:
			duration: 2.60516

	 - experiment:
		number: 4
		input_data:
			buffer_size: 1536 KB
		results:
			duration: 2.64845

	 - experiment:
		number: 5
		input_data:
			buffer_size: 2304 KB
		results:
			duration: 2.6701

#Investigation:
###Random
experiments:

	 - experiment:
		number: 1
		input_data:
			buffer_size: 32 KB
		results:
			duration: 6.49066

	 - experiment:
		number: 2
		input_data:
			buffer_size: 64 KB
		results:
			duration: 7.86824

	 - experiment:
		number: 3
		input_data:
			buffer_size: 256 KB
		results:
			duration: 14.5449

	 - experiment:
		number: 4
		input_data:
			buffer_size: 1536 KB
		results:
			duration: 17.4173

	 - experiment:
		number: 5
		input_data:
			buffer_size: 2304 KB
		results:
			duration: 59.4138

