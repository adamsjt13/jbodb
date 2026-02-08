#include <stdio.h>
#include <string.h>

void print_options(int error) {
    if(error == 1) {
        printf("Invalid Input!\n\n");
    }
    printf("Please use one of the following:\n");
    printf("1. PUT <key> <value>\n");
    printf("2. GET <key>\n");
    printf("3. DEL <key>\n");
    printf("4. EXIT\n");
}

int main() {
    printf("Welcome to JboDB!\n");
    print_options(0);

    while(1) {

        char line[256];
        printf(">");
        
        if (fgets(line, sizeof(line), stdin) != NULL) {

            line[strcspn(line, "\n")] = '\0';
            
            char *command = strtok(line, " ");
            char * arg1 = strtok(NULL, " ");
            char * arg2 = strtok(NULL, " ");

            if(strcmp(command, "PUT") == 0){
                if(arg1 && arg2 && !strtok(NULL, " ")) {
                    printf("OK! Inserting (%s, %s) into db!\n", arg1, arg2);
                } else {
                print_options(1);
                continue;
                }
            }
            else if(strcmp(command, "GET") == 0){
                if(arg1 && !arg2) {
                    printf("OK! Retrieving value for key, %s, from db!\n", arg1);
                } else {
                print_options(1);
                continue;
                }
            }
            else if(strcmp(command, "DEL") == 0){
                if(arg1 && !arg2) {
                    printf("OK! Deleting key, %s, from db!\n", arg1);
                } else {
                print_options(1);
                continue;
                }
            }
            else if(strcmp(command, "EXIT") == 0){
                if(!arg1) {
                    break;
                }
            }
            else
                print_options(1);
                continue;
            }

    }
}