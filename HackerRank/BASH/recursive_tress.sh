#Creating a Fractal Tree from Y-shaped branches
#This challenge involves the construction of trees, in the form of ASCII Art.
#
#We have to deal with real world constraints, so we cannot keep repeating the pattern infinitely. So, we will provide you a number of iterations, and you need to generate the ASCII version of the Fractal Tree for only those many iterations (or, levels of recursion). A few samples are provided below.
#
#Iteration #1 
#In the beginning, we simply create a Y. There are 63 rows and 100 columns in the grid below. The triangle is composed of underscores and ones as shown below. The vertical segment and the slanting segments are both 16 characters in length.

#Iteration #2
#At the top of the left and right branches of the first Y, we now add a pair of Y-shapes, which are half the size of the original Y.

#Input Format 
#A single integer, N.
#
#Constraints 
#N <= 5
#
#Output Format 
#The Nth iteration of the Fractal Tree, as shown above. It should be a matrix of 63 rows and 100 columns. (i.e. 6300 printable characters) It should be composed entirely of underscores and ones, in a manner similar to the examples provided. Do not include any extra leading or trailing spaces.
#
