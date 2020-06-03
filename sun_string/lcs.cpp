#include<bits/stdc++.h>
using namespace std;
// program to find longest common substring among l string with minimum k occurence.

int lcp(string s1,string s2){
	int i;
	for(i=0;i<min(s1.length(),s2.length());i++){
		if(s1[i]!=s2[i] or s1[i] == '#' or s2[i]=='#'){
			i--;
			break;
		}
	}
	return i+1;
}

int lcs(int size,string s_set[],int k){
	string s ;
	for(int i=0;i<size;i++){
		s += s_set[i];
		s += "#";
		// cout<<s<<endl;
	}
	vector<pair<pair<string,int>,int>> sub_string;
	int j =0;
	int string_num = size;
	for(int i = s.length()-1;i>=0;i--){
		string ss = "",cm = "#";
		if(s[i] == '#'){
			string_num--;
			continue;
		}
		for(int j=i;j<s.length();j++){
			ss += s[j];
		}
		// /reverse(ss.begin(),ss.end());
		// cout<<ss<<" ";
		sub_string.push_back(make_pair(make_pair(ss,j),string_num));
		j++;
	}
	sort(sub_string.begin(), sub_string.end());
	int arr_lcp[s.length()];
	arr_lcp[0] = 0;	
	int sum = 0;
	for(int i=1;i<sub_string.size();i++){
		arr_lcp[i] = lcp(sub_string[i].first.first,sub_string[i-1].first.first); 
		// cout<<sub_string[i].first.first<<" "<<arr_lcp[i]<<endl;
	}
	int strat = 0;
	int last = 0;
	int ans = 0 ;
	// cout<<sub_string.size();
	while(last<sub_string.size()){
		// cout<<last;
		// last++;
		int present = 0;
		bool visited[size] = {false};
		int min_lcp = INT_MAX;
		for(int i = strat ; i <= last ; i++){
			if(!visited[sub_string[i].second]){
				present++;
				visited[sub_string[i].second] = true;
			}
			// cout<<sub_string[i].second<<" ";
			if(i!=strat and arr_lcp[i]<min_lcp ){
				min_lcp = arr_lcp[i];
			}
		}
		// cout<<min_lcp;
		if(present>=k){
			if(ans<min_lcp){
				ans = min_lcp;
			}
			strat++;;
		}
		else
		{
			last++;
		}
	}
	return ans;
}

int main(){
	string s[4] = {"aabc","bcdc","bcde","cded"};
	cout<<lcs(4,s,2);
	return 0;
}