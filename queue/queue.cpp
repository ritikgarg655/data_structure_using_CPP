#include<bits/stdc++.h>
using namespace std;
// Implementation using single linked list.

template<typename T> struct node{
	T data;
	node* next_Add;
} ;

template<class T> class queue_using_single_linked_list{
	private:
		node<T> *head;
		node<T> *tail;	
	public:
		queue_using_single_linked_list(){
			head = NULL;
			tail = NULL;
		}

		void enqueue(T value){
			node<T>* new_node = (node<T>*)malloc(sizeof(node<T>));
			new_node->data = value;
			new_node->next_Add = NULL;
			if(head==NULL)
				head = new_node;
			else {
				head->next_Add = new_node;
				head = new_node;
			}
			if(tail == NULL){
				tail = new_node;
			}
		}

		T dequeue(){
			if(tail==NULL){
				cout<<"No value present, returning garbage value."<<endl;
				T a;
				return a;
			}
			node<T>* temp = tail;
			T value = tail->data;
			tail = tail->next_Add;
			free(temp);
			return value;
		}

		int size(){
			int len = 0;
			node<T>* temp = tail;
			while(temp!=NULL){
				temp = temp->next_Add;
				len++;
			}
			return len;
		}
};


int main(){
	queue_using_single_linked_list<int> q;
	q.enqueue(4);
	q.enqueue(6);
	cout<<"SIZE: "<<q.size()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<"SIZE: "<<q.size()<<endl;
}