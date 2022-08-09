#set($Method =${Method_name.replaceAll("([a-z])([A-Z]+)","$1_$2").toLowerCase()} )
#[[#include]]# <stdio.h>

int ${Method}(int *input, int len) {
    int result = 0;
    for (int i = 0; i < len; i++) {
        printf(input[i]);
    }
    return result;
}
