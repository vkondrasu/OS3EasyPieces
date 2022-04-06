#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){

  printf("hello world (pid:%d)\n", (int)getpid());
  int x = 100;
  fflush(stdout);
  int rc = fork();
  if (rc < 0) {
    // fork failed
    printf( "fork failed\n");
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (rc == 0){
    // child (new process)
    x = 200;
    printf("hello, I am child (pid:%d)\n", (int)getpid());
  }
  else{
      x = 300;
    // parent goes down this path (main)
    printf("hello, I am parent of %d (pid:%d)\n", rc, (int)getpid());
  }

printf("hello, X value %d (pid:%d)\n", x, (int)getpid());

  return 0;
  
}