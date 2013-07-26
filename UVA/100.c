#include <stdio.h>

int table[1000001];

int findMaxCycle(int a, int b) {
        int max = 1;
        int i;
        int length;
        int value;
        for(i=a; i<=b; i++) {
                length = 1;
                value = i;
                while(value > 1) {
                        if(value<1000000 && table[value]) {
                                length += table[value]-1;
                                break;
                        }
                        if(value & 1)
                                value = (value<<1) + value + 1;
                        else
                                value = value>>1;
                        length++;
                }
                table[i] = length;
                if(length>max)
                        max = length;
        }
        return max;
}

int main() {
        int a, b;
        while(scanf("%d %d", &a, &b) != EOF) {
                if(a<b)
                        printf("%d %d %d\n", a, b, findMaxCycle(a, b));
                else
                        printf("%d %d %d\n", a, b, findMaxCycle(b, a));
        }
        return 0;
}
