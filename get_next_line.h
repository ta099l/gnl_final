#ifndef GET_NEXT_LINE_H
#define  GET_NEXT_LINE_H
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE 
# define BUFFER_SIZE 42
#endif 

int        ft_strlen(char *str);
int        ft_strchr(char *str, char ch);
char        *ft_strdup(char *str);
char        *ft_strjoin(char *s1, char *s2);
char        *ft_substr(char *str, int start, int size);
char *get_next_line(int fd);

#endif
