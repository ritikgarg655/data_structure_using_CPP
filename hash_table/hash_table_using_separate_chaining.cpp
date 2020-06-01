#include<bits/stdc++.h>
using namespace std;

class hash_table{
private:
	int max_capacity;
	int hash_fun(string s,int value1){
		return (s.length()+value1)%max_capacity;
	}
	vector<vector<pair<string,int>>> table;
	int size;
	float alpha;
	void increse_size(){
		max_capacity = 2*max_capacity;
		vector<pair<string,int>> temp;
		vector<vector<pair<string,int>>> new_table(max_capacity,temp);
		for(int i=0;i<max_capacity/2;i++){
			new_table[i] = table[i];
		}
		table = new_table;
	}
public:
	hash_table(int capacity = 3){
		max_capacity = capacity;
		vector<pair<string,int>> temp;
		vector<vector<pair<string,int>>> new_table(max_capacity,temp);
		table = new_table;
		size = 0;
		alpha = 0.8;
	}
	void insert(string key,int value1){
		if(present(key,value1)){
			return;
		}
		int index = hash_fun(key,value1);
		if(size+1>=(max_capacity*alpha)){
			increse_size();
		}
		table[index].push_back(make_pair(key,value1));
		size++;
	}
	bool present(string key,int value1){
		int index = hash_fun(key,value1);
		auto it = table[index].begin();
		if(find(table[index].begin(),table[index].end(),make_pair(key,value1))!=table[index].end())
			return true;
		return false;
	}

};

int main(){
	hash_table ht;
	ht.insert("a",2,3);
	ht.insert("a",2,1);
	ht.insert("b",6,3);
	ht.insert("c",4,3);
	ht.insert("d",2,6);
}