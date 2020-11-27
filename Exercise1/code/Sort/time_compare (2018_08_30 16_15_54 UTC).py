import os
import sys
import numpy as np
import matplotlib.pyplot as plt
import CustomMatplotlib

# values for n
test_cases = [100, 500, 1000, 1500, 2000, 2500, 5000, 7500, 10000, 20000, 25000, 50000, 75000, 100000]

# arguments for sortdata
pre_sort_types = ['', '-r', '-f']
pre_sort_types_names = ['', 'Absteigend', 'Aufsteigend']

# arguments for sort
sort_types = ["-i", "-q"]
sort_types_names = ['Insertion', 'Quick']

# array for timings
time = np.zeros(shape = (len(test_cases), len(sort_types) * len(pre_sort_types)))

# only bench if no benchmark results are available
if not os.path.exists("time_output.dat"):
	print("No output file found --> perform benchmark")

	# bench dich durch alle Faelle 
	for i in range(len(sort_types)):
		for j in range(len(pre_sort_types)):
			for k in range(len(test_cases)):
				command = "../sortdata/sortdata " + pre_sort_types[j] + " "\
					 + str(test_cases[k]) + " | ./sort -t " + sort_types[i]\
					 + " > time.dat"
				print(command)
				os.system(command)
				# output of sort is piped to file time.dat which contend is
				# read by this scrips in order to obtain the time needed
				with open("time.dat", 'r') as f:
					data = f.readlines()
					t = data[2].split()[2]
					time[k, i * len(pre_sort_types) + j]  = float(t.rstrip('s'))

	# write benchmark result to output file
	with open("time_output.dat", 'w') as f:
		for i in range(time.shape[0]):
			for j in range(time.shape[1]):
				f.write(str(time[i, j]))
				if j != time.shape[1] - 1:
					f.write('	')
				else:
					f.write('\n')

	# remove eventual benchmark files (not needed anymore)
	if os.path.exists("time.dat"):
		os.system("rm time.dat")

	if os.path.exists("piped_input_sorted"):
		os.system("rm piped_input_sorted")

# benchmark results are available --> read that file
else:
	print("Output file found --> read from file")
	with open("time_output.dat", 'r') as f:
		data = f.readlines()
		for i in range(len(data)):
			for j in range(len(data[0].split())):
				time[i, j] = data[i].split()[j]


# plot benchmark results
plt.figure()
for i in range(time.shape[1]):
	plt.plot(test_cases, time[:, i], 'o--', label=pre_sort_types_names[i % len(pre_sort_types)]\
	 + ' ' + sort_types_names[int(i / len(pre_sort_types))])
plt.xlabel("n")
plt.ylabel("Time in s")
plt.grid(True)
plt.legend()
plt.savefig("benchmark.pdf")
plt.show()
