# 22s-pa01-cheez-its
by Maggie Asare

2/14/2022
## Description
The goal of this project is to utilize different sorting algorithms in an art gallery scenario.
Specifically, you are trying to help art galleries  increase revenue. 
You plan to do this by optimizing how the art galleries put their art pieces on the wall. 
The specifications are as follows:
- The art pieces are only placed along a single horizontal line (1 dimension).
- Art pieces cannot be rotated
- When an art piece sells, the empty space will not be filled until the wall is reset.
- The program is only organizing 1 wall.
- Every art piece is *guaranteed* to fit on the wall.

The goal of the project is to find the most efficient ordering of the art pieces on the wall that will yield the highest profit if all the pieces are sold.

## How to Build
Use the `cd` command in the command to navigate into the folder that the project in.

Once in the folder use the following command to compile:

`g++ fileio.cpp sorts.cpp art.cpp main.cpp -o main.out`

### Command Line
The program will accept a single command line argument representing the name of the input file.

## How to Run
1. Open the commandline (windows) or terminal (mac)
2. Enter the following command `./main.out`

### I/O FIle Formatting
#### Input File:
The first line will contain length and height as integers separated by a space.
The second line contains a single integer representing then total number or art pieces.
Following this there is one line for each art piece containing picture ID, value of the picture, width of the picture,
and height of the picture seperated by spaces.

The max width and height of the wall is 1,000,000 units.
The max width and height of the image is 1,000,000 units.
The maximum number of images to choose from is 100,000.

**An example input file:**
````
    1034 768
    4
    12 400 1023 768
    7 250 300 150
    22 200 750 650
    3 150 200 250
  ````
#### Output File:
The output will have 3 text files, one for each algorithm.
The names of the output files will be the name of the input file appended by the following:
"-bruteforce", "-highvalue", "-custom".

In each output file, the first line contains a single integer representing the combined value 
of the pieces put on the wall for that algorithm. Each subsequent line consists of four integers separated by a space:
picture id, value of that picture, width of that picture, and height of that picture.

## Algorithms
This project implements three algorithms:

A **brute force** algorithm that finds all possible solutions and puts keeps the best one.
This algorithm recursively finds every solution.
As it is forming the lists, it keeps track of the highest it has found so far and how many paintings are currently on the wall.
When a new max price is reached that fits on the wall, it saves that list of paintings.

A **highest values first** that puts the most expensive painting, then the next expensive painting, etc.
This algorithm does not consider width of the paintings when determining which is best value except for to make sure it fits on the wall.

A **custom** algorithm based on the classic [knapsack problem](https://en.wikipedia.org/wiki/Knapsack_problem).
Thw algorithm ranks the art pieces by price per inch (width of the paintings), and places them onto the wall in order of highest price per inch.
If it reaches one that doesn't fit, it looks for the next highest one that does fit until it has expended the whole list.



## Analysis
To determine the efficiency of each algorithm, I used the chronos library to time how each algorithm performed on different data set sizes.
The results were graphed on a runtime versus dataset size graph featured below. 
Additionally, I kept track of the total value put on the wall for each case for a total value put on the wall versus runtime graph shown below.
Regressions were done on each graph to determine a model for each algorithm.

### Run Time Analysis
The Brute Force Algorithm was consistently considerably slower than the other two as shown in Figure 1 below.
Because of how slow it was, the biggest data set size I tried on it successfully was 15 art pieces.

**Figure 1: Run Time For All Algorithms Graph**
![Graph of Run Time for All Algorithms](/media/RunTimeAllGraph.png "RunTimeAllGraph.png")

The raw data of all the runtimes is shown below in Figure 2. 
As you can see, the brute force algorithm can be almost 1500 times slower than the other two algorithms.
This is because the brute force algorithm iterates through every possible subset of the set of all paintings.
For a set of size n there are 2^n subsets including the null set.
My Brute Force Algorithm excludes the null set, so it iterates through (2^n)-1 subsets in order to find the best one.
On the other hand, the other 2 algorithms run around the same speed as one another. 
We will investigate the other two algorithms in further detail in Figures 3 and 4.

**Figure 2: Run Time For All Algorithms Table**
![Table of Run Time for All Algorithms](/media/RunTimeAllTable.png "RunTimeAllTable.png")

The High Value and Custom Algorithms are based off quick sort which has time complexity of Θ (n log (n)) and O (n^2).
The only difference between the sorting section of the algorithms is that the High Value Algorithm compares prices and the Custom compares price per inch.
Calculating the price per inch (ppi) does not add to the algorithm itself because the ppi is a member variable of the art class
that is calculated during the art class constructor. As a result, the High Value and Custom algorithms are generally around the same speed.
Differences in speed comes from the original ordering of the data set and whether it is in favor of price or price per inch.
The run time for the High Value and Custom Algorithms are graphed below in Figure 3.

**Figure 3: Run Time for High Value and Custom Algorithms Graph**
![Table of Run Time for High Value And Custom Algorithms](/media/RunTimeSub1Graph.png "RunTimeSub1Graph.png")

To better understand how close the values were for the two algorithms, we can examine Figure 4 below.
It has the same values as Figure 3, but excludes the Brute Force Algorithm.

**Figure 4: Run Time for High Value and Custom Algorithms Table**
![Table of Run Time for High Value and Custom Algorithms](/media/RunTimeSub1Table.png "RunTimeSub1Table.png")

### Total Value On The Wall Analysis

In regards to accuracy, obviously the Brute Force was the most accurate since it produced the optimal value every time.
In the size 15 data sets, the High Value algorithm got the same values as the Brute Force.
This is mostly due to chance though as in previous testing on the example data set, 
the Custom Algorithm matched the Brute Force Algorithm, but the High Value Algorithm did not.
The results for all Algorithms can be viewed below in Figure 5.

**Figure 5: Total Value for all Algorithms Graph**
![Graph of Total Value for All Algorithms](/media/TotalValueAllGraph.png "TotalValueAllGraph.png")

In the graph, many of the points overlap because they are the same, so we can view the results in further detail through
the table in Figure 6.

**Figure 6: Total Value for All Algorithms Table**
![Table of Total Value for All Algorithms](/media/TotalValueAllTable.png "TotalValueAllTable.png")

As seen in Figure 7 below, the Custom Algorithm and High Value Data set generally performed similarly with the Custom
Algorithm trending slightly higher.
This is because the Custom Algorithm optimizes for both price and width, while highest value only optimizes price.

**Figure 7: Total Value for High Value and Custom Algorithms Graph**
![Graph of Total Value for High Value and Custom Algorithms](/media/TotalValueSub1Graph.png "TotalValueSub1Graph.png")

If we compare individual trials, the Custom Algorithm almost always outperformed the High Value Algorithm.
This can be observed through the table in Figure 8.

**Figure 8: Total Value for High Value and Custom Algorithms Table**
![Table of Total Value for High Value and Custom Algorithms](/media/TotalValueSub1Table.png "TotalValueSub1Table.png")

## Discussion

If we account for performance in accuracy *and* run time, the Custom Algorith is best.
it often produces the same accuracy as the Brute Force Algorithm and ususally has higher accuracy than the High Value
Algorithm.
It is also faster than the Brute Force Algorithm and runs at the same speed as the High Value Algorithm.

Now to discuss error and places my experiment could improve... Although I did run these all on the same computer 
(Intel Core i7 with 16 GB of RAM and 64-Bit OS), the fans on my computer are a little messed up and it does not always cool properly.
As a result I am thinking the longer I was running tests and the more things I had open on my computer during each test could have
affected run times, but not total value on the wall. Overall, I think any error would be minute and not affect the overall
trends seen throughout the experiment. I would improve this by testing even more data sets and also making some data sets with
specific orders. In this experiment, all the data sets were random. 
With specific ordering, I could better test the worst case for the High Value and Custom algorithms.