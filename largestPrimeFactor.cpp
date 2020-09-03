#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
 {
     
     int t;
     cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        while(n%2==0){
            
            n=n/2;
        }
        
        int largest=2;
        
        for(int i=3;i*i<=n;i+=2){
            
            if(n%i==0){
                
                while(n%i==0){
                    
                    n=n/i;
                }
                
                if(i>largest)
                largest=i;
            }
        }
        
        if(n>2 && n>largest)
        largest=n;
        
        cout<<largest<<"\n";
    }
	//code
	return 0;
}