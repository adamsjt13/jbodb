#include <stdio.h>
#include <string.h>

void print_options() {
    printf("Incorrect usage! Please use one of the following:\n");
    printf("1. PUT <key> <value>\n");
    printf("2. GET <key>\n");
    printf("3. DEL <key>\n");
}

int main(int argc, char* argv[]) {
    printf("Welcome to JboDB!\n");

    if (argc < 2) {
        print_options();
        return 1;
    }


    if(strcmp(argv[1], "PUT") == 0){
        printf("OK! Inserting (%s, %s) into db!\n", argv[2], argv[3]);
    }
    else if(strcmp(argv[1], "GET") == 0){
        printf("OK! Retrieving value for key, %s, from db!\n", argv[2]);
    }
    else if(strcmp(argv[1], "DEL") == 0){
        printf("OK! Deleting key, %s, from db!\n", argv[2]);
    }
    else {
        print_options();
        return 1;
    }
    return 0;
}