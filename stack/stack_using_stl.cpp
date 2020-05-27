#include<bits/stdc++.h>
using namespace std;

int main(){
	stack <int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	cout<<"Size: "<<s.size()<<endl;
	s.pop();
	cout<<"Size: "<<s.size()<<endl;
	cout<<"S.top: "<<s.top()<<endl;
	cout<<"S.size: "<<s.size()<<endl;
	cout<<"s.empty: "<<s.empty()<<endl;
}