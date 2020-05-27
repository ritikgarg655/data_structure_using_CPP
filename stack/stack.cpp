#include<bits/stdc++.h>
using namespace std;

// implementation using single linked list.
// Head pointer will point to last element.
// Only able to delete and insert at last i.e. at pointing at head.

template< typename T>  struct node{
	T data;
	node *prev_add ; 
};

template<class T> class stack_using_single_linked_list{
	private:
		node<T>* head;
	public:
		stack_using_single_linked_list(){
			head = NULL;
		}
		void push(T value){
			node<T>* new_node = (node<T> *)malloc(sizeof(node<T>));
			new_node->data = value;
			new_node->prev_add = head;
			head = new_node;
		}

		T pop(){
			if(head==NULL){
				cout<<"No value present, return garbage value."<<endl;
				T a; // return garbage value.
				return a;
			}
			T value = head->data;
			node<T>* temp_head = head;
			head = head->prev_add;
			free(temp_head);
			return value;
		}

		int size(){
			int len = 0;
			node<T>* temp = head;
			while(temp!=NULL){
				len++;
				temp = temp->prev_add;
			}
			return len;
		}
};

int main(){
	stack_using_single_linked_list<int> s;
	s.push(1);
	s.push(2);
	cout<<s.pop()<<endl;
	cout<<s.size()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.size()<<endl;
}