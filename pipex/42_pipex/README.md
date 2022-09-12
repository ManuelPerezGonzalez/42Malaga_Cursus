Pipex reproduces the behaviour of the shell pipe '|' command in C.

After compilation, it launches as "./pipex infile cmd1 cmd2 outfile" and behaves as this line does in the shell "< infile cmd1 | cmd2 > outfile".

The main idea is to execute "cmd1" with "infile" as input and send the result to "cmd2", which will write it to "outfile".

- Fisrt execve(cmd1) output (end[1]) is sent by pipe() as input to second execve(cmd2) (end[2]). Pipe() takes an array of two int such as int end[2], and links them together with a pipe, so what is done in end[0] is visible to end[1], and vice versa.

- Fork() will split our program process in two parallel, simultaneous sub-processes (0 for child process, non-zero number for parent process and -1 for error).

- Fd are file descriptors, thanks to it, both ends can comunicate, since both can be read and written to.

- Dup2 copies the fisrt parameter (infile) fd in the second parameter (STDIN_FILENO), or else said, it will redirect fd1 to fd2. Swaps our files with stdin and stdout.

end[1] is the child process, and end[0] the parent process; the child writes, while the parent reads. And since for something to be read, it must be written first, cmd1 will be executed by the child, and cmd2 by the parent.