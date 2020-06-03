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

string lcp_string(string s1,string s2){
	int i;
	string ans = "";
	// cout<<s1<<" "<<s2<<endl;
	for(i=0;i<min(s1.length(),s2.length());i++){
		if(s1[i]!=s2[i]){
			i--;
			break;
		}
		ans += s1[i];
	}
	// for(int j=0;j<=i;j++){
	// 	ans = ans + s1[i];
	// }
	// cout<<ans;
	return ans;
}

string lsr(string s){
	vector<pair<string,int>> sub_string;
	int j =0;
	for(int i = s.length()-1;i>=0;i--){
		string ss = "";
		for(int j=i;j<s.length();j++){
			ss += s[j];
		}
		// reverse(ss.begin(),ss.end());
		sub_string.push_back(make_pair(ss,j));
		j++;
	}
	sort(sub_string.begin(), sub_string.end());
	int arr_lcp[s.length()];
	arr_lcp[0] = 0;
	int max = 0;
	string ans ;
	for(int i=1;i<sub_string.size();i++){
		arr_lcp[i] = lcp(sub_string[i].first,sub_string[i-1].first); 
		// cout<<sub_string[i].first<<" "<<arr_lcp[i]<<endl;
		if(max<=arr_lcp[i]){
			max = arr_lcp[i];
			ans = lcp_string(sub_string[i].first,sub_string[i-1].first);
			// cout<<max<<ans;
		}
	}
	return ans;
}

int main(){
	cout<<lsr("ABABBAABAA");
}