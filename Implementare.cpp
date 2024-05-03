#include <string>
#include <vector>
#include <iostream>


const bool anagramaPalindrom(const std::string& input)
{
	if (input.empty() || input.size() == 1)
		return true;


	std::vector<std::vector<unsigned>> containerCount = {{static_cast<unsigned>(input.at(0)), 1}};


	bool flag_caracter_gasit = false;

	for (size_t i{1}; i < input.size(); i++)
	{
		for (size_t j{}; j < containerCount.size(); j++)
		{
			if (containerCount.at(j).at(0) == input.at(i))
			{
				containerCount.at(j).at(1)++; 
				flag_caracter_gasit = true;
				break;
			}
		}

		if (!flag_caracter_gasit) 
		{
			containerCount.push_back({ static_cast<unsigned>(input.at(i)), 1 });
		}

		flag_caracter_gasit = false;
	}


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