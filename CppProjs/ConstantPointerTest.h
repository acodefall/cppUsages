#include "stdafx.h"
#include <iostream>
#include <thread>
#include <memory>  
using namespace std;


/*
	Readonly String pointer in C
	In C we can create a string in 3 ways.
	-Assign string-data to char* directly. Compiler creates a read-only pointer and also puts EOS at the end,
	 so we can print as string. We can access the elements, using index-operator, and write to it, but it will crash during run time.
	 char* f = "hhhh"
	 char* f1;
	  f1 = "tttt";
	 
	-Second method declares "char[]" without specifying SIZE, and declaration will initialize the each element with a character.
	 Compiler will not add EOS so print will print junk characters. But we can modify the element using index-operator.
	 
		void callPtrTest2()
		{
			char ch3[] = { 'd', 'f', 'k', 'L' };
			char ch2[] = { 'd', 'f', 'k', 'L','\0' };
			ch2[2] = 'h'; //This will NOT crash when running
			cout << ch3; //This will print junk at the end because there is no EOS
			cout << ch2; //This prints correctly because there is EOS
		}
 
*/
class PtrTest1
{

	public:

		void callPtrTest1()
		{
			char* ch = "rrrr";
			ch[2] = 'h'; //This will crash when running
			cout << ch;

		

		}


		void callPtrTest2()
		{
			char ch3[] = { 'd', 'f', 'k', 'L' };
			char ch2[] = { 'd', 'f', 'k', 'L','\0' };
			ch2[2] = 'h'; //This will NOT crash when running
			cout << ch3; //This will print junk at the end because there is no EOS
			cout << ch2; //This prints correctly because there is EOS
		}


		void callPtrTest3()
		{
			int a[5] = { 1, 2, 3, 4, 5 };
			int *ptr = (int*)(&a + 1);
			int *ptr4 = (int*)(&a);
			printf("%d %d\n", *(a + 1), *(ptr));
			printf("%d %d\n", *(a + 1), *(ptr - 1));

			int *ptr2 = (int*)(&a);
			printf("%d %d\n", *(a + 1), *(ptr2));
			printf("%d %d\n", *(a + 1), *(ptr2 - 1));

			return ;
		}

		//When const-pointer is declared make sure that declaration inistializes it to L-Value. Instead of L-Value if we assign number(say 6) then we get compilation error.
		//This is a Trick interview question
		void callPtrTest4()
		{
			//int const * p = 5;
			//printf("%d", ++(*p));

			return;
		}

		void printfX(int a1, int a2, int a3, int a4, int a5)
		{
			printf("%d%d%d%d%d", a1, a2, a3, a4, a5);
		}

		/*
			Post_fix and Pre_Fix operator output
				Assume a printf() function that takes pre-fix and post-fix parameters. It is easy to guess the out come of post-fix but not pre-fix. This is because Pre-Fix operator returns Lvalue, and Post-Fix returns R-value.

				Think about overloading Prefix and PostFix operators for our self in some objec.	 The pre-fix function modifies the current object and returns it to caller. Probably that is why it returns L-value.	Where as post-fix function creates a TEMP copy of the current object and returns it to caller, and actual data increment happens in THIS object, which is not returned.

				Analysing passing of parameter to a function
					Enable the DisAssemly in Project settings and then follow the PUSH instruction show in dis-assembled code. Order of PUSH instruction will be show the order in which parameters are being passed. First PUSH instruction points to Right-Most parameter, and it moves R to L.
					So if you are analysing the output of Print(), start from RIGHT-most parameter.

		*/
		void callPtrTest5()
		{
				
				int i = 5;
			

				printfX(i++, i--, ++i, --i, i);
				i = 5;

				//44
				printf("\r\n%d%d", --i, i);

				i = 5;
				//Push order  5 5 5 5 4
				//Print order 4 5 5 5 5
				printf("\r\n%d%d%d%d%d", i++, i--, ++i, --i, i);
			
		}
};