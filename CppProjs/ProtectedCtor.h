#pragma once
#include <iostream>

using namespace std;

namespace ProtectedCtorNM
{
	/*
		Protected constructors makes the class unavailable for outsiders and available for derived classes.
	*/
	class ProtectedCtorC
	{
		protected:
			ProtectedCtorC()
			{
				cout << "ProtectedCtorC::ProtectedCtorC() protected ctor" << endl;
			}

		public:
			void M1()
			{
				cout << "ProtectedCtorC::M1()" << endl;
			}
	};

	class ProtectedCtorArc : public ProtectedCtorC
	{
		public:
			ProtectedCtorArc()
			{
				cout << "ProtectedCtorArc::ProtectedCtorArc()" << endl;
			}

	
			void M2()
			{
				cout << "ProtectedCtorArc::M2()" << endl;
			}

	};


	class callProtectedCtorArc 
	{
		public:
				void test()
				{
					ProtectedCtorArc o1;
					o1.M2();
					o1.M1();
				}
				/* Output
					ProtectedCtorC::ProtectedCtorC() protected ctor
						ProtectedCtorArc::ProtectedCtorArc()
							ProtectedCtorArc::M2()
							ProtectedCtorC::M1()

				*/
	};
};