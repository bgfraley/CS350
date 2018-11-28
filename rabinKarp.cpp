#include "Algorithms.h"

//worst-case time is O(nm).
//d is the size of the alphabet to test.
long * rabinKarp(string * pattern, string * source, int q, int d){
    int pLength = pattern->length();
    int sLength = source->length();
    int p = 0; //hash value of pattern string.
    int s = 0; //hash value of source string.
    int h = 1; //d^(s-1)
    int count = 0;
    static long r[1];

    //Computing hash of h.
    for(int i = 0; i < pLength - 1; i++){
        h = (h * d) % q;
    }

    //Computing hashes of pattern and source strings.
    for(int i = 0; i < pLength; i++)
    {
        p = (d * p + pattern->at(i)) % q;
        s = (d * s + source->at(i)) % q;
    }

    //Matching loop.
    for(int i = 0; i <= sLength - pLength; i++){
        ++count;
        if(p==s){//We have found a match.
            int j=0;
            for(j = 0; j < pLength; j++){ //Check the length of the string for mismatches.
                ++count;
                if(source->at(i + j) != pattern->at(j))
                    break;
            }
            if(j == pLength){//Pattern fully matched.
                r[0] = i;
                r[1] = count;
                return r;
            }
        }
        if(i < (sLength - pLength)){//Are we still in bounds? Then get next hash.
            s = (d * (s - source->at(i) * h) + source->at(i+pLength))%q;
            if(s < 0)//If s is now negative, make positive.
                s = s + q;
        }
    }

    r[0] = -1;
    r[1] = count;
    return r;
}
