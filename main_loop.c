#include <stdio.h>
#include <stdlib.h>
#include "types.h"

void hello_message(){
    printf("=====================\n");
    printf("===Bad Text Editor===\n");
    printf("=====================\n");
    printf("A pretty bad text editor.\nNOT RECOMMENDED FOR NORMAL USAGE!\n");
    printf("\nYou Can Use These Commands To do Something:\n\n u : To print UwU for 10 seconds.\n e : To exit the program.\n r : read a file.\n w : write a file or overwrite an existing file.\n a : to append some text to a file (write the text after the file path).\n d : to remove a file.\n\n");

}

CommandTypes parse_command(char command[]){
    
    for (int i = 0 ; i < 6;i++){
        if ( command[i] == 'a' | command[i] == 'A'){
            return Append;
        }
        else if ( command[i] == 'r' | command[i] == 'R'){
            return Read;
        }
        else if ( command[i] == 'd' | command[i] == 'D'){
            return Remove;
        }
        else if ( command[i] == 'u' | command[i] == 'U'){
            return UwU;
        }
        else if ( command[i] == 'w' | command[i] == 'W'){
            return Write;
        }
        else if ( command[i] == 'e' | command[i] == 'E'){
            return Exit;
        }
        
    }
    return None;

    
}

CommandTypes get_command(){
    char command[6];
    printf("Type Command.\n\n");
    scanf("%s",command);
    CommandTypes parsed_command = parse_command(command);
    return parsed_command;
    
    
}
char* get_path(){
    printf("\nFile Path.\n");
    char path[PathSize];
    scanf("%s",path);
    printf("%s\n",path);
    return path;
}

void main_loop(){
    CommandTypes command = get_command();
    char* path = get_path();

    
    
}
