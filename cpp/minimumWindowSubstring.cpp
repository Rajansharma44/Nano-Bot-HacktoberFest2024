#include<bits/stdc++.h>
using namespace std;

// With the help of array instead of map //
string smallestWindow (string s, string t)
    {
        // Your code here
            // unordered_map<char,int>mp;
        vector<int>arr(26 , 0);
        
        for(auto v:t){
            arr[v - 97]++;
        }
        
        for(int i = 0 ; i < 26 ; i++){
            
            if(arr[i] == 0){
                arr[i] = INT_MAX;
            }
            
        }
        
        
        
        int cnt = t.size();
    
        int i = 0 ; 
        int j = 0;
        int ans = INT_MAX;
        string finalAns = "-1";
    
        while(j < s.size()){
    
            char ch = s[j];
    
            if(arr[ch - 97] != INT_MAX){
    
                if(arr[ch - 97] > 0) cnt--;
                    arr[ch - 97] -= 1;
    
            }
    
            
    
            while(cnt == 0){
                
                int length = j - i + 1; 
                // ans = min(j - i + 1 , ans);
                
                if(ans > length){
                    ans = length;
                    finalAns = s.substr(i , length);
                }
    
                char c = s[i];
    
                if(arr[c - 97] != INT_MAX){
    
                    arr[c - 97]++;
    
                    if(arr[c - 97] > 0){
                        cnt++;
                    }
                        
                }
    
                i++;
    
            }
    
            j++;
            
        }
    
        return finalAns;
    }

int solve(string s , string t){

    unordered_map<char,int>mp;

    for(auto v:t){
        mp[v]++;
    }

    int cnt = t.size(); // considering the duplicate element also
    // cnt = mp.size() -> not considering duplicate element 

    int i = 0 ; 
    int j = 0;
    int ans = INT_MAX;

    while(j < s.size()){

        char ch = s[j];

        if(mp.find(ch) != mp.end()){

            if(mp[ch] > 0) cnt--;
            mp[ch] -= 1;

        }

        

        while(cnt == 0){

            ans = min(j - i + 1 , ans);

            char c = s[i];

            if(mp.find(c) != mp.end()){

                mp[c]++;

                if(mp[c] > 0){
                    cnt++;
                }
                    
            }

            i++;

        }

        j++;
        
    }

    return ans;
}

int main(){

    cout<<smallestWindow("timetopractice" , "toc")<<endl;
    cout<<solve("timetopractice" , "toc")<<endl;
    return 0;
}