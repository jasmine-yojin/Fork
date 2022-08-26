#include <stdio.h>
#include <fcntl.h>
#include<unistd.h>
#define SIZ 128
#include<sys/wait.h>

int func_cpfile (const char *srcname, const char *tgtname){
	int f1, f2;
	// Can we access thge source file?
	if ((f1 = open(srcname, O_RDONLY, 0)) == -1){
	printf("Can't open %s \n", srcname);
	return 1;
	}
	// Can we create the target file?
	if ((f2 = creat(tgtname, 0644)) == -1){
	printf("Can't create %s \n", tgtname);
	return 2;
	}
	// Copy source file contents to target file.Tips
	char buf[SIZ];
	int n;
	while ((n = read( f1, buf, SIZ)) > 0)
	if (write(f2, buf, n) != n)
	{
		printf("Can't write file" );
		close(f1);
		close(f2);
		return 3;
	}
	
	close(f1);
	close(f2);
	printf("Success creating a copy using a function inside parent process\n");
	return 0;
}

int main (int argc, const char*argv[]){ //JK_cpfork.exe, srcname, tgt1name, tgt2name
	//I included a check to the number of parameters since we need 4 of them. 
	if (argc != 4){
		printf("Wrong number of command line arguments for the parent process\n");
		// exit(1);
		return 1;
    }
	
	//Variable which will hold the pid of parent and child. This is necessary for checking the conditions for the if else blocks below. 
	pid_t pid;

	//This calls the func_cpfile written above. The parent process will conduct the first file IO onto target1 file. 
	func_cpfile(argv[1], argv[2]); 	
	
	//Create the child process 
	pid = fork ();
	
	if (pid < 0){
		fprintf(stderr, "Fork Failed");
		return 2;
	}	
	else if (pid == 0){ //This block is for the child process. The child process will execute the cpfile and conduct the second file IO onto target2 file. 
		int ret = execlp("./cpfile.exe", "cpfile.exe", argv[1], argv[3], NULL); //"./cpfile.exe", "cpfile.exe", srcname, tgt2name
		fprintf(stderr, "execlp Failed %d ", ret);
		return 3;
	}
	else{
		wait(NULL);
		printf("/nChild complete");//The child process terminated and the wait() call was complete. 
	}
		
	return 0;
	
	
	
}
