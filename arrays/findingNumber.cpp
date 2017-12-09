#include <bits/stdc++.h>
#include <vector>
using namespace std;
int binsearch(vector<int>*,int,int,int);
int binsearch1(vector<int>*,int,int,int);
int main() {
	
	int t,n,x,i,maxele,pos=0,r,k;
	cin>>t;
	while(t--) {
	    cin>>n;
	    cin>>x;
	    vector<int> v(n);
	    for(i=0;i<n;i++) {
	        cin>>v[i];
	    }
	    
	    for(i=1;i<n;i++) {
	        
	        if(v[i]<v[i-1] && v[i]>v[i+1]) {
	           maxele=v[i];
	           pos=i;
	           break;
	        }
	        
	        else if(v[i-1]>v[i]) {
	          maxele=v[i-1];
	          pos=i-1;
	          break;
	        }
	        
	        else if(v[i-1]<v[i]) {
	            maxele=v[i];
	            pos=i;
	        }
	    }
	    
	    
	        r=binsearch(&v,0,pos,x);
	        if(r==-1) {
	            k=binsearch1(&v,pos+1,n-1,x);
	            if(k==-1)
	            cout<<"OOPS! NOT FOUND"<<endl;
	            else cout<<k<<endl;;
	        }
	        
	        else cout<<r<<endl;
	    
	    
	    
	}

	
	return 0;
}


int binsearch(vector<int>* v,int l,int h,int x) {
    int mid,p=-1;
    while(l<=h) {
        mid=(l+h)/2;
        if(x==(*v)[mid]) {
          return(mid);
        
        }
         
        else if(x<(*v)[mid]) {
            h=mid-1;
        } 
        
        else if(x>(*v)[mid]) {
            l=mid+1;
        }
    }
    return -1;
}

int binsearch1(vector<int>* v,int l,int h,int x) {
    int mid,p=-1;
    while(l<=h) {
        mid=(l+h)/2;
        if(x==(*v)[mid]) {
          return(mid);
        
        }
         
        else if(x<(*v)[mid]) {
           l=mid+1; 
        } 
        
        else if(x>(*v)[mid]) {
            h=mid-1;
        }
    }
    return -1;
}
