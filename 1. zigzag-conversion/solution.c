#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *solution(char *s, int numRows);

int main() {
    char *test = "PAYPALISHIRING";
    char *t=solution(test, 3);
    char *t2=solution(test, 4);
    char *t3=solution("A", 1);
    printf("%s\n", t);
    printf("%s\n", t2);
    printf("%s\n", t3);

    free(t);
    free(t2);
    // free(t3);

}

char *solution(char *s, int numRows) {
    if (numRows == 1) {
        return s;
    }

    size_t len = strlen(s);
    int id = 0;
    printf("%d||%d\n",len,sizeof(char));
    char *res = (char *)malloc(sizeof(char) * (len+1));
    if (!res) {
        return NULL;
    }

    for (int i = 0; i < numRows; i++) {
        int pos = i;
        int adder = (numRows - i - 1) * 2;
        if (adder == 0) {
            adder = (numRows - 1) * 2;
        }

        int toggle = 1;

        while (pos < len) {
            res[id] = s[pos];
            id++;
            pos += adder;

            if (i > 0 && i < numRows - 1) {
                if (toggle) {
                    adder = i * 2;
                } else {
                    adder = (numRows - i - 1) * 2;
                }
                toggle = !toggle;
            }
        }
    }

    printf("%d\n",id);
    res[len]='\0';

    return res;
}