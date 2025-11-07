#include <stdio.h>

int main() {
    int shape = 0;
    int n1 = 0;
    int n2 = 0;
    int n = 0;

    scanf("%d%d%d", &shape, &n1, &n2);
    switch (shape){
    case 0:
        for(int row = 0; row < n2; row++){
            for(int col = 0; col < n1; col++){
                printf("x");
            }
            printf("\n");
        }   
        break;
    case 1:
        for(int row = 0; row < n2; row++){
            for(int col = 0; col < n1; col++){
                if(row == 0 || col == 0 || col == n1 -1 || row == n2 - 1){
                    printf("x");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
        break;
    case 2:
        for(int row = 0; row < n2; row++){
            for(int col = 0; col < n1; col++){
                if(row == 0 || col == 0 || col == n1 -1 || row == n2 - 1){
                    printf("x");
                } else {
                    printf("%d", n);
                    n = n + 1;
                    if(n == 10){
                        n = 0;
                    }
                }
            }
            printf("\n");
        }
        break;
    case 3:
        for(int row = 0; row < n1; row++){
            for(int col = 0; col < n1; col++){
                if(col == row){
                    printf("x");
                    col = n1;
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
        break;
    case 4:
        n = n1;
        for(int row = 0; row < n1; row++){
            for(int col = 0; col < n1; col++){
                if(col == n - 1){
                    printf("x");
                    n = n - 1;
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
        break;
    case 5:
        int number = n1 - 1;
        int number2 = number;
        n = (n1 * 2) - 1;
        for(int row = 0; row < n1; row++){
            for(int col = 0; col < n; col++){
                if( col == number || col == number2 || row == n1 - 1){
                    printf("x");
                } else {
                    printf(" ");
                }
            }
            number = number - 1;
            number2 = number2 + 1;
            printf("\n");
        }
        break;  
    case 6:
        for(int row = 0; row < n2; row++){
            for(int col = 0; col < n1; col++){
                if(row == 0){
                    printf("x");
                } else if(col == ((n1 / 2 ))){
                    printf("x");
                    col = n1;
                }else {
                    printf(" ");
                }
            }
            printf("\n");
        }
        break;
    case 7:
        for(int row = 0; row < n2; row++){
            for(int col = 0; col < n1; col++){
                if(row == 0 || col == 0 || (col == n1 - 1 && row <= (n2 / 2)) || row == (n2 / 2)){
                    printf("x");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
        break;
    case 9:
        for(int row = 0; row < n2; row++){
            for(int col = 0; col < n1; col++){
                if(row == 0 || col == 0 || col == n1 -1 || row == n2 - 1){
                    printf("x");
                } else {
                    printf("%d", n);
                    n = n + (n2 - 2);
                    if(n >= 10){
                        n = n - 10;
                    }   
                }
            }
            n = row;
            printf("\n");
        }
        break;
    default:
        printf("Neznamy obrazec\n");
    }
    return 0;
}