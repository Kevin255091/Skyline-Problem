# Solving the skyline problem

My C code for solving the skyline problem using the max heap data structure. 

I also wrote two Python scripts to show the buildings and the skyline.

## Using the code

### Prerequisites

You need to have gcc or other C compiler installed on your computer.

You need to have Python and Python package "matplotlib" installed on your computer in order to run the Python scripts.

### Compiling the code

Use the command prompt and go to the directory where the files "skyline.c", "MaxHeap.c" and "MaxHeap.h" are.
Type the following command :

```
gcc skyline.c MaxHeap.c -o skyline
```
### Running the test

There is a test file 'Input.txt' containing the data about the buildings' positions and heights.
For more details, please google "UVA online judge skyline problem" and check the problem specification.
To run the test, type the following command.

For Windows system, type
```
skyline < Input.txt
```

For Unix-like system, type
```
./skyline < Input.txt
```

The output result should be identical to the content in the file "Output.txt".

The following is the command to run the Python scripts.

To show the building lines, type

```
python show_buildings.py Input.txt
```

To show the skyline, type

```
python show_skyline.py Output.txt
```

If the scripts can not work properly, you can delete the following two lines of code in both of the scripts:
```
mng = plt.get_current_fig_manager()
mng.window.state('zoomed')
```
