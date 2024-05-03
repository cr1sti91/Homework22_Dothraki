#include <iostream>

const bool anagramaPalindrom(const std::string& input);

int main()
{
	std::string sir; 

	std::cout << "Introdu sirul de litere: "; 
	std::cin >> sir;

	std::cout << std::boolalpha; 
	if (anagramaPalindrom(sir))
	{
		std::cout << "DA" << std::endl;
	}
	else
	{
		std::cout << "NU" << std::endl;
	}
}

