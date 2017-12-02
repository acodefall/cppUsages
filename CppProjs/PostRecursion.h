#pragma once
#include <iostream>
#include <sstream>
using namespace std;
namespace CountPathsFromTopCornerToBottomMatrixNM
{
	/*
		Why some recursion calls RETURN directly?
		If no work is being done at post-recursion stage, then caller ATTACHes RETURN to Recursion call.
		Otherwise caller collects the return value of Recursion function, processes the return values and then returns it to caller.
		int countPathsRecursion(int r, int c, int MaxRows, int MaxCols)
		{
			if ((r == MaxRows - 1) && (c == MaxCols - 1))
				return 1;


			if (r == MaxRows - 1)
			{	//No work is being done at post recursion stage
				return countPathsRecursion(r, c + 1, MaxRows, MaxCols);
			}
			else
			{
				//Work is being done at post recursion stage
				int bottom = countPathsRecursion(r + 1, c, MaxRows, MaxCols);  //accounts for BOTTOM
				int right = countPathsRecursion(r, c + 1, MaxRows, MaxCols); //accounts for RIGHT
				int diagonal = countPathsRecursion(r + 1, c + 1, MaxRows, MaxCols); //accounts for diagonal 

				return bottom + right + diagonal;
			}
		}
	*/

	const int MAXRow = 3;
	const int MAXCol = 3;
	class CountPathsFromTopCornerToBottomMatrix
	{
	public:

		int countPathsRecursion(int r, int c, int MaxRows, int MaxCols)
		{
			//right-bottom corner cell so exit with 1
			if ((r == MaxRows - 1) && (c == MaxCols - 1))
				return 1;


			//Take care of bottom-row and right-column
			if (r == MaxRows - 1)
			{
				//we can only in left direction
				return countPathsRecursion(r, c + 1, MaxRows, MaxCols);
			}
			else if (c == MaxCols - 1)
			{
				//we can only go down 
				return countPathsRecursion(r + 1, c, MaxRows, MaxCols);
			}
			else
			{	//from each cell we can go in 3 direction
				int bottom = countPathsRecursion(r + 1, c, MaxRows, MaxCols);  //accounts for BOTTOM
				int right = countPathsRecursion(r, c + 1, MaxRows, MaxCols); //accounts for RIGHT
				int diagonal = countPathsRecursion(r + 1, c + 1, MaxRows, MaxCols); //accounts for diagonal 

				return bottom + right + diagonal;
			}
		}





		void CallCountPathsFromTopCornerToBottomMatrix()
		{

			int count = countPathsRecursion(0, 0, MAXRow, MAXCol); //13
			cout << endl << "total number of path using Recursion " << count << endl;
			/* Solution matrix
			1 1 1
			1 3 5
			1 5 13
			*/

		}
	};
};