#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

int main() {
  // Create the pipes
  int pipe_fds[2];
  pipe(pipe_fds);

  // Spawn child process
  pid_t pid = fork();

  // Child code
  if (pid == 0) {
    // Close the read end of pipe (children won't read)
    close(pipe_fds[0]);

    int grandchild_pids[5];

    for (int i = 0; i < 5; i++) {
      grandchild_pids[i] = fork();
      if (grandchild_pids[i] == 0) {
        exit(0);
      }
    }

    // Write the child PIDs
    for (int i = 0; i < 5; i++) {
      int gc_pid = grandchild_pids[i];
      write(pipe_fds[1], &gc_pid, sizeof(pid_t));
    }

    // This child is done, close the file descriptor and exit
    close(pipe_fds[1]);
    return 0;
  }

  // Parent code
  // Close write end of pipe
  close(pipe_fds[1]);

  // Keep on reading data until child process has closed write ends
  // If the pipe is empty and not closed, call will block
  pid_t curr_pid;
  while (read(pipe_fds[0], &curr_pid, sizeof(curr_pid))) {
    printf("Received pid %d.\n", curr_pid);
  }

  // Wait for child process to terminate
  int status;
  wait(&status);

  // Close remaining file descriptors; pipe memory is on stack, so it is
  // automatically cleaned up
  close(pipe_fds[0]);
  return 0;
}
