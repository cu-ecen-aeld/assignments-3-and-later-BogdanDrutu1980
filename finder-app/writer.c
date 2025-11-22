#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

int main(int argc, char *argv[])
{
    /* Setup syslog - LOG_USER facility */
    openlog("writer", LOG_PID, LOG_USER);

    /* Verify argument count*/
    if (argc != 3)
    {
        syslog(LOG_ERR, "Invalid number of arguments: %d provided, 2 required", argc - 1);
        fprintf(stderr, "Error: Two arguments required.\nUsage: %s <writefile> <writestr>\n", argv[0]);
        closelog();
        exit(1);
    }

    const char *writefile = argv[1];
    const char *writestr = argv[2];

    /* try openining the file for writing */
    FILE *file = fopen(writefile, "w");
    if (file == NULL)
    {
        syslog(LOG_ERR, "Failed to open file: %s", writefile);
        fprintf(stderr, "Error: Failed to open file '%s'.\n", writefile);
        closelog();
        exit(1);
    }

    /* Write to file */
    if (fputs(writestr, file) == EOF)
    {
        syslog(LOG_ERR, "Error writing to file: %s", writefile);
        fprintf(stderr, "Error: Could not write to file '%s'.\n", writefile);
        fclose(file);
        closelog();
        exit(1);
    }

	/* close the file*/
	fclose(file);
    
	/* Log success using DEBUG level */
    syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);
	closelog();
    return 0;
}