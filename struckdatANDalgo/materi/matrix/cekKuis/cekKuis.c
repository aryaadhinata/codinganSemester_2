#include <stdio.h>

typedef struct{
    int c, m, y, k;
}warna;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    warna matrix[n][m];
    for(int i = 0; i < n; i++){
        for( int j = 0; j < m; j++){
            scanf("%d %d %d %d", &matrix[i][j].c, &matrix[i][j].m, &matrix[i][j].y, &matrix[i][j].k);
        }
    }
    
    int cc = 0, tc = 0,
        cm = 0, tm = 0,
        cy = 0, ty = 0,
        ck = 0, tk = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if((matrix[i][j].c > matrix[i][j].m) && 
            (matrix[i][j].c > matrix[i][j].y) &&
            (matrix[i][j].c > matrix[i][j].k)){
                tc += matrix[i][j].c;
                cc++;
            }
            if((matrix[i][j].m > matrix[i][j].c) && 
            (matrix[i][j].m > matrix[i][j].y) &&
            (matrix[i][j].m > matrix[i][j].k)){
                tm += matrix[i][j].m;
                cm++;
            }
            if((matrix[i][j].y > matrix[i][j].m) && 
            (matrix[i][j].y > matrix[i][j].c) &&
            (matrix[i][j].y > matrix[i][j].k)){
                ty += matrix[i][j].y;
                cy++;
            }
            if((matrix[i][j].k > matrix[i][j].m) && 
            (matrix[i][j].k > matrix[i][j].y) &&
            (matrix[i][j].k > matrix[i][j].c)){
                tk += matrix[i][j].k;
                ck++;
            }
        }
    }
    
    printf("cenderung cyan : %d - total : %d\n", cc, tc);
    printf("cenderung mangenta : %d - total : %d\n", cm, tm);
    printf("cenderung yellow : %d - total : %d\n", cy, ty);
    printf("cenderung key : %d - total : %d\n", ck, tk);
    

    printf("\nKesimpulan: ");
    if(((cc >= cm) && (cc >= cy) && (cc >= ck)) || 
        ((cm >= cc) && (cm >= cy) && (cm >= ck)) ||
        ((cy >= cm) && (cy >= cc) && (cy >= ck)) ||
        ((ck >= cm) && (ck >= cy) && (ck >= cc))){
        
        if((cc > cm) && (cc > cy) && (cc > ck)){
            printf("cyan\n");
        }else if((cm > cc) && (cm > cy) && (cm > ck)){
            printf("mangenta\n");
        }else if((cy > cm) && (cy > cc) && (cy > ck)){
            printf("yellow\n");
        }else if((ck > cm) && (ck > cy) && (ck > cc)){
            printf("key\n");
        }else{
            if((tc >= tm) && (tc >= ty) && (tc >= tk)){
                printf("cyan\n");
            }else if((tm > tc) && (tm >= ty) && (tm >= tk)){
                printf("mangenta\n");
            }else if((ty > tc) && (ty > tm) && (ty >= tk)){
                printf("yellow\n");
            }else if((tk > tc) && (tk > tm) && (tk > ty)){
                printf("key\n");
            }
        }
    }

    return 0;
}