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
		case Timer:
			command_message = "Timer";break;
		case None:
			command_message = "None";break;
		default :
			command_message = "None";break;
	}

	printf("\nDebug Info :\nPath: %s\nCommand :%s\n",path,command_message);
}

void hello_message(){
    printf("=====================\n");
    printf("===Bad Text Editor===\n");
    printf("=====================\n");
    printf("A pretty bad text editor.\nNOT RECOMMENDED FOR NORMAL USAGE!\n");
    printf("\nYou Can Use These Commands To do Something:\n\n t : count for specifyed duration.\n u : To print UwU for 3 seconds.\n e : To exit the program.\n r : read a file.\n w : write a file or overwrite an existing file.\n a : to append some text to a file (write the text after the file path).\n d : to remove a file.\n\n");

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
        else if ( command[i] == 't' | command[i] == 'T'){
            return Timer;
        }
        
    }
    return None;

    
}

CommandTypes get_command(){
    char command[BufferSize];
    printf("\n\nType Command.\n\n");
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
			write_file(path);
			break;
		case Append:
			append_text(path);
			break;
		case Remove:
			delete_file(path);
			break;
		case Timer:
			counter();
			break;
	}
}

void read_file(const char* path){
    FILE * fileptr = fopen(path,"r");
    
    if (fileptr == NULL){
    printf("\n\nError: File Doesn't Exist, Please Input An Existing File Path.\n\n");
    
    fclose(fileptr);
    return;
    }
    char reader_buffer[ReaderBuffer];
    
    printf("\n");
    printf("File Data:\n\n");
    while (fgets(reader_buffer,ReaderBuffer,fileptr) != NULL){
    	printf("%s",reader_buffer);
    }
    printf("\n\n");
    fclose(fileptr);
    
}
void write_file(const char* path){

    FILE * fileptr = fopen(path,"w");
    
    fprintf(fileptr,"");
    
    fclose(fileptr);

}

//due to our very low budget and time.
//I am gonna replace some keys like (space) and (enter [\n]) with _ and %.
//And you can cancel it by typing it twice.

void append_text(const char* path){
    FILE * fileptr = fopen(path,"a");
    
    if (fileptr == NULL){
    printf("\n\nError: File Doesn't Exist, Please Input An Existing File Path.\n\n");
    fclose(fileptr);
    return;
    }
    char buffer[BufferSize];
    
    scanf("%s",&buffer);
    
    for (int i = 0;i < BufferSize;i++){
    	if (buffer[i] == '_'){
    	    buffer[i] = ' ';
    	}
    	else if (buffer[i] == '%'){
    	    buffer[i] = '\n';
    	}
    }
    
    
    fprintf(fileptr,"%s",buffer);   
    fclose(fileptr);
}

void delete_file(const char* path){
    FILE* fileptr = fopen(path,"r");
    
    if (fileptr == NULL){
    	printf("\n\nError: File Doesn't Exist, Please Input An Existing File Path.\n\n");
    	fclose(fileptr);
    	return;
    }
    
    remove(path);
    fclose(fileptr);
}

// I don't know why I added This.
void counter(){
    double current;
    
    float timer;
    scanf("%f",&timer);
    
    while (current < timer){
    	current = (double)clock()/CLOCKS_PER_SEC;
    	
    	printf("\n%.4f                %.4f                    %.4f                    %.4f                    %.4f",current,current,current,current,current);
    }
    printf("\n\n\n");

}

void main_loop(){
    while (1){
    	CommandTypes command = get_command();
    	printf("\nFile Path.\n");
    	char path[BufferSize];
    	scanf("%s",&path);
    	DebugInfo(path,command);
    	chooseCommand(command,path);
    	if (command == Exit){
    	    break;
    	}
    	else if (command == None){
    	    continue;
    	}
    }
}


