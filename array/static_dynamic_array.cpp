#include<bits/stdc++.h>
using namespace std;

// Dynamic array class
template <class type> class Array{
	private:
		size_t m_size;
		size_t m_capacity;
		type* m_data;
		void resize(){
			size_t capacity = m_capacity*2;
			type* temp = (type*)realloc(m_data,capacity*sizeof(*m_data));
			m_data = temp;
			m_capacity = capacity;
		}

	public:
		Array(){
			m_size = 0;
			m_capacity = 1;
			m_data = (type*)malloc(m_capacity * sizeof(*m_data));
		}

		~Array(){
			free(m_data);
		}
		
		// Function to change value of specified index. 
		void set(size_t index, type value){
				if(index>=m_size) 
					cout<<"Size out of range.\n";
				else 
					*(m_data + index) = value;
		}
		
		void push(type value){
			if(m_size>=m_capacity){
				resize();
			}
			*(m_data + m_size) = value;
			m_size++;
		}
		
		type pop(){
			type temporary = *(m_data + m_size - 1);
			m_size--;
			return  temporary;
		}

		type get(size_t index){
			return *(m_data + index);
		}

		size_t size(){
			return m_size;
		}
		size_t capacity(){
			return m_capacity;
		}

		void print(){
			size_t i = 0;
			cout<<"Printing array : ";
			while(i<m_size){
				cout<<this->get(i)<<" ";
				i++;
			}
			cout<<endl;
		}

		int is_empty(){
			return m_size==0;
		}
};


int main(){
	cout<<"Init static array..."<<endl;
	int size;
	cout<<"Enter size of static array: ";
	cin>>size;

	// init static array
	Array<int> arr;
	arr.push(1);
	arr.push(1);
	arr.push(1);
	arr.push(1);

	cout<<"Size of array: "<<arr.size()<<endl;
	cout<<"Capacity of array: "<<arr.capacity()<<endl;
	cout<<"Value at index 0: "<<arr.get(0)<<endl;
	cout<<"Poped value: "<<arr.pop()<<endl;
	arr.print();
}