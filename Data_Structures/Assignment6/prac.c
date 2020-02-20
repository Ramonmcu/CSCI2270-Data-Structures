
#include <stdlib.h>



int main()
{
	int a = 10;
	int*p = &a;

	std::cout<<p<<endl;
	std::cout<<a<<endl;

	std::cout<<*p<<endl;

	return 0;
}