#include<bits/stdc++.h>
using namespace std;

class hash_table{
private:
	vector<pair<string,int>> table;
	int size;
	int max_capacity;
	float alpha = 0.35;
	int next_prime(int num){
		if(num==1){
			return 2;
		}if(num==2){
			return 3;
		}
		for(int i=5;1;i = i+6){
			if(i>num)
				return i;
			if(num<i+2)
				return i+2;
		}
	}
	int hash_fun(string s,int value1){
		return (s.length()+value1)%max_capacity;
	}
	int double_hash_fun(string s){
		return s.length()%max_capacity;
	}
	int double_porb(int x,string k){
		return x * ((double_hash_fun(k)>0)?double_hash_fun(k):1);
	}
	void increse_size(){
		int prev_size = max_capacity;
		max_capacity = next_prime(max_capacity);
		pair<string,int> t;
		vector<pair<string,int>> new_table(max_capacity,t);
		for(int i=0;i<prev_size;i++){
			int index = hash_fun(table[i].first,table[i].second);
			int x = 0;
			pair<string,int> t;
			while(table[index]!=t){
				index = index+double_porb(x,table[index].first);
				x++;
			}
			new_table[index] = table[i];
		}
		table = new_table;
	}
public:
	hash_table(){
		size = 0;
		max_capacity = 4;
		pair<string,int> t;
		vector<pair<string,int>> new_table(3,t);
		table = new_table;
	}
	void insert(string key,int value1){
		if(present(key,value1)){
			return;
		}
		if((size+1)>=floor(max_capacity*alpha)){
			increse_size();
		}
		int index = hash_fun(key,value1);
		int x = 1;
		pair<string,int> t;
		while(table[index]!=t){
			index = index+double_porb(x,table[index].first);
			x++;
		}
		table[index] = make_pair(key,value1);
		size++;
	}
	bool present(string key,int value1){
		int index = hash_fun(key,value1);
		pair<string,int> t;
		if(table[index]!=make_pair(key,value1))
			return true;
		return false;
	}
};

int main(){
	hash_table ht;
	ht.insert("dssss",45);
	ht.insert("dssss",4345);
	ht.insert("dssss",445);
	ht.insert("dsss",445);
	ht.insert("dss",455);
	ht.insert("sss",415);
	cout<<ht.present("dssss",4345);
}