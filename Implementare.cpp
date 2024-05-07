#include <string>
#include <vector>
#include <iostream>


const bool anagramaPalindrom(const std::string& input)
{
	if (input.empty() || input.size() == 1)
		return true;

	//Pastreaza literele care se gasesc in sir si nr ce indica de cate ori fiecare dintre literea apare in sir
	//Initializam vectorul dat cu primul element si indicam pentru el count = 1
	std::vector<std::vector<unsigned>> containerCount = {{static_cast<unsigned>(input.at(0)), 1}};

	//Indica daca litera curenta este gasita in containerCount
	bool flag_caracter_gasit = false;

	for (size_t i{1}; i < input.size(); i++)
	{
		for (size_t j{}; j < containerCount.size(); j++)
		{	
			//Daca litera curenta este gasita in containerCount, incrementam count-ul pentru ea
			if (containerCount.at(j).at(0) == input.at(i))
			{
				containerCount.at(j).at(1)++; 
				flag_caracter_gasit = true;
				break;
			}
		}

		//Daca litera curenta nu este gasita in containerCount o inregistram si ii punem count = 1
		if (!flag_caracter_gasit) 
		{
			containerCount.push_back({ static_cast<unsigned>(input.at(i)), 1 });
		}

		flag_caracter_gasit = false;
	}

	//Daca cel putin doua litere apar in sir de un numar impar de ori, atunci sirul nu poate fi aranjat in palindrom
	//'flag_odd_nr' indica daca avem un numar impar de gasiri in sir pentru un caracter
	bool flag_odd_nr = false;
	bool result = false;

	//'containerCount.size()' nu poate depasi 256 
	for (size_t i{}; i < containerCount.size(); i++)
	{
		if (!flag_odd_nr && (containerCount.at(i).at(1) % 2))
		{
			result = true;
			flag_odd_nr = true;
		} 
		else if (!(containerCount.at(i).at(1) % 2))
		{
			result = true;
		} 
		else
		{
			return false; 
		}
	}

	return result;
}