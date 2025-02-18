#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ctime>
#include <random>

int stud_skc;
int temp;
int paz_skc;
bool rezultato_tipas; 
int pasirinkimas_pradzia;



struct studentas
{
	std::string vardas;
	std::string pavarde;

	std::vector <int> pazymiai;
	int egzaminas;
	double vidurkis;
	double mediana;
};

std::vector <studentas> stud;

void pradzia();
void rankinis();
void automatinis();
void rezultatas();
void pazymiu_generacija(int i);

int main()
{
	srand (time(NULL));

 	pradzia();

 	return 0;
}

void pradzia()
{
	std::cout<< "Sveiki." << std::endl 
			 << "Noredami, kad programa sugeneruotu studentus įveskite, '1' " << std::endl 
			 << "Noredami, kad programa sugeneruotu tik jų pažymius, įveskite '2' " << std::endl
			 << "Noredami, duomenis ivest rankiniu būdu, įveskite '3' " << std::endl
			 << "Noredami baigti darbą, įveskite '4' " << std::endl
			 <<"jus: ";
	std::cin>> pasirinkimas_pradzia;
	std::cout<<std::endl;

	if (pasirinkimas_pradzia==4) return;
	if (pasirinkimas_pradzia==3) rankinis();
	if (pasirinkimas_pradzia==2) rankinis();
	if (pasirinkimas_pradzia==1) automatinis();
	

};		

void rankinis()
{
	bool studentu_pildymas=true;
	int i=0;

	while (studentu_pildymas)
	{
		stud.push_back(studentas());

		std::cout << "koks " << i+1 << "-ojo  studento vardas" << std::endl;
		std::cin >> stud[i].vardas;

		std::cout << "kokia " << i+1 << "-ojo  studento pavardė" << std::endl;
		std::cin >> stud[i].pavarde;

		std::cout << "koks " << i+1 << "-ojo  studento egzamino pažymis" << std::endl;
		std::cin >> stud[i].egzaminas;

		if (pasirinkimas_pradzia==3)
		{
			bool pazymiu_pildymas=true;
			while (pazymiu_pildymas)
			{
				std::cout << "įveskite " << i+1 << "-ojo  studento pažymį" << std::endl;
				std::cin >> temp;
				stud[i].pazymiai.push_back(temp);

				std::cout << "Ar jis turi dar viena pažymį? jei ne įveskite '0' jei taip įveskite '1'" << std::endl;
				std::cin >> pazymiu_pildymas;
			}
		}

		if (pasirinkimas_pradzia==2) pazymiu_generacija(i);

		i++;
		std::cout<<"Ar dar yra studentų? jei ne įveskite '0' jei taip įveskite '1'" << std::endl;
		std::cin>>studentu_pildymas;
	};

	rezultatas();
};

void rezultatas()
{
	std::cout << "0-isvest vidurki 1-mediana" << std::endl;
	std::cin >> rezultato_tipas;

	for (int i = 0; i< stud.size(); i++)
	{
		int sum = std::accumulate(stud[i].pazymiai.begin(), stud[i].pazymiai.end(), 0);

		stud[i].vidurkis = sum / stud[i].pazymiai.size();
		stud[i].vidurkis = stud[i].vidurkis * 0.4 + stud[i].egzaminas * 0.6;
	
		sort(stud[i].pazymiai.begin(), stud[i].pazymiai.end());
	
		if (stud[i].pazymiai.size() % 2 != 0)
			stud[i].mediana = (double)stud[i].pazymiai[stud[i].pazymiai.size() / 2];
		else
			stud[i].mediana = (double)(stud[i].pazymiai[(stud[i].pazymiai.size() - 1) / 2] + stud[i].pazymiai[stud[i].pazymiai.size() / 2]) / 2.0;


		if (rezultato_tipas) std::cout << stud[i].vardas << " " << stud[i].pavarde <<  " " << stud[i].mediana << std::endl;
		else std::cout << stud[i].vardas << " " << stud[i].pavarde << " " << stud[i].vidurkis << std::endl;
	}
};

void automatinis()
{

};

void pazymiu_generacija(int i)
{
	std::cout<<"Kiek pažymių turi "<<i+1<<"-tasis studentas?"<<std::endl;
	std::cin>>paz_skc;

	for (int j=0; j<paz_skc; j++)
	{
	temp = 1 + rand() % (10-1)+1;
	stud[i].pazymiai.push_back(temp);
	};
};