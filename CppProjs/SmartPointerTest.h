#pragma once
#include<iostream>
#include<stdio.h>
#include<string>
#include<list>
#include<map>
#include<queue>
#include<string>
#include<memory>
using namespace std;


class smartTest
{
	public:
		void uniqueTest()
		{
			//Test1
			//Following code will give compilation error	
			unique_ptr<string> s1(new string("my test"));
			unique_ptr<string> s2;
			//s2 = s1; Gives compilation error 
			s2 = move(s1);

			//Test2
			auto_ptr<string> a1(new string("my test"));
			auto_ptr<string> a2;
			a1 = a2; //results in bad. Both DTOR frreing same object
			a1.release();

			//Test3.
			//function can return unique_ptr by value.
			unique_ptr<string> c1 = returnUniquePointer();
			cout << c1->c_str();

			//Test4
			//function can NOT return unique_ptr by ref because it PTR will loose its uniqueness
			//unique_ptr<string> c2 = returnUniquePointerRef();
			//cout << c1->c_str();


		}

		unique_ptr<string> returnUniquePointer()
		{
			unique_ptr<string> s1(new string("mytest"));

			return s1;
		}


		unique_ptr<string>& returnUniquePointerRef()
		{

			unique_ptr<string> s1(new string("mytest"));

			return s1;
		}

		unique_ptr<string>& returnUniquePointerTest()
		{
			string s2("test");
			unique_ptr<string> s1(&s2);

			return s1;
		}


	
};