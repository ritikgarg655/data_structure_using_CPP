#include<bits/stdc++.h>
using namespace std;

class fenwick_t{
private:
	int *tree;
	int size;

	int lsb(int v){
		return v & (-v);
	}

public:
	fenwick_t(int size){
		tree = (int *)malloc(sizeof(int)*size);
		tree = new int[size];
		this->size = size;
	}
	fenwick_t(int v[],int size){
		tree = new int(*v);
		this->size = size;
	}
	long int prefix_sum(int index){
		long int sum = 0LL;
		while(index>=0){
			sum += tree[index];
			index -= lsb(index+1);
		}
		return sum;
	}

	long int range_sum(int start_index,int end_index){
		long int sum =0;
		return prefix_sum(end_index) - prefix_sum(start_index-1);
	}

	void add(int index,int value){
		while(index<size){
			tree[index]+= value;
			index += lsb(index+1);
		}
	}
};

int main(){
	fenwick_t t(5);
	t.add(0,5);
	t.add(1,6);
	t.add(2,7);
	t.add(3,8);
	t.add(4,9);
	cout<<t.prefix_sum(4)<<endl;
	cout<<t.range_sum(0,4)<<endl;
	t.add(0,5);
	t.add(1,6);
	t.add(2,7);
	t.add(3,8);
	t.add(4,9);
	cout<<t.prefix_sum(4)<<endl;
	cout<<t.range_sum(0,4)<<endl;
}