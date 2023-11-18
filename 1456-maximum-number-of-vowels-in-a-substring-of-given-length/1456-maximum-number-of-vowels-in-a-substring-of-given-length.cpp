class Solution {
public:
    int maxVowels(string s, int k) {
        
        int maxVow = 0;
        int currVow = 0;
        
        for(int i = 0; i < k; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i'|| s[i] == 'o' || s[i] == 'u'){
                currVow++;
            }
        }
            
        maxVow = currVow;
        
        int i = 0; int j = k;
        
        while(j < s.length()){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i'|| s[i] == 'o' || s[i] == 'u'){
                currVow--;
            }
            if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i'|| s[j] == 'o' || s[j] == 'u'){
                currVow++;
            }
            if(currVow > maxVow){
                maxVow = currVow;
            }
            i++; j++;
        }
        
        
        return maxVow;
    }
};