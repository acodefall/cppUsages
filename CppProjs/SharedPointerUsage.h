#pragma once
#include <iostream>
#include <list>
#include <memory>
#include <random>
using namespace std;
namespace SharedPointerUsageNM
{
	//Copy-ctor, assignment, ==, < 
	class Person
	{
	public:
		std::string name;
		int		age;


		Person(char* n, int a)
		{
			name = n;
			age = a;
		}

		~Person()
		{
			cout << "\r\n" << name << " " << age;
		}
		//Copy-ctor (this is required when we are not storing POINTER in stl container)
		Person(const Person& prs)
		{
			cout << "\r\n" << " CopyCtor got called";
			if (this != &prs)
			{
				name = prs.name;
				age = prs.age;
			}
		}
		//Copy-Assignment
		Person& operator = (const Person& prs)
		{
			cout << "\r\n" << " Copy-Assignment =  got called";
			if (this != &prs)
			{
				name = prs.name;
				age = prs.age;
			}
			return *this;
		}

		//Equality
		bool operator == (const Person& prs) const
		{
			cout << "\r\n" << " ==(equality) got called";
			if (age == prs.age)
				return true;
			else
				return false;
		}

		//move-ctor
		Person(const Person&& prs)
		{
			cout << "\r\n" << " MoveCtor got called";
			if (this != &prs)
			{
				name = prs.name;
				age = prs.age;
			}
		}
		//Move-Assignment
		Person& operator = (const Person&& prs)
		{
			cout << "\r\n" << " = got called";
			if (this != &prs)
			{
				name = prs.name;
				age = prs.age;
			}
			return *this;
		}

	};

	class SharedPointerUsage
	{
		public:
			void callSharedPointerUsage()
			{
				cout << "\r\n CreateExamples() \r\n";
				CreateExamples();

				cout << "\r\n RefCountExamples() \r\n";
				RefCountExamples();

				cout << "\r\n NotDO() \r\n";
				//NotDO(); THIS WILL CRASH

				cout << "\r\n WithSTL() \r\n";
				WithSTL();

				cout << "\r\n getRawPointer() \r\n";
				GetRawObject();


				cout << "\r\n CreateSimpleTypes() \r\n";
				CreateSimpleTypes();

			}

			void CreateSimpleTypes()
			{
				shared_ptr<unsigned int> pSimple(new unsigned int[10]);
				unsigned int* pdata = pSimple.get();
				for (int i = 0; i < 10; i++)
				{
					pdata[i] = i+100;
				}

				for (int i = 0; i < 10; i++)
				{
					cout << pdata[i];
				}
				
			}
			void CreateExamples()
			{
				/*
				shared_ptr can be initialized in two ways
				1) as part of declaration of shared_ptr.
				2) after the declaration of shared_ptr.
				*/

				//1) Initialize shared_ptr as part of declaration.
				shared_ptr<Person> pDecl1(new Person((char*)"createOne", 1));

				//1.a) Initialize shared_ptr as part of declaration, using make_shared()
				//shared_ptr<Person> pDecl2 = make_shared<Person>(new Person("two", 2)); //ERRROR 
				//This expects "const-person"

				//1.b) Initialize shared_ptr as part of declaration, using make_shared()
				shared_ptr<Person> pDecl3 = make_shared<Person>((char*)"createtwo", 2);


				//2) Initialize shared_ptr after the declaration, using make_shared()
				shared_ptr<Person> pPostDecl1(nullptr);
				pPostDecl1 = make_shared<Person>((char*)"createthree", 2);

				//2) Initialize shared_ptr after the declaration, using assignment
				shared_ptr<Person> pPostDecl2(nullptr);
				pPostDecl1 = pDecl1; //This will increment of refcount of pDecl1

			}

			void RefCountExamples()
			{
				/*
					Refcount increment scenarios
					shared_ptr will increment ref counter 
						-when shared_ptr is passed as function argument ( by-value)
								void workOnPerson(share_ptr<Person> p)
								{
								}
						-when function returns shared_ptr by-value
								shared_ptr<Person>  createPerson();
								{
					
								}
						-when we assign one instance of share_ptr to another instance
								shared_ptr<Person> pempty;
								pempty = ploaded; //will increment REF COUNT

						-when we initialize one instance of share_ptr with the another instance
								shared_ptr<Person> pempty2(ploaded); //will increment REF COUNT
					In all above cases share_ptr will be holding same raw-pointer 
				*/
				
				//Initialize one instance of share_ptr with the another instance
				shared_ptr<Person> pref1(new Person((char*)"RefCountOne", 1));
				shared_ptr<Person> pref11(pref1); //this should increment the refcount of pref1


				//assign one instance of share_ptr to another instance
				shared_ptr<Person> pref5(nullptr);
				shared_ptr<Person> pref52(new Person((char*)"RefCountFive", 1)); //this should increment the refcount of pref52
				pref5 = pref52;

				//shared_ptr is passed as function argument ( by-value)
				shared_ptr<Person> pref7(new Person((char*)"RefCountPassByValue", 1));
				passByvalue(pref7);//this should increment the refcount of pref7

				//function returns shared_ptr by-value
				shared_ptr<Person> pref9(nullptr);
				pref9 = returnByvalue(); 
			}

			void passByvalue(shared_ptr<Person> p)
			{

			}

			//we can create object in a function and return it to caller, without worrying about who is giong to FREE it.
			shared_ptr<Person> returnByvalue()
			{
				shared_ptr<Person> pref8(new Person((char*)"RefCountReturnByValue", 1));
				return pref8;
			}


			void NotDO()
			{
				/*
					raw pointer pointer returned by share_ptr.get() should not be assigned to another shared_ptr instance;
					In this case two instances of shared_ptr will be pointing to same raw-pointer, and that is bad.
						share_ptr<Person> ploaded = make_shared<Person>("one", 1);
						share_ptr<Person> pBad = ploaded.get(); //This is bad
						share_ptr<Person> pBad2 = ploaded; //This is standard
				*/
				try
				{
					shared_ptr<Person> pref3(new Person("NotDo", 1));
					shared_ptr<Person> pref33(pref3.get());
				}
				catch (...)
				{
					cout << " \r\n EXCEPTION in NotDO() \r\n";
				}

			}

			void WithSTL()
			{
				list<shared_ptr<Person>> lst1;
				list<shared_ptr<Person>> lst2;

				for (int i = 0; i < 7; i++)
				{
					lst1.push_back(createPerson(i));
				}

				for (auto itr = lst1.begin(); itr != lst1.end(); itr++)
				{
					lst2.push_back(*itr); //Increments the ref-count in lst1
					//lst2.push_back(make_shared<Person>((*itr).get())); //BBBAD. Should not be done. "Assiging same raw-object to multiple shared_ptr instances is BAAD"
				}
				
			}
			void GetRawObject()
			{
				shared_ptr<Person> pref2(new Person("GetRawObject", 1));
				Person* pref23 = pref2.get();
			}
			shared_ptr<Person> createPerson(int i)
			{
				int seed = i + 89;
				default_random_engine rnd(seed);
				uniform_int_distribution<int> dist(10, 900);

				//Person* p = new Person("ssss", dist(rnd));
			
				//return make_shared<Person>(p);
				return make_shared<Person>((char*)"WithSTL", dist(rnd));
			}
	};
};