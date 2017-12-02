#pragma once
#include <iostream>
#include <queue>
#include <string>
#include <memory>

using namespace std;
namespace PriorityQueueUsageNM
{
	
	class Person
	{
		public:
			Person(string n, int a)
			{
				Age = a;
				Name = n;
			}
			int Age;
			string Name;
	};

	struct  compr
	{
		//MIN
		bool operator()(shared_ptr<Person> x, shared_ptr<Person> y)
		{
			if (x.get()->Age > y.get()->Age)
			{
				return true;
			}
			else
				return false;
		}
	};

	struct comprLess
	{
		public:
			bool operator() (int p1, int p2)
			{
				if (p1 < p2)
					return false;
				else
					return true;
			}
	};

	struct comprMore
	{
		public:
			bool operator() (int p1, int p2)
			{
				if (p1 < p2)
					return true;
				else
					return false;
			}
	};

	class PriorityQueueUsage
	{
		public:
				void callPriorityQueueUsage()
				{
					vector<int> vt;
					vt.reserve(60);

					compr c1;
					//MIN 
					priority_queue<shared_ptr<Person>, vector<shared_ptr<Person>>, compr> pqMax(c1);
					pqMax.push(make_shared<Person>("A1", 1));
					pqMax.push(make_shared<Person>("A1000", 1000));
					pqMax.push(make_shared<Person>("A900", 900));
					pqMax.push(make_shared<Person>("A400", 400));
					pqMax.push(make_shared<Person>("A30", 30));
					pqMax.push(make_shared<Person>("A90", 90));
					pqMax.push(make_shared<Person>("A100", 100));
					pqMax.push(make_shared<Person>("A300", 300));
					pqMax.push(make_shared<Person>("A500", 500));
					pqMax.push(make_shared<Person>("A200", 200));
					pqMax.push(make_shared<Person>("A700", 700));
					pqMax.push(make_shared<Person>("A800", 800));

					cout << "\r\nQueue content";
					//Pop one by one
					int i = 0;
					while (pqMax.empty() == false)
					{
						shared_ptr<Person> v = pqMax.top();
						cout << v.get()->Age << "\r\n";
						pqMax.pop();
					}
				}


				void callPriorityQueueUsagePlainInt()
				{
					comprMore cMore;
					comprLess cLess;

					
					priority_queue<int, vector<int>, comprMore> pqMax(cMore);
					priority_queue<int, vector<int>, comprLess> pqMin(cLess);

					pqMax.push(16);
					pqMax.push(32);
					pqMax.push(2);
					pqMax.push(12);

					pqMin.push(6);
					pqMin.push(320);
					pqMin.push(76);
					pqMin.push(3);
					pqMin.push(56);


					
					cout << "\r\nQueue content";
					//Pop one by one
					//print the values of heaps
					cout << endl << "Minheap content" << endl;
					while (pqMin.empty() == false)
					{
						cout << pqMin.top() << " ";
						pqMin.pop();
					}
					cout << endl;
					cout << endl << "Maxheap content" << endl;
					while (pqMax.empty() == false)
					{
						cout << pqMax.top() << " ";
						pqMax.pop();
					}
					cout << endl;
				}
	};
};
