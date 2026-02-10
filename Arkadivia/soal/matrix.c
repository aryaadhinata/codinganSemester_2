#include <stdio.h>
#include <string.h>

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    char str[n];
    scanf("%s", str);

    int count0 = 0, count1 = 0 ;
    for(int i = 0; i < n; i++){
        if(str[i] == '0'){
            count0++;
        }
        if(str[i] == '1'){
            count1++;
        }
    }

    if(count0 == count1){
        printf("%d", ((n/2) * k));
    }else{
        printf("%d", 0);
    }
    return 0;
}