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

		void r_print(int a =0){
			static l_list<type>* temp_add = starting_add;
			if(a==0)
				temp_add = starting_add;
			if(temp_add==0) {cout<<"Print in reverse order:";return;}
			l_list<type>* temp1 = temp_add;
			temp_add = temp_add->add;
			r_print(1);
			cout<<temp1->data<<" ";
			if(temp1==starting_add) cout<<endl;
		}

		void delete_node(int index){
			l_list<type>* temp = starting_add;
			if(index==0){
				starting_add = temp->add;
				free(temp);
				return;
			}
			for(int i=0;i<index;i++){
				// temp = temp->add;
				if(i==index-1){
					l_list<type>* temp1 = temp;
					temp1 = temp->add;
					temp->add = temp1->add;
					free(temp1);
					break;
				}
				temp = temp->add;
			}
		}

		void reverse_list(){
			l_list<type>* temp = 0;
			while(1){
				// starting_add->add = temp;
				l_list<type>* temp1 = 0;
				temp1 = temp;
				temp = starting_add;
				starting_add = starting_add->add;
				temp->add = temp1;
				if(starting_add->add==0){
					starting_add->add = temp;
					break;
				}
				// temp 
				// temp = 
			}
		}

		// reverse using recursion
		void r_revese_list(int a = 0){
			static l_list<type>* temp_add = starting_add;
			static l_list<type>* s_starting_add = starting_add;
			if(temp_add==0) {return;}
			if(a==0){
				temp_add = starting_add;
				s_starting_add = starting_add;
			}
			l_list<type>* temp1 = starting_add;
			l_list<type>* temp2 = temp_add;
			
			starting_add = temp_add;
			temp_add = temp_add->add;
			
			r_revese_list(1);
			
			if(temp2!=s_starting_add)
				temp2->add = temp1;
			else
				temp2->add = 0;
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
	l1.reverse_list();
	l1.add_node(2);	
	l1.print();
	l1.r_print();
	l1.r_revese_list();
	l1.print();
	l1.add_node(1,12);
	l1.add_node(4);
	l1.print();
	l1.r_print();	
}