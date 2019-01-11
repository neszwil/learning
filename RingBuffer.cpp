#include<iostream>
#include<vector>

class RB
{
	std::vector<int> my_v;
	int head = 0;
	int size_v;
	int read_buf = 0;
	

public:
	RB(int size);
	void add(int value);
	void read();
	void show();
	const std::vector<int> &get_element(){return my_v;};
	std::vector<int>::iterator it;
};

RB::RB(int n):my_v(n)
{
	size_v = my_v.size();
	it = my_v.begin();
}


void RB::add(int value)
{
	if(head<size_v)	
		{
		*(it+head) = value;
		head++;
		}
	else
		{
		head = 0;
		*(it+head) = value;
		head++;
		}
}

void RB::read()
{
	*(it+head) = 0;
	head++;
}

void RB::show()
{
	for(auto const &i:my_v)
		std::cout<<i<<" ";
	std::cout<<"\n";
}



int main()
{
	RB moj(5);
	moj.add(1);
	moj.add(2);
	moj.add(3);
	moj.add(4);
	moj.add(5);
	moj.show();
	moj.add(55);
	moj.show();
	moj.add(66);
	moj.show();
	moj.add(6);
	moj.show();
	moj.read();
	moj.show();
	moj.read();
	moj.show();
	moj.add(7);
	moj.show();
	moj.add(8);
	moj.show();
	moj.add(9);
	moj.show();
	moj.add(10);
	moj.show();
	moj.add(11);
	moj.show();
	moj.add(12);
	moj.show();
	moj.read();
	moj.show();
	for(const auto& item:moj.get_element())
		std::cout<<item<<"*";
	std::cout<<std::endl;
	return 0;
}
