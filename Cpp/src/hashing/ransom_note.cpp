#include <unordered_map>
#include "ransom_note.h"

using namespace std;

//https://leetcode.com/problems/ransom-note/discuss/1567023/Easy-C++-HashMap-solution/1267627
bool RansomNote::CanConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> map;
    for (auto character: magazine) {
        map[character]++;
    }
    for (auto character: ransomNote) {
        if (--map[character] < 0)
            return false;
    }
    return true;
}
