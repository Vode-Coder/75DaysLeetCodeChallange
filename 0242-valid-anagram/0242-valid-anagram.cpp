class Solution {
public:
    bool isAnagram(string s, string t) {
        int sl = s.length();
        int tl = t.length();
        if (sl != tl) {
            return false;
        }
        int arr[26] = {0};
        for (int i = 0; i < sl; i++) {
            arr[s[i] - 'a']++;
        }
        for (int i = 0; i < tl; i++) {
            arr[t[i] - 'a']--;
            if (arr[t[i] - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};