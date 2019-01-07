#include<algorithm>
#include<iostream>
#include<vector>
#include<thread>
#include <sstream>
#include <fstream>
#include<chrono>
#include<mutex>
#include<gmp.h>

const unsigned int nproc = std::thread::hardware_concurrency();

long long power(long long x, long long y, long long p) 
{ 
    int res = 1;
    x = x % p; 
                
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p;  
        y = y>>1;
        x = (x*x) % p; 
    } 
    return res; 
} 
  
bool miillerTest(long long d, long long n) 
{ 
    long long a = 2 + rand() % (n - 4); 
    long long x = power(a, d, n); 
  
    if (x == 1  || x == n-1) 
       return true; 
    while (d != n-1) 
    { 
        x = (x * x) % n; 
        d *= 2; 
  
        if (x == 1)      return false; 
        if (x == n-1)    return true; 
    } 
  
    return false; 
} 
  

bool isPrime(long long n) 
{ 
    int k = 4; 
    if (n <= 1 || n == 4)  return false; 
    if (n <= 3) return true; 
    long long d = n - 1; 
    while (d % 2 == 0) 
        d /= 2; 
	for (int i = 0; i < k; i++) 
		if (!miillerTest(d, n)) 
			return false; 
	return true; 
} 

bool trial(long long data)
{
	if(data<2)
		return false;
	for(int i = 2; i*i<=data;i++)
		if(data%i==0)
			return false;
	return true;
}

void func1(const std::vector<long long>& value)
{
	std::for_each(value.begin(), value.end(), trial);
}

void func2(const std::vector<long long>& value)
{	
	std::for_each(value.begin(), value.end(), isPrime);
}


int main()
{
	std::vector<std::vector<long long>> my_v(nproc);
	std::ifstream in("liczby.txt");
	long long value, i = 0;
	while (in >> value)
	{
    	my_v[i].push_back(value);
    	if (++i == nproc)
        	i = 0;
	}

//prime
	
	std::vector<std::vector<long long>>::iterator it = my_v.begin();
	std::vector<std::thread> threads;
	auto start_trial = std::chrono::system_clock::now();
	for(int j=0;j<nproc;j++)
	   	{
        	threads.emplace_back(func1, std::cref(*(it+j)));
    	}

    for (auto& thread: threads)
    {
        thread.join();
    }
    auto end_trial = std::chrono::system_clock::now();
	std::chrono::duration<double> trial_seconds = end_trial - start_trial;
	double czas_trial = trial_seconds.count();
	std::cout<<czas_trial<<std::endl;
	
//miller
	std::vector<std::vector<long long>>::iterator it2 = my_v.begin();
	std::vector<std::thread> threads2;
	auto start_rabin = std::chrono::system_clock::now();
	for(int j=0;j<nproc;j++)
	   	{
        	threads2.emplace_back(func2, std::cref(*(it2+j)));
    	}

    for (auto& thread: threads2)
    {
        thread.join();
    }
    auto end_rabin = std::chrono::system_clock::now();
	std::chrono::duration<double> rabin_seconds = end_rabin - start_rabin;
	double czas_rabin = rabin_seconds.count();
	std::cout<<czas_rabin<<std::endl;
	
    return 0;
}
