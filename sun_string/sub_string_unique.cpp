#include<bits/stdc++.h>
using namespace std;

int lcp(string s1,string s2){
	int i;
	for(i=0;i<min(s1.length(),s2.length());i++){
		if(s1[i]!=s2[i]){
			i--;
			break;
		}
	}
	return i+1;
}

int unique_substring(string s){
	vector<pair<string,int>> sub_string;
	int j =0;
	for(int i = s.length()-1;i>=0;i--){
		string ss = "";
		for(int j=0;j<s.length()-i;j++){
			ss += s[i-j];
		}
		reverse(ss.begin(),ss.end());
		sub_string.push_back(make_pair(ss,j));
		j++;
	}
	sort(sub_string.begin(), sub_string.end());
	int arr_lcp[s.length()];
	arr_lcp[0] = 0;
	int sum = 0;
	for(int i=1;i<s.length();i++){
		arr_lcp[i] = lcp(sub_string[i].first,sub_string[i-1].first); 
		sum += arr_lcp[i];
	}
	return ((s.length()*(s.length()+1)/2) - sum);
}

int main(){
	cout<<unique_substring("AZAZA");
}