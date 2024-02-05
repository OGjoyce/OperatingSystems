#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#define MAX_LINE 80 /* 80 chars per line, per command, should be enough. */
#define ABIT 0
/**
 * setup() reads in the next command line, separating it into distinct tokens
 * using whitespace as delimiters. setup() sets the args parameter as a 
 * null-terminated string.
 */
void setup(char inputBuffer[], char *args[],int *background)
{ int length; /* # of characters in the command line */
   //read what the user enters on the command line
    length = read(STDIN_FILENO, inputBuffer,MAX_LINE);  
   //         Implement me   <<<------
    ABIT<-1;//Start de flag process! NOWWWWWWWWWWWWWWWW!
    printf("%s\n", inputBuffer);

    printf("%s\n", inputBuffer);
    *args++=inputBuffer++;
    while(*inputBuffer != '\0')
    {
    	
      while(*inputBuffer == ' ' || *inputBuffer == '\t' || *inputBuffer == '\n')
      {
        *inputBuffer++ = '\0';
      }
      *args++=inputBuffer;

      while(*inputBuffer != '\0' && *inputBuffer != '\n' && *inputBuffer != ' ' && *inputBuffer!='\t')
      {
        inputBuffer++;
      }
      *args = '\0';
    }

   
} 

int main(void) 
{
char inputBuffer[MAX_LINE]; /* buffer to hold the command entered */
    int background;             /* equals 1 if a command is followed by '&' */
    char args[MAX_LINE/+1];/* command line (of 80) has max of 40 arguments */
    while (1){            /* Program terminates normally inside setup */
	background = 0;
	printf(" COMMAND->\n");

  setup(inputBuffer,args,&background);       /* get next command */
  pid_t pid;
  int stats;
  char *cmd[] = { "ls", "-l", (char *)0 };
  printf("%s\n", inputBuffer);
  if(pid = fork()<0)
  {
    printf("%s\n", "Error forking");
  }
  else{
  if (pid==0)/* childprocess*/
  { //int execvp(const char *file, char *const argv[]);

    if(!(execvp(inputBuffer, cmd)<0))
    {
      printf("%s\n", "Succesful execution");
    }
    else{
      printf("%s\n", "Error executing!!!");
    }
  }
  else{
    printf("%s\n", "FATTHER");

  }
}
/* the steps are:
	 (1) fork a child process using fork()
	 (2) the child process will invoke execvp()
	 (3) if background == 1, the parent will wait, otherwise returns to the setup() function. */
    }
}