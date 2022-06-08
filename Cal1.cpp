#include "Calculator.h"

int main()
{
	while (true)
	{
		Calculator cal;
		if (cal.CheckFirstChar())
		{
			break;
		}	
		std::cout << cal.GetRawString() << " = " << cal.MainLoop() << std::endl;
	}
	return 0;
}