#include "get_next_line.h"

void *ft_free(char **line)
{
    if(*line != NULL)
    {
        free(*line);
        *line = NULL;
        return (NULL);
    }
    return (NULL);
}


char *get_data(char **line)
{
    char *buff;
    char *result;
    int location;

    if(*line == NULL)
        return (NULL);
    buff = *line;
    location = ft_strchr(buff, '\n');
    if(location == -1)
    {
        if(ft_strlen(buff) == 0)
            return (ft_free(line));
        result = ft_strdup(*line);
        ft_free(line);
        return (result);
    }
    result = ft_substr(buff, 0, location + 1);
    if(result == NULL)
        return (ft_free(line));
    *line = ft_substr(buff, location + 1, (ft_strlen(buff) - location));
    free(buff);
    return(result);
}

void *manager_buffer(char **line, int *read_size, int fd)
{
    char *buff;

    buff = malloc(BUFFER_SIZE + 1);
    if(!buff)
        return(ft_free(line));
    *read_size = read(fd, buff, BUFFER_SIZE);
    if(*read_size == -1)
    {
        free(buff);
        return (ft_free(line));
    }
    buff[*read_size] = 0;
    *line = ft_strjoin(*line, buff);
    free(buff);
    return (NULL);
}

char *get_next_line(int fd)
{
    static char *line;
    int read_size;

    read_size = 1;
    if(fd < 0 || BUFFER_SIZE <=  0)
        return (NULL);
    if(line == NULL)
        line = ft_strdup("");
    while(read_size > 0)
    {
        if(ft_strchr(line, '\n') == -1)
        {
            manager_buffer(&line, &read_size, fd);
            if(line == NULL)
                return (ft_free(&line));
        }
        else
            return (get_data(&line)); 
    }
    return (get_data(&line));
}
