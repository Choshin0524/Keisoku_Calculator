#include "Calculator.h"
#include <iomanip>

int main()
{
	while (true)
	{
		Calculator cal;
		std::cout << cal.GetRawString() << " = " << cal.MainLoop() << std::endl;
	}
	return 0;
}