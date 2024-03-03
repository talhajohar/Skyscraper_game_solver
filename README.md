# Skyscraper_game_solver

This program is created in C language to solve the Skyscraper problem. 
For information about Skyscraper please check this https://www.conceptispuzzles.com/de/index.aspx?uri=puzzle/skyscrapers
The input to this program is given as the visible buildings in the order of top view, bottom view, left view and right view respectively.
Each view is separated by spaces.
In case of false input, more than one input or deviation from the given pattern (space missing) "Error" is printed on the standard output.
In case of more than one possible solution, the first solution that appears would be displayed.
This same program can be used to solve till skyscrapers of size 7x7 in few seconds. 
Although the algorithm should be able to solve for 8x8 und 9x9 however the computing power required increases manifold. 

Example:

The following input is given to the program:
./a.out "5 1 5 2 4 3 2 1 2 2 2 2 3 5 2 7 4 3 3 2 1 4 1 2 2 2 3 6"

Output:
2 7 1 6 3 5 4 
1 2 3 4 5 6 7
3 4 5 7 1 2 6
5 1 4 3 6 7 2
4 3 6 2 7 1 5
6 5 7 1 2 4 3
7 6 2 5 4 3 1

To explain the views the above example is further illustrated below:

		 5 1 5 2 4 3 2 	
		 _____________
	2	|2 7 1 6 3 5 4|		4
	7	|1 2 3 4 5 6 7|		1
	4	|3 4 5 7 1 2 6|		2
	3	|5 1 4 3 6 7 2|		2
	3	|4 3 6 2 7 1 5|		2
	2	|6 5 7 1 2 4 3|		3	
	1	|7 6 2 5 4 3 1|		6
		 -------------
		 1 2 2 2 2 3 5