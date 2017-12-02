#pragma once
#include <iostream>
using namespace std;
class grandFather
{
	int var;
	public:
		grandFather()
		{
			var = 10;
		}
		virtual void Method1()
		{
			cout << "in grandFather::Method1() \r\n";
		}

		
};


class Father : public grandFather
{
	int f1;
	public:
		Father()
		{
			f1 = 101;
		}
		void Method1()
		{
			cout << "in Father::Method1() \r\n";
		}

};

class Son : public Father
{
	int fs;
	public:
		Son()
		{
			fs = 102;
		}
		void Method1()
		{
			cout << "in Son::Method1() \r\n";
		}
};

class testDynamicCasting
{
	public:
		void calltestDynamicCasting()
		{
			grandFather* x = new grandFather();
			Father* y = new Father();
			Son* z = new Son();
			
			grandFather* x1 = dynamic_cast<grandFather*>(z);
			if (x1)
			{
				cout << "Able to cast [Son -> grandFather] \r\n";
			}
			else
			{
				cout << "Unable to cast [Son -> grandFather] \r\n";
			}



			Son* z1 = dynamic_cast<Son*>(x);
			if (z1)
			{
				cout << "Able to cast [grandFather -> Son] \r\n";
			}
			else
			{
				cout << "Unable to cast [grandFather -> Son] \r\n";
			}
		}
};