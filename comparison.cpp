#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<chrono>
#include<list>
#include<string>

int main()
{
   srand(time(NULL));


//struct
   struct DanePraca{
   std::string stanowisko;
   int pensja;
   std::string ulica;
   int numer;
   int lokal;
   };
   struct DaneMieszkania{
   std::string ulica;
   int numer;
   int lokal;
   float czynsz;
   };
   struct Osoba{
   std::string imie;
   std::string nazwisko;
   int wiek;
   char plec;
   struct DaneMieszkania mieszkanie;
   struct DanePraca praca;
   };
   Osoba jakasOsoba;
   jakasOsoba.imie = "Janusz";
   jakasOsoba.nazwisko = "Kowalski";
   jakasOsoba.wiek = 45;
   jakasOsoba.plec = 'm';
   jakasOsoba.praca.stanowisko = "Programista";
   jakasOsoba.praca.pensja = 15000;
   jakasOsoba.praca.ulica = "Wojska Polskiego";
   jakasOsoba.praca.numer = 5;
   jakasOsoba.praca.lokal = 123;
   jakasOsoba.mieszkanie.ulica = "Poziomkowa";
   jakasOsoba.mieszkanie.numer = 56784;
   jakasOsoba.mieszkanie.lokal = 53426;
   jakasOsoba.mieszkanie.czynsz= 567,56;
//vector
   std::vector<int> v1;
   std::vector<float> v2;
   std::vector<std::vector<struct Osoba>> v3;
   std::vector<struct Osoba> duzy_vector;
   for(int k=0;k<3;k++)
      {duzy_vector.push_back(jakasOsoba);} 
//list
   std::list<int> l1;
   std::list<float> l2;
   std::list<std::vector<struct Osoba>> l3;
   std::list<int>::iterator i1;
   std::list<float>::iterator i2;
   std::list<std::vector<struct Osoba>>::iterator i3;
//auxiliary variables
   int i,j, liczba=std::rand(), pozycja = 349267;
   float liczba_f=std::rand()/10.23;
//adding int to the vector
   std::chrono::time_point<std::chrono::system_clock> start, end;
   start = std::chrono::system_clock::now();
      for(i=0;i<1000000;i++)
         v1.push_back(liczba);
   end = std::chrono::system_clock::now();
   std::chrono::duration<double> elapsed_seconds = end - start;
   std::cout << "adding int to vector "<<elapsed_seconds.count() <<std::endl;
//adding int to the list
   std::chrono::time_point<std::chrono::system_clock> start3, end3;
   start3 = std::chrono::system_clock::now();
      for(i=0;i<1000000;i++)
         l1.push_back(liczba);
   end3 = std::chrono::system_clock::now();
   std::chrono::duration<double> elapsed_seconds3 = end3 - start3;
   std::cout << "adding int to list "<<elapsed_seconds3.count() <<std::endl;
//adding float to the vectora 
   std::chrono::time_point<std::chrono::system_clock> start2, end2;
   start2 = std::chrono::system_clock::now();
      for(i=0;i<1000000;i++)
         v2.push_back(liczba_f);
   end2 = std::chrono::system_clock::now();
   std::chrono::duration<double> elapsed_seconds2 = end2 - start2;
   std::cout << "adding float to vector "<<elapsed_seconds2.count() <<std::endl;
//adding float to the list
   std::chrono::time_point<std::chrono::system_clock> start5, end5;
   start5 = std::chrono::system_clock::now();
      for(i=0;i<1000000;i++)
         l2.push_back(liczba_f);
   end5 = std::chrono::system_clock::now();
   std::chrono::duration<double> elapsed_seconds5 = end5 - start5;
   std::cout << "adding float to list "<<elapsed_seconds5.count() <<std::endl;
//adding struct to the vectora 
   std::chrono::time_point<std::chrono::system_clock> start21, end21;
   start21 = std::chrono::system_clock::now();
      for(i=0;i<1000000;i++)
         v3.push_back(duzy_vector);
   end21 = std::chrono::system_clock::now();
   std::chrono::duration<double> elapsed_seconds21 = end21 - start21;
   std::cout << "adding struct to vector "<<elapsed_seconds21.count() <<std::endl;
//adding struct to the list
   std::chrono::time_point<std::chrono::system_clock> start51, end51;
   start51 = std::chrono::system_clock::now();
      for(i=0;i<1000000;i++)
         l3.push_back(duzy_vector);
   end51 = std::chrono::system_clock::now();
   std::chrono::duration<double> elapsed_seconds51 = end51 - start51;
   std::cout << "adding struct to list "<<elapsed_seconds51.count() <<std::endl;
//finding sepcified value in vector of int
   std::chrono::time_point<std::chrono::system_clock> start4, end4;
   start4 = std::chrono::system_clock::now();
      v1[pozycja];
   end4 = std::chrono::system_clock::now();
   std::chrono::duration<double> elapsed_seconds4 = end4 - start4;
   std::cout << "specified value in vetor<int> "<<elapsed_seconds4.count() <<std::endl;
//finding sepcified value in list<int>
   std::chrono::time_point<std::chrono::system_clock> start7, end7;
   start7 = std::chrono::system_clock::now();
      auto it=std::next(l1.begin(), pozycja);
   end7 = std::chrono::system_clock::now();
   std::chrono::duration<double> elapsed_seconds7 = end7 - start7;
   std::cout << "specified value in list<int> "<<elapsed_seconds7.count() <<std::endl;
//finding sepcified value in vector of float
   std::chrono::time_point<std::chrono::system_clock> start6, end6;
   start6 = std::chrono::system_clock::now();
      v2[pozycja];
   end6 = std::chrono::system_clock::now();
   std::chrono::duration<double> elapsed_seconds6 = end6 - start6;
   std::cout << "specified value in vetor<float> "<<elapsed_seconds6.count() <<std::endl;
//finding sepcified value in list<float>
   std::chrono::time_point<std::chrono::system_clock> start8, end8;
   start8 = std::chrono::system_clock::now();
      auto it2=std::next(l2.begin(), pozycja);
   end8 = std::chrono::system_clock::now();
   std::chrono::duration<double> elapsed_seconds8 = end8 - start8;
   std::cout << "specified value in list<float> "<<elapsed_seconds8.count() <<std::endl;
//finding sepcified value in vector of struct
   std::chrono::time_point<std::chrono::system_clock> start61, end61;
   start61 = std::chrono::system_clock::now();
      v3[pozycja];
   end61 = std::chrono::system_clock::now();
   std::chrono::duration<double> elapsed_seconds61 = end61 - start61;
   std::cout << "specified value in vetor<struct> "<<elapsed_seconds61.count() <<std::endl;
//finding sepcified value in list<struct>
   std::chrono::time_point<std::chrono::system_clock> start81, end81;
   start81 = std::chrono::system_clock::now();
      auto it3=std::next(l3.begin(), pozycja);
   end81 = std::chrono::system_clock::now();
   std::chrono::duration<double> elapsed_seconds81 = end81 - start81;
   std::cout << "specified value in list<struct> "<<elapsed_seconds81.count() <<std::endl;
//inserting at random position vector<int>
   std::chrono::time_point<std::chrono::system_clock> start9, end9;  
   start9 = std::chrono::system_clock::now();
      auto itpos=v1.begin()+pozycja;
      auto newit=v1.insert(itpos, liczba);
   end9 = std::chrono::system_clock::now();
   std::chrono::duration<double> elapsed_seconds9 = end9 - start9;
   std::cout << "inserting at random position vetor<int> "<<elapsed_seconds9.count() <<std::endl;
//inserting at random position list<int>
   std::chrono::time_point<std::chrono::system_clock> start11, end11;
   start11 = std::chrono::system_clock::now();
   i1 = l1.begin();
   for(j=0;j<pozycja;j++){i1++;}
   l1.insert(i1, liczba);
   end11 = std::chrono::system_clock::now();
   std::chrono::duration<double> elapsed_seconds11 = end11 - start11;
   std::cout << "inserting at random position list<int> "<<elapsed_seconds11.count() <<std::endl;
//inserting at random position vector<float>
   std::chrono::time_point<std::chrono::system_clock> start10, end10; 
   start10 = std::chrono::system_clock::now();
      auto itpos2=v2.begin()+pozycja;
      auto newit2=v2.insert(itpos2, liczba_f);
   end10 = std::chrono::system_clock::now();
   std::chrono::duration<double> elapsed_seconds10 = end10 - start10;
   std::cout << "inserting at random position vetor<float> "<<elapsed_seconds10.count() <<std::endl;
//inserting at random position list<float>
   std::chrono::time_point<std::chrono::system_clock> start12, end12;
   start12 = std::chrono::system_clock::now();
   i2 = l2.begin();
   for(j=0;j<pozycja;j++){i2++;}
   l2.insert(i2, liczba_f);
   end12 = std::chrono::system_clock::now();
   std::chrono::duration<double> elapsed_seconds12 = end12 - start12;
   std::cout << "inserting at random position list<float> "<<elapsed_seconds12.count() <<std::endl;
//inserting at random position vector<struct>
   std::chrono::time_point<std::chrono::system_clock> start101, end101; 
   start101 = std::chrono::system_clock::now();
      auto itpos3=v3.begin()+pozycja;
      auto newit3=v3.insert(itpos3, duzy_vector);
   end101 = std::chrono::system_clock::now();
   std::chrono::duration<double> elapsed_seconds101 = end101 - start101;
   std::cout << "inserting at random position vetor<struct> "<<elapsed_seconds101.count() <<std::endl;

//inserting at random position list<struct>
   std::chrono::time_point<std::chrono::system_clock> start121, end121;
   start121 = std::chrono::system_clock::now();
   i3 = l3.begin();
   for(j=0;j<pozycja;j++){i2++;}
   l3.insert(i3, duzy_vector);
   end121 = std::chrono::system_clock::now();
   std::chrono::duration<double> elapsed_seconds121 = end121 - start121;
   std::cout << "inserting at random position list<struct> "<<elapsed_seconds121.count() <<std::endl;
return 0;
}
