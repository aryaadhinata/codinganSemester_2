#include <stdio.h>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int matrix[n][m];
    char arah;
    scanf(" %c", &arah);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    switch (arah){
        case 'U':{
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    printf("%d ", matrix[i][j]);
                }
                printf("\n");
            }
            break;
        }
        case 'S':{
            for(int i = n-1; i >= 0; i--) {
                for(int j = m-1; j >= 0; j--) {
                    printf("%d ", matrix[i][j]); 
                }
                printf("\n");
            }
            break;
        }
        case 'T':{
            for(int i = 0; i < m; i++) {
                for(int j = n-1; j >= 0 ; j--) {
                    printf("%d ", matrix[j][i]); 
                }
                printf("\n");
            }
            break;
        }
        case 'B':{
            for(int i = m-1; i >= 0; i--) {
                for(int j = 0; j < n ; j++) {
                    printf("%d ", matrix[j][i]); 
                }
                printf("\n");
            }
            break;
        }
    }
    
    return 0;
}