#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <ctype.h>

void remove_newline(char *str){
    int len = strlen(str);
    if(str[len - 1] == '\n'){
        str[len - 1] = '\0';
    }
}

void print(char *row, const bool idc_about_letters, const bool output_file, FILE *output, const char *needle){
    int len = strlen(row);
    int needle_len = strlen(needle);
    bool found = false;
    for(int i = 0; i <= len - needle_len; i++){
        for(int j = 0; j < needle_len; j++){
            if(idc_about_letters){
                if(tolower(row[i + j]) != tolower(needle[j])){
                    break;
                }
                if(j == needle_len - 1){
                    found = true;
                }
            }else{
                if(row[i + j] != needle[j]){
                    break;
                }
                if(j == needle_len - 1){
                    found = true;
                }
            }
        }
        if(found){
            break;
        }
    }
    if(found){
        if(!output_file){
            /*bool start = true;
            for(int i = 0; i <= len - needle_len; i++){
                for(int j = 0; j < needle_len; j++){
                    if(idc_about_letters){
                        if(tolower(row[i + j]) != tolower(needle[j])){
                            printf("%c", row[i]);
                            break;
                        }
                        if(j == needle_len - 1){
                            if(start){
                                printf("\033[0;31m");
                                start = false;
                            }
                            for(int k = i; k < i + needle_len; k++){
                                printf("%c", row[k]);
                            }
                            start = true;
                        }
                    }else{
                        if(row[i + j] != needle[j]){
                            printf("%c", row[i]);
                            break;
                        }
                        if(j == needle_len - 1){
                            if(start){
                                printf("\033[0;31m");
                                start = false;
                            }
                            for(int k = i; k < i + needle_len; k++){
                                printf("%c", row[k]);
                            }
                            start = true;
                        }
                    }
                }
                printf("\033[0m");
            }
            printf("\n");*/
            printf("%s\n", row);
        }else{
            fprintf(output, "%s\n", row);    
        }
    }
}

int main(int argc, char** argv) {
    bool idc_about_letters = false;
    bool output_file = false;
    bool input_file = false;
    bool needle_provided = false;
    const char *input_filename = NULL;
    const char *output_filename = NULL;
    const char *needle = NULL;
    if(argc < 2){
        printf("Input path not provided\n");
        return 1;
    }
    for(int i = 1; i < argc; i++){
        char *parameter = argv[i];
        remove_newline(parameter);
        if(strcmp(argv[i - 1], "-o") == 0){
            output_filename = parameter;
        }else if(strcmp(parameter, "-i") == 0){
            if(idc_about_letters){
                printf("Parameter -i provided multiple times\n");
                return 1;
            }
            idc_about_letters = true;
        }else if(strcmp(parameter, "-o") == 0){
            if(output_file){
                printf("Parameter -o provided multiple times\n");
                return 1;
            }
            output_file = true;
        }else{
            if(!input_file){
                input_filename = parameter;
                input_file = true;
            }else if(!needle_provided){
                 needle = parameter;
                 needle_provided = true;
            }else{
                printf("Too many parameters provided\n");
                return 1;
            }
        }
    }
    if(input_filename == NULL){
        printf("Input path not provided\n");
        return 1;
    }
    if(output_filename == NULL && output_file){
        printf("Missing output path\n");
        return 1;
    }
    if(needle == NULL){
        printf("Needle not provided\n");
        return 1;
    }
    char row[101] = {0};
    FILE *input = fopen(input_filename, "rt");
    assert(input_filename);
    FILE *output = NULL;
    if(output_file){
        output = fopen(output_filename, "w");
        assert(output_filename);
    }
    while(1){
        if(fgets(row, sizeof(row), input)){
            remove_newline(row);
            print(row, idc_about_letters, output_file, output, needle);
        }else{
            if(feof(input)){
                break;
            }
        }
    }
    fclose(input);
    if(output_file){
        fclose(output);
    }
    return 0;
}