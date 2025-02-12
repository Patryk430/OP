#include <iostream>
#include <string>
#include <vector>
#include <numeric>

int stud_skc;
int temp;
int paz_skc;

struct studentas
{
	std::string vardas;
	std::string pavarde;

	std::vector <int> pazymiai;
	int egzaminas;
	double vidurkis;
};

studentas stud[10];

int main()
{
	std::cout << "Kiek studentu?" << std::endl;
	std::cin >> stud_skc;

	for (int i = 0; i< stud_skc; i++)
	{
		std::cout << "vardas?" << std::endl;
		std::cin >> stud[i].vardas;

		std::cout << "pavardas?" << std::endl;
		std::cin >> stud[i].pavarde;

		std::cout << "kiek pazymiu?" << std::endl;
		std::cin >> paz_skc;

		for (int j = 0; j < paz_skc; j++)
		{
			std::cout << "ivesk" << std::endl;
			std::cin >> temp;
			stud[i].pazymiai.push_back(temp);
		}

		std::cout << "kiek uz egza?" << std::endl;
		std::cin >> stud[i].egzaminas;

		int sum = std::accumulate(stud[i].pazymiai.begin(), stud[i].pazymiai.end(), 0);

		stud[i].vidurkis = sum / stud[i].pazymiai.size();
		stud[i].vidurkis = stud[i].vidurkis * 0.4 + stud[i].egzaminas * 0.6;
	}

	for (int i = 0; i< stud_skc; i++)
	{
		std::cout << stud[i].vardas << " " << stud[i].pavarde << " " << stud[i].vidurkis << std::endl;
	}
}
