import os
from matplotlib import pyplot as plt
import sys

class Building():
    def __init__(self, x1, height, x2):
        self.x1 = x1
        self.height = height
        self.x2 = x2

if len(sys.argv) != 2:
	print ('Usage : python show_buildings.py <input_file>')
	sys.exit(0)

os.chdir(os.getcwd())

filename = sys.argv[1]

building_list = []
with open(filename) as f:
    line = f.readline()
    x1, height, x2 = (int(x) for x in line.split())
    building_list.append(Building(x1, height, x2))
    min_x = x1
    max_height = height
    max_x = x2
    while True:
        line = f.readline()
        if line == '':
            break
        x1, height, x2 = (int(x) for x in line.split())
        building_list.append(Building(x1, height, x2))
        if x1 < min_x:
            min_x = x1
        if x2 > max_x:
            max_x = x2
        if height > max_height:
            max_height = height

plt.hlines(0, min_x-1, max_x+1)  # Draw a horizontal line
plt.xlim(min_x-1, max_x+1)
plt.ylim(0, max_height+1)

for building in building_list:
    plt.vlines(building.x1, 0, building.height)
    plt.hlines(building.height, building.x1, building.x2)
    plt.vlines(building.x2, 0, building.height)

plt.axis('on')

mng = plt.get_current_fig_manager()
mng.window.state('zoomed')

plt.show()
