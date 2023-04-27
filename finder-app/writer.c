#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>

// write main function for writer.c
int main(int argc, char *argv[]) {

// create variable argument assignments
    char *writefile = argv[1];
    char *writestr  = argv[2];

// if statement to check number of arguments (arg[0] -> file call, arg[1] -> file name to write, arg[2] -> file content to write)
// log error, print message, and exit
    if (argc != 3) {
        syslog(LOG_ERR, "ERROR : %s requires 3 arguments to function", writefile);
        exit(1);
    }

// open file for writing to
    FILE *f = fopen(writefile, "w");

// safety for general case use where file would not exist -- logs error, prints message, and exit
    if (f == NULL) {
	syslog(LOG_ERR, "ERROR : %s file does not exist", writefile);
	exit(1);
    }

// write content to file & close file
    fprintf(f, "%s", writestr);
    fclose(f);

// show that the content string has been written to the specified file
    syslog(LOG_DEBUG, "Writing \"%s\" to %s.", writestr, writefile);

    return 0;
}
