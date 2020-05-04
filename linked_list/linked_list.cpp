#include<bits/stdc++.h>
using namespace std;

template <typename T> struct l_list
{
	T data;
	l_list* add;
};

template <class type> class linked_list{
	private:
		l_list<type>* starting_add;
	public:
		linked_list(type value){
			l_list<type>* temp = (l_list<type>*) malloc(sizeof(l_list<int>));
			temp->data = value;
			starting_add = temp;
		}	

		void add_node(type value){
			l_list<type>* temp = (l_list<type>*) malloc(sizeof(l_list<int>));
			temp->data = value;
			temp->add = 0;
			l_list<type>* temp1 = starting_add;
			while(1){
				if(temp1->add==0) {
					temp1->add = temp;
					break;
				}
				temp1 = temp1->add;
			}
		}

		void add_node(int index,type value){
			l_list<type>* temp = (l_list<type>*) malloc(sizeof(l_list<int>));
			temp->data = value;
			temp->add = 0;
			l_list<type>* temp1 = starting_add;
			int i;
			for(i=0;i<index;i++){
				if(i==index-1) {
					temp->add = temp1->add;
					temp1->add = temp;
					break;
				}
				temp1 = temp1->add;
			}

		}
		void print(){
			l_list<type>* temp = starting_add;
			cout<<"Printing data: ";
			while(1){
				cout<<temp->data<<" ";
				if(temp->add==0) {
					// *temp1.add = temp;
					break;
				}
				temp = temp->add;
			}
			cout<<endl;
		}

		void delete_node(int index){
			l_list<type>* temp = starting_add;
			if(index==0){
				starting_add = temp->add;
			}
			for(int i=0;i<index;i++){
				// temp = temp->add;
				if(i==index-1){
					l_list<type>* temp1 = temp;
					temp1 = temp->add;
					temp->add = temp1->add;
					break;
				}
				temp = temp->add;
			}

		}
};

int main(){
	linked_list<int> l1(1);
	l1.add_node(2);
	l1.add_node(3);
	l1.add_node(1,12);
	l1.add_node(4);
	l1.print();
	l1.delete_node(0);
	l1.print();
}