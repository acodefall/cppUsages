#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
using namespace std;
#include<iostream>
#include<algorithm>
#include<queue>
#include <string>
namespace ArrayToPointersNM
{
	/*
			Arry-To-Pointer
			Array declaration and poiner declaration are different. 
			Where is pointer is a blob of address that does not aware of dimension, where as Array knows it dimension..
			In fact compiler allocates a single block of memory for Array.
			Array has two important addresses 'address-of-first-element' and 'address-of-Array-block'.
			You can think of this as pointer to 1st element of an object; and pointer to the object itself.
			'address-of-Array-block' is like address to object.
			'address-of-Array-block' will know about Sizeof() but not 'address-of-first-element', so SIZEOF() does not return proper value
			when called on 'address-of-first-element'.
			
			When Array is assigned to a Pointer, compilers assigns address-of-first-element to Pointer, and the resulting pointer will loose size information.
			This loss of information is termed as "decay of Array in Pointer". 
			
			To get to the adsress-of-array-block, simply do "char (*abc)[row-count]".
			

			char src[5];  //array that knows size
			
			ptrToFirstElement(src);
			ptrToFirstElement(char* p) //p has 'address-to-first-element-of-Array'. pointer will not respond to SizeOf()
			{
			
			}
		
			ptrToArrayBlock(char (p*)[5] ) //p has 'address-to-Array-block'.  pointer will not respond to SizeOf()
			{
			
			}
		
			Another difference is we can assign any random address to POINTER but not ARRAY.
			
			char src[5];  //array that knows size
			src = 0x5666; //ERROR assigning address will not work

			char* p= 0x435235;
			p= 0x555535;

			When calling a function Array can be passed When calling a function we can pass either addre

		
	*/
	class ArrayToPointers
	{
	public:
		void Test()
		{
			int Src[3][3] =
			{
				{ 1,2,3 },
				{ 4,5,6 },
				{ 7,8,9 }
			};
			test1(Src);
			test2(Src);
			ptrToFirstElement((int*)Src);
			//ptrToArrayBlock(Src);
		}

	

		
		void ptrToFirstElement(int* p) //p has 'address-to-first-element-of-Array'. pointer will not respond to SizeOf()
		{
			cout << endl << "ptr To First Element" << sizeof(p) << endl;
		}

		void ptrToArrayBlock(int (*p)[][3]) //p has 'address-to-Array-block'.  pointer will not respond to SizeOf()
		{
			cout << endl << "ptr To Array Block" << sizeof(p) << endl;
		}

		void test1(int src[3][3])
		{
			cout << endl;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					cout << src[i][j] << " ";
				}
				cout << endl;
			}
		}

		void test2(int src[][3])
		{
			cout << endl;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					cout << src[i][j] << " ";
				}
				cout << endl;
			}
		}
	};
};