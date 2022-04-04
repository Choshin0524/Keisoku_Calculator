#pragma once
#include <iostream>
#include <string>
#include <vector>

class Calculator
{
public:
	Calculator()
	{
		std::cout << "Enter an expresssion." << std::endl;
		std::cin >> MainString;
	};
	~Calculator() = default;
	std::string GetMainString() const;
	std::vector<std::string> Separator() const;
	float Calculate(const std::vector<std::string>& result) const;
private:
	std::string MainString;
};

