class Solution {
public:
    bool isAnagram(string s, string t) {
       vector<int> freq(26,0),freqT(26,0);
       for(char ch : s){
            freq[ch-'a']++;
       }

       for(char c : t){
            freqT[c-'a']++;
       }

       for(int i=0;i<26;i++){
         if(freq[i]!= freqT[i])
            return false;
       }

        return true;
    }
};
