#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<chrono>
#include<list>

int main(){
   srand(time(NULL));
//vector
   std::vector<int> v1;
   std::vector<float> v2; 
//list
   std::list<int> l1;
   std::list<float> l2;

   int i, liczba=std::rand(), pozycja = 349267;
   float liczba_f=std::rand()/10.23;
//dodawanie int do vectora
   auto start = std::chrono::system_clock::now();
   for(i=0;i<1000000;i++)
      v1.push_back(liczba);
   auto end = std::chrono::system_clock::now();
   auto elapsed = end - start;
   std::cout << "add int to vector "<<std::endl<<elapsed.count() <<std::endl;
//dodawanie float do vectora 
   auto start2 = std::chrono::system_clock::now();
   for(i=0;i<1000000;i++)
      v2.push_back(liczba_f);
   auto end2 = std::chrono::system_clock::now();
   auto elapsed2 = end2 - start2;
   std::cout << "add float to vector "<<std::endl<<elapsed2.count() <<std::endl;
//add int to list
   auto start3 = std::chrono::system_clock::now();
   for(i=0;i<1000000;i++)
      l1.push_back(liczba);
   auto end3 = std::chrono::system_clock::now();
   auto elapsed3 = end3 - start3;
   std::cout << "add int to list "<<std::endl<<elapsed3.count() <<std::endl;
//add float to list
   auto start5 = std::chrono::system_clock::now();
   for(i=0;i<1000000;i++)
      l2.push_back(liczba_f);
   auto end5 = std::chrono::system_clock::now();
   auto elapsed5 = end5 - start5;
   std::cout << "add float to list "<<std::endl<<elapsed5.count() <<std::endl;
//find sepcified value in vector of int
   auto start4 = std::chrono::system_clock::now();
   v1[pozycja];
   auto end4 = std::chrono::system_clock::now();
   auto elapsed4 = end4 - start4;
   std::cout << "specified value in vetor<int> "<<v1[pozycja]<<std::endl<<elapsed4.count() <<std::endl;
//find sepcified value in vector of float
   auto start6 = std::chrono::system_clock::now();
   v2[pozycja];
   auto end6 = std::chrono::system_clock::now();
   auto elapsed6 = end6 - start6;
   std::cout << "specified value in vetor<float> "<<v2[pozycja]<<std::endl<<elapsed6.count() <<std::endl;
//find sepcified value in list<int>
   auto start7 = std::chrono::system_clock::now();
   auto it=std::next(l1.begin(), pozycja);
   auto end7 = std::chrono::system_clock::now();
   auto elapsed7 = end7 - start7;
   std::cout << "specified value in list<int> "<<*it<<std::endl<<elapsed7.count() <<std::endl;
//find sepcified value in list<float>
   auto start8 = std::chrono::system_clock::now();
   auto it2=std::next(l2.begin(), pozycja);
   auto end8 = std::chrono::system_clock::now();
   auto elapsed8 = end8 - start8;
   std::cout << "specified value in list<float> "<<*it2<<std::endl<<elapsed8.count() <<std::endl;
//insert at random position vector<int> 
   auto start9 = std::chrono::system_clock::now();
   auto itpos=v1.begin()+pozycja;
   auto newit=v1.insert(itpos, liczba);
   auto end9 = std::chrono::system_clock::now();
   auto elapsed9 = end9 - start9;
   std::cout << "insert at random position vetor<int>"<<std::endl<<elapsed9.count() <<std::endl;
//insert at random position vector<float> 
   auto start10 = std::chrono::system_clock::now();
   auto itpos2=v2.begin()+pozycja;
   auto newit2=v2.insert(itpos2, liczba_f);
   auto end10 = std::chrono::system_clock::now();
   auto elapsed10 = end10 - start10;
   std::cout << "insert at random position vetor<float>"<<std::endl<<elapsed10.count() <<std::endl;










return 0;
}

