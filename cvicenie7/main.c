#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int index;
    char *name;
    float first_value;
    float last_value;
    int number_of_values;
} Record;

void fake_space(int number_of_values){
    char temporary[101] = {0};
    sprintf(temporary, "%d", number_of_values);
    int record_len = strlen(temporary);
    for(int j = 0; j < record_len; j++){
        if((record_len - j) % 3 == 0 && j != 0){
            printf("_");
        }
        printf("%c", temporary[j]);
    }
}

void print_record(Record *records, const int n, const char *t){
    int record = -1;
    int max_record = 0;
    for(int i = 0; i < n; i++){
        if(strcmp(records[i].name, t) == 0){
            if(records[i].number_of_values > max_record){
                max_record = records[i].number_of_values;
                record = i;
            }
        }
    }
    printf("<html>\n<body>\n<div>\n");
    if(record == -1){
        printf("Ticker %s was not found\n</div>\n", t);
    }else{
        printf("<h1>%s: highest volume</h1>\n", records[record].name);
        printf("<div>Day: %d</div>\n", records[record].index);
        printf("<div>Start price: %.2f</div>\n", records[record].first_value);
        printf("<div>End price: %.2f</div>\n", records[record].last_value);
        printf("<div>Volume: ");
        fake_space(records[record].number_of_values);
        printf("</div>\n</div>\n" );
    }
}

void print_records(Record *records,const int n, const char *t){
    printf("<table>\n<thead>\n<tr><th>Day</th><th>Ticker</th><th>Start</th><th>End</th><th>Diff</th><th>Volume</th></tr>\n</thead>\n<tbody>\n");
    for(int i = n; i > 0; i--){
        bool is_it = (strcmp(records[i - 1].name, t) == 0);
        if(is_it){
            printf("<tr>\n");
            printf("\t<td><b>%d</b></td>\n", records[i-1].index);
            printf("\t<td><b>%s</b></td>\n", records[i-1].name);
            printf("\t<td><b>%.2f</b></td>\n", records[i-1].first_value);
            printf("\t<td><b>%.2f</b></td>\n", records[i-1].last_value);
            printf("\t<td><b>%.2f</b></td>\n", records[i-1].last_value - records[i-1].first_value);
            printf("\t<td><b>");
            fake_space(records[i-1].number_of_values);
            printf("</b></td>\n</tr>\n");
        }else{        
            printf("<tr>\n");
            printf("\t<td>%d</td>\n", records[i-1].index);
            printf("\t<td>%s</td>\n", records[i-1].name);
            printf("\t<td>%.2f</td>\n", records[i-1].first_value);
            printf("\t<td>%.2f</td>\n", records[i-1].last_value);
            printf("\t<td>%.2f</td>\n", records[i-1].last_value - records[i-1].first_value);
            printf("\t<td>");
            fake_space(records[i-1].number_of_values);
            printf("</td>\n</tr>\n");
        }
    }
    printf("</tbody>\n</table>\n</body>\n</html>\n");
}

void free_records(Record *records, int n){
    for(int i = 0; i < n; i++){
        free(records[i].name);
    }
    free(records);
}

int main(int argc, char** argv) {
    if(argc != 3){
        printf("Wrong parameters\n");
        return 1;
    }
    char *t = argv[1];
    int n = atoi(argv[2]);
    Record *records = malloc(n * sizeof(Record));
    char first_row[101] = {0};
    for(int i = 0; i < n; i++){
        fgets(first_row, sizeof(first_row), stdin);
        int len = strlen(first_row);
        if(first_row[len-1] == '\n'){
            first_row[len-1] = '\0';
        }
        char *row = strtok(first_row, ",");
        records[i].index = atoi(row);
        row = strtok(NULL, ",");
        records[i].name = malloc(strlen(row) + 1);
        strcpy(records[i].name, row);
        row = strtok(NULL, ",");
        records[i].first_value = atof(row);
        row = strtok(NULL, ",");
        records[i].last_value = atof(row);
        row = strtok(NULL, ",");
        records[i].number_of_values = atoi(row);
    }
    print_record(records, n, t);
    print_records(records, n, t);
    free_records(records, n);
    return 0;
}