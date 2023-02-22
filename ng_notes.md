child :
- takes input from an fd and dups2 it to make it be the stdinput
- takes a tube, dups2 the stdout to it
- execve and quits

Basically, performs execve on fd (stdin) and sends it to tube (stdout)

But this is only half of the tube. The other half is a second command.

So, the child 2:

- takes input from the pipe and swaps it with its own stdin
- 