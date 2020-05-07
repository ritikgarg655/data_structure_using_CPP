#include<bits/stdc++.h>
using namespace std;

template<typename T> struct double_l_list
{
	double_l_list* prev_add ;
	T data;
	double_l_list* next_add ;
};

template<class type> class d_list{
	private:
		double_l_list<type>* base_add;
	public:
		d_list(type value){
			double_l_list<type>* temp = (double_l_list<type>*) malloc(sizeof(double_l_list<type>));
			temp->data = value;
			temp->prev_add = 0;
			temp->next_add = 0;
			base_add = temp;
		}

		void add_node(type value){
			double_l_list<type>* temp = base_add;
			double_l_list<type>* temp_prev_add = base_add;
			while(1){
				temp_prev_add = temp;
				if(temp->next_add !=0){
					temp = temp->next_add;
				}
				else{
					break;
				}
			}
			double_l_list<type>* new_node = (double_l_list<type>*) malloc(sizeof(double_l_list<type>));
			temp->next_add = new_node;
			new_node->prev_add = temp_prev_add;
			new_node->data = value;
			new_node->next_add = 0;
		} 

		void print(){
			double_l_list<type>* temp = base_add;
			cout<<"Printing data: ";
			while(1){
				cout<<temp->data<<" ";
				if(temp->next_add == 0) break;
				temp = temp->next_add;
			}	
			cout<<endl;
		}

		void rev_print(){
			double_l_list<type>* temp = base_add;
			cout<<"Reverse printing data: ";
			while(1){
				// cout<<temp->data<<" ";
				if(temp->next_add == 0) break;
				temp = temp->next_add;
			}	
			while(1){
				cout<<temp->data<<" ";
				if(temp->prev_add == 0) break;
				temp = temp->prev_add;
			}
			cout<<endl;			
		}

		void deleting_node(int index){
			double_l_list<type>* temp = base_add;
			int count = 1;
			if(index==0){
				if(temp->next_add !=0){
					(*(temp->next_add)).prev_add = 0;
					base_add = temp->next_add;
					return;
				}
				else{
					cout<<"At least their should one node present."<<endl;
					return;
				}
			}
			while(1){
				if(temp->next_add == 0) break;
				if(count==index){
					(*(temp->prev_add)).next_add = temp->next_add;
					return;	
				}
				temp = temp->next_add;
				count++;
			}	
		}

};

int main(){
	d_list<int> d_l(1);
	d_l.add_node(2);
	d_l.add_node(3);
	d_l.add_node(4);
	d_l.add_node(5);
	d_l.add_node(6);
	d_l.print();
	d_l.rev_print();
	d_l.deleting_node(2);
	d_l.print();		
}	