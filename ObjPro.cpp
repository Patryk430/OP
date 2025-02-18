#include <iostream>
#include <iomanip>
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
	double galutinis;
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
			 << "Noredami baigti darbą, įveskite '4' ar betkokį kitą skaičių " << std::endl
			 <<"jus: ";
	std::cin>> pasirinkimas_pradzia;

	if (!std::cin) {
		std::cout<<"JUSU ĮVEDIMAS NETINKAMAS, BAIGIU DARBĄ"; return; 
   	};

	std::cout<<std::endl;

	//if (pasirinkimas_pradzia==4) return;
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

		if (!std::cin) {
			std::cout<<"JUSU ĮVEDIMAS NETINKAMAS, BAIGIU DARBĄ"; return; 
		   };

		if (pasirinkimas_pradzia==3)
		{
			bool pazymiu_pildymas=true;
			while (pazymiu_pildymas)
			{
				std::cout << "įveskite " << i+1 << "-ojo  studento pažymį" << std::endl;
				std::cin >> temp;

				if (!std::cin) {
					std::cout<<"JUSU ĮVEDIMAS NETINKAMAS, BAIGIU DARBĄ"; return; 
				   };

				stud[i].pazymiai.push_back(temp);

				std::cout << "Ar jis turi dar viena pažymį? jei ne įveskite '0' jei taip įveskite '1'" << std::endl;
				std::cin >> pazymiu_pildymas;

				if (!std::cin) {
					std::cout<<"JUSU ĮVEDIMAS NETINKAMAS, BAIGIU DARBĄ"; return; 
				   };
			}
		}

		if (pasirinkimas_pradzia==2) pazymiu_generacija(i);

		i++;
		std::cout<<"Ar dar yra studentų? jei ne įveskite '0' jei taip įveskite '1'" << std::endl;
		std::cin>>studentu_pildymas;

		if (!std::cin) {
			std::cout<<"JUSU ĮVEDIMAS NETINKAMAS, BAIGIU DARBĄ"; return; 
		   };
	};

	rezultatas();
};

void rezultatas()
{
	std::cout << "'0' - išvesti naudojant vidurkį | '1' - išvesti naudojant medianą" << std::endl;
	std::cin >> rezultato_tipas;

	if (!std::cin) {
		std::cout<<"JUSU ĮVEDIMAS NETINKAMAS, BAIGIU DARBĄ"; return; 
   	};

	std::cout << std::setw(20) << "VARDAS" << std::setw(20) << "PAVARDĖ" << std::setw(20) << "GALUTINIS" << std::endl
	<< "_____________________________________________________________" << std::endl;

	for (int i = 0; i< stud.size(); i++)
	{
		if (rezultato_tipas)
		{
			sort(stud[i].pazymiai.begin(), stud[i].pazymiai.end());
	
			if (stud[i].pazymiai.size() % 2 != 0)
				stud[i].mediana = (double) stud[i].pazymiai[stud[i].pazymiai.size() / 2];
			else
				stud[i].mediana = (double) (stud[i].pazymiai[(stud[i].pazymiai.size() - 1) / 2] + stud[i].pazymiai[stud[i].pazymiai.size() / 2]) / 2.0;

			stud[i].galutinis= (double) stud[i].mediana * 0.4 + stud[i].egzaminas * 0.6;
		}	

		else
		{
			int sum = std::accumulate(stud[i].pazymiai.begin(), stud[i].pazymiai.end(), 0);

			stud[i].vidurkis = (double) sum / stud[i].pazymiai.size();
			stud[i].galutinis = (double) stud[i].vidurkis * 0.4 + stud[i].egzaminas * 0.6;
		}

		std::cout << std::setw(20) << stud[i].vardas << std::setw(20) << stud[i].pavarde <<  std::setw(20) << std::setprecision(3) << stud[i].galutinis << std::endl;

		
	}
	
	pradzia();
};

void automatinis()
{
	std::string vardai [10] = {"Arnas", "Emilis", "Andrius", "Nojus", "Jonas", "Gabrielius", "Vardenis", "Tadas", "Julius", "Ignas"};
	std::string pavardes [10] = {"Arnaitis", "Jonaitis", "Ponaitis", "fon Brandenburgas", "Pavardenis", "Gediminaitis", "Nausėda", "Biliūnas", "Studentaitis", "Aleksejevas"};

	std::cout<<"Kiek studentu sugeneruoti?"<<std::endl;
	std::cin>>stud_skc;

	if (!std::cin) {
		std::cout<<"JUSŲ ĮVEDIMAS NETINKAMAS, BAIGIU DARBĄ"; return; 
   	};

	for (int i=0; i<stud_skc; i++)
	{
		stud.push_back(studentas());

		stud[i].vardas = vardai[0 + rand() % 10];

		stud[i].pavarde = pavardes[0 + rand() % (10-0)+1];

		stud[i].egzaminas = 1 + rand() % (10-1)+1;

		pazymiu_generacija(i);
	}
	
	rezultatas();
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