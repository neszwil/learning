
#include<iostream> 
#include<cstdlib> 


class Ring_Buffer 
{ 
public:	
	int rear, front; 
	int size; 
	int *arr; 

	Ring_Buffer(int s) : front(-1), rear(-1), size(s)
	{ 
		arr = new int[s]; 
	} 

	void addElement(int value); 
	void delete_element(); 
	void display(); 
}; 

void Ring_Buffer::addElement(int value) 
{ 
	if ((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))) 
	{ 
		delete_element();
		rear++;
		arr[rear] = value;
		front=rear=-1;
		//arr[rear] = value; 
		return; 
	}

	else if (front == -1)
	{ 
		front = rear = 0; 
		arr[rear] = value; 
	} 

	else if (rear == size-1 && front != 0) 
	{ 
		rear = 0; 
		arr[rear] = value; 
	} 

	else
	{ 
		rear++; 
		arr[rear] = value; 
	} 
} 

void Ring_Buffer::delete_element() 
{ 
	if (front == -1) 
	{ 
		std::cout<<"Buffer is Empty"<<std::endl; 
	} 

	int data = arr[front]; 
	arr[front] = -1; 
	if (front == rear) 
	{ 
		front = -1; 
		rear = -1; 
	} 
	else if (front == size-1) 
		front = 0; 
	else
		front++;
} 

void Ring_Buffer::display() 
{ 
	if (front == -1) 
	{ 
		std::cout<<"Buffer is Empty"<<std::endl;
		exit(-1) ; 
	} 
	std::cout<<"Elements: "<<std::endl; 
	if (rear >= front) 
	{ 
		for (int i = front; i <= rear; i++) 
			std::cout<<arr[i]<<" "; 
		std::cout<<std::endl;
	} 
	else
	{ 
		for (int i = front; i < size; i++) 
			std::cout<<arr[i]<<" "; 
		for (int i = 0; i <= rear; i++) 
			std::cout<<arr[i]<<" "; 
		std::cout<<std::endl;
	} 
} 


int main() 
{ 
	Ring_Buffer q(3); 

	q.addElement(14); 
	q.addElement(22); 
	q.addElement(13); 
	q.display();
	q.addElement(5);
	q.display();
	q.addElement(6);
	q.display();
	q.delete_element();
	q.display();
	q.addElement(7);
	
	q.display(); 
 
	return 0; 
} 

