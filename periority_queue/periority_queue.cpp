#include<bits/stdc++.h>
using namespace std;
// min periority queue
template<class T> class periority_queue{
private: 
	vector<T> binary_tree;
	int last_node; // index of last node.x`
	// Hash for removing in O(logn)
	map<T,vector<int>> hash; // value, array of index

public:
	void swim(int &curr_index){
		// bubble up
		// int curr_index = binary_tree.size()-1;
		while(curr_index>0){
			int parent_index = (((curr_index-1)/2)%1==0)?((curr_index-1)/2):((curr_index-2)/2);
			if(binary_tree[parent_index]>binary_tree[curr_index] and parent_index>=0){
				// swaping
				T temp = binary_tree[parent_index];
				binary_tree[parent_index] = binary_tree[curr_index];
				binary_tree[curr_index]  = temp;
				curr_index = parent_index;
			}
			else{
				// cout<<curr_index<<endl;
				break;
			}
		}
	}
	void sink(int &curr_index){
		int child_index = binary_tree.size();
		if((curr_index*2+1) < binary_tree.size()){
			child_index = (curr_index*2+1);
		}
		else{
			return;
		}
		while(curr_index<binary_tree.size()){
			// cout<<curr_index<<binary_tree.size();
			if(binary_tree[child_index]<binary_tree[curr_index]){
				// swaping
				// cout<<curr_index;
				T temp = binary_tree[child_index];
				binary_tree[child_index] = binary_tree[curr_index];
				binary_tree[curr_index]  = temp;
				curr_index = child_index;
				child_index = (curr_index*2+1);
			}
			else if(binary_tree[child_index]<binary_tree[curr_index+1] and curr_index+1<binary_tree.size()){
				// swaping
				T temp = binary_tree[child_index+1];
				binary_tree[child_index+1] = binary_tree[curr_index];
				binary_tree[curr_index]  = temp;
				curr_index = child_index+1;
				child_index = (curr_index*2+1);
			}
			else{
				break;
			}
		}
	}
	void enqueue(T value){
		binary_tree.push_back(value);
		int index = binary_tree.size()-1;
		swim(index);
	}
	T dequeue(){
		T value  = binary_tree[0];
		binary_tree[0] = binary_tree[binary_tree.size()-1];
		binary_tree.pop_back();
		int index = 0;
		sink(index);
		cout<<index;
		return value;
	}
	T dequeue_index(int index){
		if(index>=binary_tree.size() or index<0){
			cout<<"Index out off bound."<<endl<<"Returning garbage value"<<endl;
			T gar;
			return gar;
		}
		T value = binary_tree[index];
		binary_tree[index] = binary_tree[binary_tree.size()-1];
		binary_tree.pop_back();
		int temp_index = index;
		swim(index);
		if(temp_index==index){
			sink(index);
		}
		return value;
	}
	int size(){
		return binary_tree.size();
	}
	void print(){
		cout<<"Value: ";
		for(int i=0;i<binary_tree.size();i++){
			cout<<binary_tree[i]<<" ";
		}
		cout<<endl;
	}
	void remove(T value){
		

	}
};

int main(){
	periority_queue<int> pq;
	pq.enqueue(1);
	pq.enqueue(5);
	pq.enqueue(7);
	pq.enqueue(2);
	pq.enqueue(3);
	pq.enqueue(-1);
	pq.print();
	cout<<"Size: "<<pq.size()<<endl;
	cout<<"POP VALUE:"<<pq.dequeue()<<endl;
	pq.print();
	cout<<"Size: "<<pq.size()<<endl;
	// pq.dequeue_index(2);
	pq.print();
	cout<<"Size: "<<pq.size()<<endl;
}