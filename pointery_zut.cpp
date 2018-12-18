#include<iostream>
#include<memory>
#include<functional>

template<typename T>
class UP
{
	T *u_pointer;
public:
	UP() : u_pointer(nullptr){}
	explicit UP(T* p) : u_pointer(p){}
	~UP()
	{
		delete u_pointer;
	}
	UP(std::nullptr_t) : u_pointer(nullptr){}	
	T* get() const{return u_pointer;}
	UP(UP<T>&& something)
	{
		u_pointer = std::move(something.u_pointer);
		something.u_pointer = nullptr;
	}
	UP(const UP<T> &something_else) = delete;
	UP<T>& operator=(const UP<T>& ptr)  = delete;
	
	UP<T>& operator=(UP<T>&& ptr) noexcept
	{
		u_pointer = std::move(ptr.u_pointer);
		ptr.u_pointer = nullptr;
		return *this;
	}	

	T* operator->() const {return u_pointer;}
	T& operator*() const {return *u_pointer;}
	bool operator==(const UP<T> &a){return u_pointer == a.get();}
	bool operator>(const UP<T> &a){return a.get() < u_pointer;}
	bool operator>=(const UP<T> &a){return !(a.get() > u_pointer);}
	bool operator<(const UP<T> &a){return a.get() > u_pointer;}
	bool operator<=(const UP<T> &a){return !(a.get() < u_pointer);}
	bool operator!=(const UP<T> &a){return a.get() != u_pointer;}
	
	void swap(UP<T>&a)
	{
	T* tmp = u_pointer;
	u_pointer = a.u_pointer;
	a.u_pointer = tmp;
	}
};

int main()
{
	UP<int> a(new int(5));
	std::cout<<"a: "<<a.get()<<std::endl;
	UP<int> b(new int(2));
	a.swap(b);
	std::cout<<"a: "<<*a.get()<<std::endl;
	std::cout<<"b: "<<*b.get()<<std::endl;
	UP<int> c;
	c = std::move(a);
	std::cout<<"b: "<<b.get()<<std::endl;
	std::cout<<"c: "<<c.get()<<std::endl;
	if(c>=b)
		std::cout<<"yes"<<std::endl;
	else
		std::cout<<"no"<<std::endl;

	return 0;
}
