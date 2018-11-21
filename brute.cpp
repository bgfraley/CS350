#include "Algorithms.h"

void brute(string pattern, string text) {
    int text_i = 0;
    int pat_i = 0;
    int text_len = text.length();
    int pat_len = pattern.length();
    int stop_i = text_len - pat_len;

    while (text_i < stop_i) {
        while (text[text_i] == pattern[pat_i]) {
            if (pat_i == pat_len-1) {
                cout << "Success at " << text_i - pat_i << endl;
                return;
            }
            ++text_i;
            ++pat_i;
        }
        ++text_i;
        pat_i = 0;
    }
    if (text_i + pat_i > text_len) cout << "We have failed you, sorry master!" << endl;
    return;
    
}