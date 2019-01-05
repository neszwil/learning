#include<algorithm>
#include<iostream>
#include<vector>
#include<thread>

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
  
    // Find r such that n = 2^d * r + 1 for some r >= 1 
    long long d = n - 1; 
    while (d % 2 == 0) 
        d /= 2; 
  
    // Iterate given nber of 'k' times 
    for (int i = 0; i < k; i++) 
         if (!miillerTest(d, n)) 
              return false; 
  
    return true; 
} 

bool trial(long long data)
{
	if(data<2)
		//std::cout<<"no"<<std::endl;
		return false;
	for(int i = 2; i*i<=data;i++)
		if(data%i==0)
			//std::cout<<"no"<<std::endl;
			return false;
	//std::cout<<"yes"<<std::endl;
	return true;
}

void func(const std::vector<int>& value)
{
    
	std::for_each(value.begin(), value.end(), trial);
	std::for_each(value.begin(), value.end(), isPrime);
}

int main()
{
    std::vector<std::vector<int>> values = 
       { { 1, 2 } , { 1, 2, 3 }, { 1, 2, 3, 4 } };

    std::vector<std::thread> threads;
    for (auto& vect: values)
    {
        threads.emplace_back(func, std::cref(vect));
    }

    for (auto& thread: threads)
    {
        thread.join();
    }
    long long x = 2999;
    if(isPrime(x))
	std::cout<<"Rabin yes"<<std::endl;
    else
	std::cout<<"Rabin no"<<std::endl;
    if(trial(x))
	std::cout<<"trial yes"<<std::endl;
    else
	std::cout<<"trial no"<<std::endl;
    return 0;
}
