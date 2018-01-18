#include <bits/stdc++.h>
using namespace std;

int main() {
	int t,i=0,b=0,j;
	cin>>t;
	while(t--) {
	b=0;
	string A;
	cin>>A; 
	i=A.length();
	A+='.';
	A+='\0';
	cout<<A<<endl;
	   
	  vector<string> str(2001);
	    string a="";
	    for(j=0;j<(i+1);j++) {
	        if(A[j]!='.') {
	            a=a+A[j];
	        }
	        else {
	            a+='\0';
	            str[b++]=a;
	            a="";
	        }
	    }
	    b--;
	    cout<<str[b--];
	    while(b>=0) cout<<"."<<str[b--];
	    cout<<endl;
	}
	return 0;
}
