#include <stdio.h> // for puts(), printf(), feof()
#include <stdlib.h> // for no warn about wait()
#include <string.h> // for strtok(), strlen()
#include <unistd.h> // for fork(), wait()

#define MAX_LINE 80
#define HISTORY_SIZE 10
#define HELP_MESSAGE "sh: "

// store history 
struct {
  char history[HISTORY_SIZE][MAX_LINE];
  int begin;
  int size;
} data;

// print history
void printHistory() {
  puts("");
  int i = 0;
  for (; i < data.size; i++) {
    int index = (data.begin + i) % HISTORY_SIZE;
    printf("%s", data.history[index]);
  }
}

// add history
void addHistory(char *str) {
  int index = (data.begin + data.size) % HISTORY_SIZE;
  strcpy(data.history[index], str);
  if (data.size == HISTORY_SIZE) {
    data.begin = (data.begin + 1) % HISTORY_SIZE;
  } else {
    data.size++;
  }
}

// pricess signal, not kill process
void process_signal(int sign_num) {
  printHistory();
}

//most inportant  set up function
void setup(char inputBuffer[], char *args[], int *background) {
  // read input 
  fgets(inputBuffer, MAX_LINE, stdin);
  // process EOF and skip empty line
  if (feof(stdin)) exit(0);
  if (inputBuffer[0] == '\n' && strlen(inputBuffer) == 1) return;
  // add history
  addHistory(inputBuffer);
  // slice input to args 
  // attention please! only one white char in allowed between two args
  char *pch = strtok(inputBuffer, " \t\n");
  int i = 0;
  for (; pch != NULL; i++) {
    args[i] = pch;
    // printf("|%s|",args[i]);
    pch = strtok(NULL, " \n");
  }
  // check background or not 
  *background = (int)(strcmp(args[i - 1], "&") == 0);
  // printf("%d", *background);
  if (*background) args[i - 1] = NULL;
  
  int pid = fork();
  if (pid == 0) execvp(args[0], args);
  // if not background, wait it finished
  if (*background != 1) wait(NULL);
}

// mian func like book example
int main() {
  signal(SIGINT, process_signal);

  char inputBuffer[MAX_LINE];
  int background;
  char *args[MAX_LINE / 2 + 1];

  while (1) {
    background = 0;
    printf("%s", HELP_MESSAGE);
    // print stdout buffer 
    fflush(stdout);
    
    setup(inputBuffer, args, &background);
  }
}

// about exec
// 
// 
// C language prototypes
// The POSIX standard declares exec functions in the unistd.h header file, in C
// language. The same functions are declared in process.h for DOS (see below),
// OS/2, and Microsoft Windows.

// int execl(char const *path, char const *arg0, ...);
// int execle(char const *path, char const *arg0, ..., char const *envp[]);
// int execlp(char const *file, char const *arg0, ...);
// int execv(char const *path, char const *argv[]);
// int execve(char const *path, char const *argv[], char const *envp[]);
// int execvp(char const *file, char const *argv[]);
// Some implementations provide these functions named with a leading underscore
// (e.g. _execl).

// The base of each is exec (execute), followed by one or more letters:

// e – An array of pointers to environment variables is explicitly passed to the
// new process image.
// l – Command-line arguments are passed individually (a list) to the function.
// p – Uses the PATH environment variable to find the file named in the file
// argument to be executed.
// v – Command-line arguments are passed to the function as an array (vector) of
// pointers.
// path
// The argument specifies the path name of the file to execute as the new
// process image. Arguments beginning at arg0 are pointers to arguments to be
// passed to the new process image. The argv value is an array of pointers to
// arguments.

// arg0
// The first argument arg0 should be the name of the executable file. Usually it
// is the same value as the path argument. Some programs may incorrectly rely on
// this argument providing the location of the executable, but there is no
// guarantee of this nor is it standardized across platforms.

// envp
// Argument envp is an array of pointers to environment settings. The exec calls
// named ending with an e alter the environment for the new process image by
// passing a list of environment settings through the envp argument. This
// argument is an array of character pointers; each element (except for the
// final element) points to a null-terminated string defining an environment
// variable.

// Each null-terminated string has the form:

// name=value
// where name is the environment variable name, and value is the value of that
// variable. The final element of the envp array must be null.

// In the execl, execlp, execv, and execvp calls, the new process image inherits
// the current environment variables.
