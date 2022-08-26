# Fork

<h2>Compilation Instructions</h2>
gcc JKim_cpfork.c -o JKim_cpfork.exe<br>
./JKim_cpfork.exe source target1 target 2 

<h2>Program Design</h2>
This program demonstrates how the call to fork() can create a child process inside the parent process. A function inside the parent process will open a text file and write to a first target file. Then we call the fork() to create the child process. Because of the wait() call, the parent has to wait until the child process is done. The child process will invoke cpfile.exe to open a text file and write to a second target file. At the end, we will have three files with the same content.    The forking involves a series of if, else if, and else statements. Fork() is called once but returns twice: once for the parent process and once for the child process. The pid receives and saves the values returned from the fork(). If the pid equals 0 (child process), the program will perform the execlp in the middle else if block. If the pid is greater than 0 (parent process), it will go to the last else block and wait for the child process to finish. <br><br>

The forking involves a series of if, else if, and else statements. Fork() is called once but returns twice: once for the parent process and once for the child process. The pid receives and saves the values returned from the fork(). If the pid equals 0 (child process), the program will perform the execlp in the middle else if block. If the pid is greater than 0 (parent process), it will go to the last else block and wait for the child process to finish. 
