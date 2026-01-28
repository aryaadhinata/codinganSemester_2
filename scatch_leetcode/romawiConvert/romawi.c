#include <stdio.h>
#include <string.h>

int main(){
    char s[128];
    scanf("%s", s);
    int idx = strlen(s);
    int result = 0, ceck = 0, count = 1;

    for(int i = 0; i < idx; i++){
        if(s[i] == 'M' || 'D' || 'C' || 'L' || 'X' || 'V' || 'I'){
            if(i == 0){
                int temp0 = 0;
                switch (s[i]){
                    case 'M' : temp0 = 1000; break;
                    case 'D' : temp0 = 500; break;
                    case 'C' : temp0 = 100; break;
                    case 'L' : temp0 = 50; break;
                    case 'X' : temp0 = 10; break;
                    case 'V' : temp0 = 5; break;
                    case 'I' : temp0 = 1; break;
                }
                ceck = temp0;
            }else{
                int temp1 = 0;
                switch (s[i]){
                    case 'M' : temp1 = 1000; break;
                    case 'D' : temp1 = 500; break;
                    case 'C' : temp1 = 100; break;
                    case 'L' : temp1 = 50; break;
                    case 'X' : temp1 = 10; break;
                    case 'V' : temp1 = 5; break;
                    case 'I' : temp1 = 1; break;
                }

                if(temp1 == ceck){
                    count++;
                }else{
                    count = 1;
                }
                
                if(ceck < temp1){
                    ceck = (temp1 - (ceck * count * 2));
                }else{
                    ceck = temp1;
                }
                
            }
            printf("ceck: %d -- %d\n", ceck, i);
            result += ceck;
        }
    }

    printf("%d\n", result);
    return 0;
}