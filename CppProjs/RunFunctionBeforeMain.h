#include "stdafx.h"

/*8) How to call a function before main() ?
	Use the directive called "pragma startup" for supplying the function to be executed before MAIN().
	Function body can sit at different place.



#pragma startup fun
void fun()
{
	printf(“In fun\n”);
}
main()
{
	printf(“In main\n”);
}
*/
