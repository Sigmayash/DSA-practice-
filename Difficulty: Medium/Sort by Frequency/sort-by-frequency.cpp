class Solution {
  public:
    string frequencySort(string &s) {
          unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        vector<char> chars;
        unordered_set<char> seen;
        for (char c : s) {
            if (!seen.count(c)) {
                seen.insert(c);
                chars.push_back(c);
            }
        }

        stable_sort(chars.begin(), chars.end(), [&](char a, char b) {
            if (freq[a] == freq[b]) return a < b;
            return freq[a] < freq[b];
        });

        string result = "";
        for (char c : chars) {
            result += string(freq[c], c);
        }
        return result;
    }
};