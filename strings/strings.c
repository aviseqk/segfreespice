#include <stdio.h>

int main()
{
    char name[10] = "Jonathan";
    printf("%s", name);

    char s[11] = "aBOmInAtiOn";
    for(int i=0; i<11; i++) {
        s[i] = (s[i] > 96) ? s[i] - 32 : s[i] + 32;
    }
    printf("toggled string %s\n", s);
    
    // find duplicate chars in a string
    char str[9] = "finnings";
    int hash[26] = {0};
    for(int i=0; i < 9; i++) {
        hash[str[i] - 'a']++;
    }
    for(int i=0; i<26; i++) {
        if(hash[i] > 1)
            printf("char %c was duplicated %d times\n", i + 'a', hash[i]);
    }


    // finding duplicate chars using BITWISE OPERATIONS - MASKING AND MERGING
    int bitarray=0, x;
    char string[10] = "spiciered";
    for(int i=0; i < 10; i++) {
        x = 1;
        x = x << (string[i] - 'a');
        if((bitarray & x) > 0) {
            printf("Duplicate character found %c \n", string[i]);
        } else {
            bitarray = bitarray | x;
        }
    }
}

