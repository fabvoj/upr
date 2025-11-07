#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void count_statistics(int *array_before, int *array_after, const char *row,const int length,const bool now){
    for(int j = 0; j < length; j++){
        if(row[j] >= 'a' && row[j] <= 'z'){
            if(now){
                array_before[0]++;
            }
            else{
                array_after[0]++;
            }
            
        }
        else if(row[j] >= 'A' && row[j] <= 'Z'){
            if(now){
                array_before[1]++;
            }
            else{
                array_after[1]++;
            }
        }
        else if(row[j] == ' '){
            if(now){
                array_before[2]++;
            }
            else{
                array_after[2]++;
            }
        }
    }
}

void delete_spaces(char *row, int *length){
    for(int j = 0; j < *length; j++){
        if((row[j] == ' ' && row[j + 1] == ' ') || (row[0] == ' ' && j == 0) || (row[j] == ' ' && row[j + 1] == '\0')){
            for(int k = j; k < *length - 1; k++){
                row[k] = row[k + 1];
            }
            j--;
            (*length)--;
        }
    }
}

void normalize(char *row, int length){
    int length_of_word = 0;
    int is_upper = 0;
    for(int j = 0; j <= length; j++){
        if(row[j] != ' ' && j != length){
            length_of_word++;
            if(row[j] >= 'A' && row[j] <= 'Z' && row[j] != ' '){
                is_upper += 1;
            }

        }else{
            if(is_upper > 0){
                if(row[j - length_of_word] >= 'a' && row[j - length_of_word] <= 'z' && row[j - length_of_word] != ' '){
                    row[j - length_of_word] -= 32;
                }
                for(int k = j - length_of_word + 1; k <= j; k++){
                    if(row[k] >= 'A' && row[k] <= 'Z' && row[k] != ' '){
                        row[k] += 32;
                    }
                }
            }else{
                for(int k = j - length_of_word; k <= j; k++){
                    if(row[k] >= 'a' && row[k] <= 'z' && row[k] != ' '){
                        row[k] -= 32;
                    }
                }
            }
            length_of_word = 0;
            is_upper = 0;
        }
    }
}


void print_statistic(const int length,const char * row, const int *array_before, const int * array_after){
    for(int j = 0; j < length - 1; j++){
            printf("%c", row[j]);
        }
    printf("\n");
    printf("lowercase: %d -> %d\n", array_before[0], array_after[0]);
    printf("uppercase: %d -> %d\n", array_before[1], array_after[1]);
    printf("spaces: %d -> %d\n", array_before[2], array_after[2]);
}

void delete_repetetive_chars(char *row, int *length){
    for(int j = 0; j < *length - 1; j++){
        if(row[j] == row[j + 1]){
            for(int k = j; k < *length - 1; k++){
                row[k] = row[k + 1];
            }
            j--;
            (*length)--;
        }
    }
}

int my_strlen(const char* s){
    int len = 0;
    while(s[len] != 0){
        len++;
    }
    return len;
}

int string_to_int(char * string){
    int result = 0;
    int length = my_strlen(string);
    for(int i = 0; i < length; i++){
        if(string[i] >= '0' && string[i] <= '9'){
            result = result * 10 + (string[i] - '0');
        }
    }
    return result;
}

int main(){
    int n = 0;
    char number[ 51 ] = {0};
    fgets(number, 51, stdin);
    n = string_to_int(number);
    for(int i = 0; i < n; i++){
        int array_before[3] = {0};
        int array_after[3] = {0};
        char row[ 51 ] = {0};
        fgets(row, 51, stdin);
        int length = my_strlen(row);
        if(length > 0 && row[ length - 1 ] == '\n'){
            row[ length - 1 ] = '\0';
        }
        bool before = true;
        count_statistics(array_before, array_after, row, length, before);
        delete_spaces(row, &length);
        before = false;
        normalize(row, length);
        delete_repetetive_chars(row, &length);
        count_statistics(array_before, array_after, row, length, before);
        print_statistic(length, row, array_before,  array_after);
        if(i != n - 1){
            printf("\n");
        }
    }
    return 0;
}