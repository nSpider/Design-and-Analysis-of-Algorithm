#include<bits/stdc++.h>

using namespace std;

void find(int *m,string s1,string s2, int n1, int n2,int w,string out){
	if (n1>0 && n2>0){
		if (s1[n1-1]==s2[n2-1]){
			out.push_back(s1[n1-1]);
			find(m,s1,s2,n1-1,n2-1,w,out);
		} else {
			if (m[n1*w+n2]==m[(n1-1)*w+n2])
				find(m,s1,s2,n1-1,n2,w,out);
			if (m[n1*w+n2]==m[n1*w+(n2-1)])
				find(m,s1,s2,n1,n2-1,w,out);
		}
	} else{
		reverse(out.begin(),out.end());
		cout<<out<<"\n";
	}
}

int max(int a,int b){
	return (a > b) ? a : b;
}

int main(){
	string s1,s2;
	cin>>s1;
	cin>>s2;
	int n1 = s1.length();
	n1++;
	int n2 = s2.length();
	n2++;
	int *m = new int[n1*n2];
	for (int i=0;i<n2;i++)
		m[i] = 0;
	for (int i=1;i<n1;i++)
		m[i*n2] = 0;
	for (int i=1;i<n1;i++){
		for (int j=1;j<n2;j++){
			if (s1[i-1] == s2[j-1])
				m[i*n2+j] = m[(i-1)*n2+(j-1)]+1;
			else
				m[i*n2+j] = max(m[(i-1)*n2+j],m[i*n2+(j-1)]);
			cout<<m[i*n2+j]<<" ";
		}
		cout<<"\n";
	}
	string out;
	find(m,s1,s2,n1,n2,n2,out);
	return 0;
}