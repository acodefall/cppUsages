#ifndef _FriendTest
#define _FriendTest
#include "stdafx.h"
#include <iostream>
using namespace std;

/*
	Friend function
		-Friend function accepts reference to host-class as parameter. Body of Friend function will access the 
		 private members of class. And ability to do this is given by FRIEND keyword.
	
	
		-Friend function is declared inside the class and Implementation sits in global scope, outside the class.
		So friend function is not in any way a class-member. Caller will access the friend function, as if it is a 
		global function.
	 
		-Caller will instantiate the class, and calls the global-friend-function by passing class-instance as parameter.   
	
		-Friend declaration can sit anywhere and access control keywords have no effect.
	
		-Friend function will be able to access private and protected members. 

		-Implementation will not have FRIEND keyword, declaration will have FRIEND keyword.
	
		-Friend function(fun()) implementation can also be a public member of a DIFFERENT class;
		 When declaring the Friend, the grating class should qulify the function-name with the class-name.
		 Note the friend implementation should be PUBLIC.

*/


//Friend sample where the friend-function is in Global scope
class frndInGlobalScope
{
	
	int mem;

	
	friend void exposed(frndInGlobalScope& f);

	public:
		frndInGlobalScope(int d)
		{
			mem = d;
		}
		
};

void exposed(frndInGlobalScope& f)
{
	cout << "Friend function in global scope " << f.mem;
}



//Friend sample where the friend-function is member of another class
/*
	Friend function(fun()) implementation can also be a public member of a DIFFERENT class;
	When declaring the Friend, the grating class should qulify the function-name with the class-name.
	Note the friend implementation should be PUBLIC.
*/
class foriegnClass1;
class friendGranter;

class foriegnClass1
{
	public:
		void Member1(friendGranter& f1);
};

class friendGranter
{
	int x;

	public:
		friendGranter(int d)
		{
			x = d;
		}
		friend void foriegnClass1::Member1(friendGranter& f);
};


void foriegnClass1::Member1(friendGranter& f1)
{
	cout << "Friend function implemented in another class" << f1.x;
}


class FriendTest
{
	public:
		void callFriendTest()
		{
			frndInGlobalScope xd(89);
			exposed(xd);
		}
		void callFriendTest2()
		{
			foriegnClass1 forgn;
			friendGranter objfriendGranter(67);;
			forgn.Member1(objfriendGranter);
		}
};
#endif