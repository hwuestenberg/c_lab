import os
import sys
import numpy as np
import matplotlib.pyplot as plt
import CustomMatplotlib
import random

# values for n
test_cases = [100, 500, 1000, 1500, 2000, 2500, 5000, 7500, 10000, 20000, 25000, 50000, 75000, 100000]

# arguments for contains
search_types = ["-l", "-b"]
search_types_names = ['linear search', 'binary search']

# array for timings
time = np.zeros(shape = (len(test_cases), len(search_types)))

sortdata_dir = '../../Assignment_1/sortdata'
sort_dir = '../../Assignment_1/Sort'
output_dir = '../../Assignment_2/contains/testcases'

if not os.path.isdir('testcases'):
	os.makedirs('testcases')

for i in range(len(test_cases)):
	if not os.path.exists('testcases/testvalues_' + str(test_cases[i]) + '_sorted'):
		# create test cases
		command = sortdata_dir + '/sortdata ' + str(test_cases[i]) + ' '\
			 + output_dir + '/testvalues_' + str(test_cases[i])
		os.system(command)
		
		# sort test cases
		command = sort_dir + '/sort -i ' + output_dir + '/testvalues_'\
			 + str(test_cases[i])
		os.system(command)

		# remove test file as it is no longer needed
		os.remove('testcases/testvalues_' + str(test_cases[i]))

	# create value to search for
	if not os.path.exists('testcases/search_for_' + str(test_cases[i])):
		with open('testcases/testvalues_' + str(test_cases[i]) + '_sorted', 'r') as f:
			number_of_values = int(f.readline())
			index_to_search_for = number_of_values - 1;#random.choice(range(number_of_values))
			data = f.readlines()
			target = data[index_to_search_for]
		with open('testcases/search_for_' + str(test_cases[i]), 'w') as f:
			f.write('1\n')
			f.write(str(target) + '\n')			
	
# only bench if no benchmark results are available
if not os.path.exists("time_output.dat"):
	print("No output file found --> perform benchmark")

	# bench dich durch alle Faelle 
	for i in range(len(search_types)):
		for k in range(len(test_cases)):
			command = "./contains -t " + search_types[i]\
			 + ' testcases/search_for_' + str(test_cases[k])\
			 + ' ' + "testcases/testvalues_" + str(test_cases[k]) + '_sorted'\
			 + " > time.dat"
			print(command)
			os.system(command)
			# output of contains is piped to file time.dat which contend is
			# read by this scrips in order to obtain the time needed
			with open("time.dat", 'r') as f:
				data = f.readlines()
				t = data[2].split()[2]
				time[k, i]  = float(t.rstrip('s'))

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
	plt.semilogy(test_cases, time[:, i], 'o--', label= search_types_names[i])
plt.title("Searching for last element in sorted list of numbers")
plt.xlabel("n")
plt.ylabel("Time in s")
plt.grid(True)
plt.legend()
plt.savefig("benchmark.pdf")
plt.show()
