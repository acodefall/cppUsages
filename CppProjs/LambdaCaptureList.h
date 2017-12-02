#pragma once
#include <list>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
namespace CaptureListOfLambdaNM
{
	class Person
	{
		public:
			std::string name;
			int		age;


			Person(const char* n, int a)
			{
				name = n;
				age = a;
			}
		};

	
	class TestCaptureListOfLambda
	{
		public:
			void callCaptureListOfLambda()
			{
				std::list<Person*> lst;
				lst.push_back(new Person("A1", 12));
				lst.push_back(new Person("A67", 89));
				lst.push_back(new Person("Z7", 87));
				lst.push_back(new Person("C01", 982));
				lst.push_back(new Person("U17", 489));
				lst.push_back(new Person("D80", 712));

		

				LambdaWithNOCaptureCapture(lst, 87);

				LambdaONEVariableCapture(lst, 87);
				LambdaALLRefCapture(lst, 87);

				LambdaALLValueCapture(lst, 87);

			}


		
			//[ capture-list ] ( params ) -> ret { body }
			//[ capture-list ] = [] "means Lamba will not capture anything from local scope"
			void LambdaWithNOCaptureCapture(std::list<Person*> lst, int age1)
			{
				std::list<Person*>::iterator x = find_if(
					lst.begin(),
					lst.end(),
					[](Person* prs) -> bool
					{
						///if (prs->age == age1) THIS will give error because we are not capturing 'age1'
						if (prs->age == 90)
						{
							return true;
						}
						return false;
					}
				);

				if (x == lst.end())
					cout << "not found \r\n";
				else
					cout << (*x)->name << " " << (*x)->age << endl;
			}


			//[ capture-list ] ( params ) -> ret { body }
			//[ capture-list ] = [age1] "means Lamba will capture R-VALUE of only 'age1'. Lambda can read age1 but not modify it"
			void LambdaONEVariableCapture(std::list<Person*> lst, int age1)
			{
					std::list<Person*>::iterator x = find_if(
					lst.begin(),
					lst.end(),
					[age1](Person* prs) -> bool
					{
						if (prs->age == age1)
						{
							return true;
						}
						return false;
					}
				);

				if (x == lst.end())
					cout << "not found \r\n";
				else
					cout << (*x)->name << " " << (*x)->age << endl;
			}

			//[ capture-list ] = [&] "means Lamba will capture L-VALUE of every variable available in local-scope, so Lamba can modify the age1, and change will get reflected outside of Lambda"
			void LambdaALLRefCapture(std::list<Person*> lst, int age1)
			{
				std::list<Person*>::iterator x = find_if(
					lst.begin(),
					lst.end(),
					[&](Person* prs) -> bool
						{
							if (prs->age == age1)
							{
								age1 *= 3; 
								return true;
							}
							return false;
						}
				);


				if (x == lst.end())
					cout << "not found \r\n";
				else
				{
					cout << (*x)->name << " " << (*x)->age << endl;
					cout << "\r\nvalue of age1 " << " " << age1 << endl; //Age1 will be TRIPLED.
				}
			}

			//[ capture-list ] = [=] "means Lamba will capture R-VALUE of every variable available in local-scope, so Lambda can not modify the variables. In fact compiler will not let you modify it."
			void LambdaALLValueCapture(std::list<Person*> lst, int age1)
			{

				//[ capture-list ] ( params ) -> ret { body }
	
				std::list<Person*>::iterator x = find_if(
					lst.begin(),
					lst.end(),
					[=](Person* prs) -> bool
						{
							if (prs->age == age1)
							{
								//age1 *= 3; //age1 can not be modified because LVALUE of age1 is not made available to Lambda
								return true;
							}
							return false;
						}
					);


				if (x == lst.end())
					cout << "not found \r\n";
				else
				{
					cout << (*x)->name << " " << (*x)->age << endl;
				}
			}
	};
};