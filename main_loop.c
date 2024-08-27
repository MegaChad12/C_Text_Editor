#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include <time.h>

void DebugInfo(const char* path,const CommandTypes command){
	char* command_message;
	switch (command){
		case Read:
			command_message = "Read";break;
		case UwU:
			command_message = "UwU";break;
		case Write:
			command_message = "Write";break;
		case Exit:
			command_message = "Exit";break;
		case Append:
			command_message = "Append";break;
		case Remove:
			command_message = "Delete";break;
		case None:
			command_message = "None";break;
		default :
			command_message = "None";break;
	}

	printf("\nDebug Info :\nPath: %s\nCommand :%s",path,command_message);
}

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
    char command[BufferSize];
    printf("Type Command.\n\n");
    scanf("%s",&command);
    CommandTypes parsed_command = parse_command(command);
    return parsed_command;
    
    
}

void sayUwU(){
    long current = 0;
    while (current < UwUTime){
    	current = clock() / CLOCKS_PER_SEC;
    	printf("\nUwU\n");
    }

}

void chooseCommand(const CommandTypes command,const char* path){
   switch (command){
		case Read:
			read_file(path);
			break;
		case UwU:
			sayUwU();
			break;
		case Write:
			break;
		case Exit:
			break;
		case Append:
			break;
		case Remove:
			break;
		case None:
			break;
		default :
			break;
	}
}

void read_file(const char* path){
    FILE * fileptr = fopen(path,"r");
    
    if (fileptr != NULL){
    
    char reader_buffer[ReaderBuffer];
    
    printf("\n");
    printf("File Data:\n\n");
    while (fgets(reader_buffer,ReaderBuffer,fileptr) != NULL){
    	printf("%s",reader_buffer);
    }
    printf("\n\n");
    fclose(fileptr);
    }
    printf("\nError: File Doesn't Exist, Please Input An Existing File Path.\n\n");
}
void write_file(const char* path){}

void main_loop(){
    CommandTypes command = get_command();
    printf("\nFile Path.\n");
    char path[BufferSize];
    scanf("%s",&path);
    DebugInfo(path,command);
    chooseCommand(command,path);
    
}


