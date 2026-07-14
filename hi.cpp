#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string reverseWords(string s){
    string ans;
    int n=s.size();
    int count=0;
    
    for(int i=0; i<n; i++){
        if(s[i]==' ' && count==0){
            ans+=s[i];
            count++;
        }
        else if(s[i]!=' '){
            ans+=s[i];
            count=0;

        }
    }
// if zero index has blank space
    if(ans[0]==' ') 
        ans = ans.substr(1);
// if last index has blank space 
    if(!ans.empty() && ans[ans.size()-1]==' ') //
        ans.pop_back();
        n=ans.size();
        s.clear();
        
// Reverse the Whole string
for(int i=n-1; i>=0; i--){
s+=ans[i];
}

// Reverse Each Word
string temp;
n=s.size();
ans.clear();
for(int i=0; i<n; i++){
    
    if(s[i]==' '){
        reverse(temp.begin(), temp.end());
        
        ans+=temp;
        ans+=' ';
        temp.clear();
    }
temp+=s[i];

}
reverse(temp.begin(), temp.end());
    return ans+temp;
}
int main(){
system("cls");

cout<<reverseWords("  Hello World  ");
cout<<"\nHello World";
return 0;
}