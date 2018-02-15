#ifndef _RefConstTest
#define _RefConstTest
#include "stdafx.h"
#include <iostream>
using namespace std;
class RefConstTest
{
	public:
		RefConstTest()
		{

		}
			
		/*
			Reference
				- For both "int&" and "int &const" L-Value and R-Value can be altered.
				- For "const int&"  both L & R values are non-mutable.
				- When ever the R-Value of reference is changed, original-variable's value also changes.
		*/
		void callRefConstTest1()
		{
			int v1 = 10;
			int v2 = 75;

			//////For REFERENCE both L-value and R-value can be altered
			int& r1 = v1; //Reference has to be initialized with L-value
			r1 = 90; //R-value can be changed. And this changes original-value
			cout << " v1 has changed " << v1 << "\r\n";
			v1 = 100;
			cout << " r1 has changed " << r1 << "\r\n";
			r1 = v2; //L-Value can be changed
			/////////////////////////////////////////////

			//////For const-REFERENCE both L-value and R-value are non-mutable
			const int& r2 = 123; //Const Reference can be initialized with CONST
			//r2 = 90; //R-Value can not be changed
			//r2 = v2; //L-Value can not be changed
			

			/////For REFERENCE-Const both R & L value can be changed
			int &const r3 = v1;
			r3 = 80; //R-value can be changed. And this changes original-value
			cout << " v1 has changed " << v1 << "\r\n";
			r3 = v2; //L-Value can be changed
		}

		void callRefConstTest2()
		{
			int v1 = 10;
			int v2 = 75;

			//////For POINTER both L-value and R-value can be altered
			int* r1 = &v1; //Reference has to be initialized with L-value
			*r1 = 90; //R-value can be changed. And this changes original-value
			cout << " v1 has changed " << v1 << "\r\n";
			r1 = &v2; //L-Value can be changed
			/////////////////////////////////////////////

			//////For const-POINTER R-value can not be changed, but L-value can be changed.
			const int* r2; //Const Reference can be initialized with CONST
			r2 = &v2; //L-Value can be changed
   		   //*r2 = 90; //R-Value can not be changed
			v2 = 800;


			/////For POINTER-Const R-value can be changed and L-value can not be changed
			int *const r3 = &v1;
			*r3 = 80; //R-value can be changed. And this changes original-value
			cout << " v1 has changed " << v1 << "\r\n";
			//r3 = v2; //L-Value can not be changed
		}

};


#endif