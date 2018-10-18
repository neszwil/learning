#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<chrono>

int main(){
   srand(time(NULL));
   std::vector<int> v1;
   std::vector<float> v2;
   int i, liczba=std::rand();
   auto start = std::chrono::system_clock::now();
   for(i=0;i<1000000;i++)
      v1.push_back(liczba);

   auto end = std::chrono::system_clock::now();
   auto elapsed = end - start;
   std::cout << elapsed.count() <<"\n";





   auto start2 = std::chrono::system_clock::now();

   for(i=0;i<1000000;i++)
      v2.push_back(liczba/107);

   auto end2 = std::chrono::system_clock::now();
   auto elapsed2 = end2 - start2;
   std::cout << elapsed2.count() <<"\n";








return 0;
}

