#include <cstdio>
#include <cstring>

int main() {
  int t;
  char str[100001];
  scanf("%d", &t);
  int len, res, k, j;
  while(t--) {
    len = res = 0;
    scanf("%s", &str);
    for(int i = 0; str[i] != '\0'; i++) {
      len++;
      k = 0;
      for(j=i+1; str[j] != '\0'; j++) {
        if(str[j] == str[k]){
          res++;
          k++;
        }
        else
          break;
      }
    }
    printf("%d\n", res+len);
  }
  return 0;
}
