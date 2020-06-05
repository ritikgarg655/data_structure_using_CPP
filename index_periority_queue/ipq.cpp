#include<bits/stdc++.h>
using namespace std;

class ipq{
private:
	int size; // size of tree
	vector<string> hash;
	vector<int> vals; // value acc to ki
	vector<int> pm; // from key value pair to index
	vector<int> im; // from tree index to key value pair
	void sink(int index){
		int left_child = 2*index+1;
		int right_child = 2*index+2;
		while(left_child<size){
			int small = -1;
			if(vals[left_child]<vals[index]){
				small = left_child;
			}
			else if(vals[right_child]<vals[index] and right_child<size){
				small = right_child;
			}
			if(small==-1){
				break;
			}
			swap(small,index);
			index = small;
			left_child = 2*index+1;
			right_child = 2*index+2;
		}
	}
	void swap(int index,int parent){
		pm[im[index]] = index;
		pm[im[parent]] = parent;
		int temp = im[index];
		im[index] = im[parent];
		im[parent ] = temp;
	}
	void swim(int index){
		int parent = (index-1)/2;
		while(parent>=0 and vals[parent]>vals[index]){
			// swap

			index = parent;
			parent = (index-1)/2;

		}
	}
public:
	ipq(){
		size = 0;
	}
	void insert(string key,int val){
	// swap im[val[ki]] and im[vals[ki]]
		// swap pm[ki] and pm[ki]
		if(vals.size()==size){
			vals.push_back(val);
			pm.push_back(size);
			im.push_back(size);
			hash.push_back(key);
		}
		else{
			vals[size]=val;
			pm[size] = size;
			im[size] = size;
			hash[size] = key;			
		}
		size++;
		swim(size-1);
	}
	void remove(int index){
		// index in tree
		int i = pm[index];
		swap(i,size-1);
		size--;
		sink(i);
		swim(i);
		vals[index] = -1;
		pm[index] = -1;
		im[size] = -1;
	}
	void update(int index,int value){
		int i = pm[index];
		vals[index] = value;
		sink(i);
		swim(i);
	}
};

int main(){
	ipq pq;
	pq.insert("abc",1);
	pq.insert("abd",2);
	pq.insert("abe",3);
	pq.insert("abf",4);
	pq.insert("abg",5);
	pq.remove(4);
	pq.update(1,7);
}