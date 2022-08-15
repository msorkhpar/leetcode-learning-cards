#include <stdbool.h>

int get_char_index(char character) {
    return character - 'a';
}

bool can_construct(const char *ransomNote, const char *magazine) {
    int hash_table[26] = {0};

    for (int i = 0; magazine[i] != '\0'; i++) {
        int index = get_char_index(magazine[i]);
        hash_table[index]++;
    }
    for (int i = 0; ransomNote[i] != '\0'; i++) {
        int index = get_char_index(ransomNote[i]);
        hash_table[index]--;
        if (hash_table[index] < 0) {
            return false;
        }
    }
    return true;
}