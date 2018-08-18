import os
from matplotlib import pyplot as plt
import sys

class SkylinePoint():
    def __init__(self, x, y):
        self.x = x
        self.y = y

if len(sys.argv) != 2:
	print ('Usage : python show_skyline.py <input_file>')
	sys.exit(0)

os.chdir(os.getcwd())

filename = sys.argv[1]

with open(filename) as f:
    numbers = [int(x) for x in f.readline().split()]
    skyline_point_list = []
    i = 0
    while i < len(numbers):
        skyline_point_list.append( SkylinePoint(numbers[i], numbers[i+1]) )
        i += 2

min_x = skyline_point_list[0].x
max_x = skyline_point_list[-1].x
max_height = skyline_point_list[0].y
for i in range(1, len(skyline_point_list)):
    if skyline_point_list[i].y > max_height:
        max_height = skyline_point_list[i].y

plt.hlines(0, min_x-1, max_x+1)  # Draw a horizontal line
plt.xlim(min_x-1, max_x+1)
plt.ylim(0, max_height+1)

current_height = 0
current_x = min_x-1
for skyline_point in skyline_point_list:
    x = skyline_point.x
    y = skyline_point.y
    plt.hlines(current_height, current_x, x)
    current_x = x
    plt.vlines(current_x, current_height, y)
    current_height = y

plt.axis('on')

mng = plt.get_current_fig_manager()
mng.window.state('zoomed')

plt.show()
