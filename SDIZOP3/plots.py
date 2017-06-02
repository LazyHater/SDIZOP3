import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt

from matplotlib.ticker import NullFormatter
from sets import Set


bp_data = open("bp_tests.csv").readlines()[1:]

rows = [[float(it) for it in line.split(";")] for line in bp_data]

x_axis = list(Set([(row[0]) for row in rows]))
x_axis.sort()

variants = Set([(row[1]) for row in rows])
variants = list(variants)
variants.sort()

styles = ['ro-', 'gs-', 'b^-']


def func(idx):
	i = 0
	for v in variants:
		line_settings = [v]
		line_settings.append(styles[i % len(styles)])
		line_settings.append([(row[idx]) for row in rows if row[1] == v])
		print(line_settings)
		i += 1
		plt.plot(x_axis, line_settings[2], line_settings[1], label ="bp_w: %d" % line_settings[0])
	

plt.subplot(211)
func(2)
plt.title("Backpack problem full check alghoritm")
plt.axis([min(x_axis), max(x_axis)+10, 0, 1200])
plt.ylabel("Time of execution[ms]")
plt.xlabel("Number of items")
plt.grid(True)
plt.legend()

plt.subplot(212)
func(3)
plt.title("Backpack problem greedy aproxymation")
plt.axis([min(x_axis), max(x_axis)+5, 0, 0.01])
plt.ylabel("Time of execution[ms]")
plt.xlabel("Number of items")
plt.grid(True)
plt.legend()

plt.subplots_adjust(top=0.92, bottom=0.08, left=0.10, right=0.95, hspace=0.4,
                    wspace=0.35)
plt.savefig("bp_plot.png")

#tsp plot
tsp_data = open("tsp_tests.csv").readlines()
labels = tsp_data[0]
tsp_data = tsp_data[1:]

rows = [[float(it) for it in line.split(";")] for line in tsp_data]
print (rows)

x_axis = list(Set([(row[0]) for row in rows]))
x_axis.sort()

full_y = [row[1] for row in rows]
greedy_y = [row[2] for row in rows]

max_time = max(full_y)
max_n = max(x_axis) 

def fact(x):
	if x == 0 : return 1
	tmp = 1	
	for i in range(int(x)):
		tmp *= i+1
	return tmp

per_permutation =  float(float(max_time) / float(fact(max_n)))
print ("per perm: %f"%per_permutation)


plt.clf()
plt.cla()


plt.subplot(211)
plt.title("Tsp problem greedy alghoritm")
plt.ylabel("Time of execution[ms]")
plt.xlabel("Number of cities")
plt.grid(True)
plt.plot(x_axis, greedy_y, 'bo-')
plt.gca().yaxis.set_minor_formatter(NullFormatter())

#x_axis.append(50);
#x_axis.append(100);
#x_axis.append(150);
#full_y.append(fact(50)*per_permutation)
#full_y.append(fact(100)*per_permutation)
#full_y.append(fact(150)*per_permutation)

plt.subplot(212)
plt.title("Tsp problem full check alghoritm")
plt.ylabel("Time of execution[ms]")
plt.xlabel("Number of cities")
plt.grid(True)
plt.plot(x_axis, full_y, 'bo-')


plt.savefig("tsp_plot.png")
print (fact(3))
