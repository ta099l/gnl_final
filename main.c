#include <fcntl.h> // For open()
#include <stdio.h> // For printf()
#include <stdlib.h> // For exit()
#include "get_next_line.h" // Include your header file

int main(void)
{
    int fd;
    char *line;

    // Open the test file
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Read and print each line from the file
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    // Close the file
    if (close(fd) == -1)
    {
        perror("Error closing file");
        exit(EXIT_FAILURE);
    }

    return 0;
}


