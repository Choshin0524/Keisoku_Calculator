#include "Calculator.h"
#include <iomanip>

int main()
{
	while (true)
	{
		Calculator cal;
		auto r = cal.Separator();
		std::cout << std::setprecision(
			r[0].length() > r[2].length() ? (r[0].length()) : (r[2].length())) //ê∏ìxåàÇﬂ
			<< cal.GetMainString() << " = " << cal.Calculate(r) << std::endl;
	}
	return 0;
}