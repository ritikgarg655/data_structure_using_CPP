#include<bits/stdc++.h>
using namespace std;

int main(){
	// syntax: array<type,size> name = {value};
	array<int,2> arr = {1,2};
	cout<<"Array size: "<<arr.size()<<endl;

	cout<<"Printing array: ";
	for(auto it:arr){
		cout<<it<<" ";
	}
	cout<<endl;

	// Better than this is to use vector
	vector<int> v(5,0); // size: 5 ,value: 0
	cout<<"Size of vector:"<<v.size()<<endl;
	// Also indexing is allowed
	cout<<"Value at index 0:"<<v[0]<<endl;
}