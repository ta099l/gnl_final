#include "get_next_line.h"

int        ft_strlen(char *str)
{
        int        i;

        i = 0;
        if (str == NULL)
                return (0);
        while (str[i] != '\0')
                i++;
        return (i);
}

int        ft_strchr(char *str, char ch)
{
        int        i;

        i = 0;
        if (str == NULL)
                return (-1);
        while (str[i])
        {
                if (str[i] == ch)
                        return (i);
                i++;
        }
        return (-1);
}

char        *ft_strdup(char *str)
{
        char        *new_str;
        int                i;

        if (str == NULL)
                return (NULL);
        i = 0;
        new_str = malloc((ft_strlen(str) + 1) * sizeof(char));
        if (new_str == NULL)
                return (NULL);
        while (str[i] != '\0')
        {
                new_str[i] = str[i];
                i++;
        }
        new_str[i] = '\0';
        return (new_str);
}

char        *ft_strjoin(char *s1, char *s2)
{
        char        *str;
        int                i;
        int                j;

        if (s1 == NULL || s2 == NULL)
                return (NULL);
        i = 0;
        j = 0;
        str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
        if (str != NULL)
        {
                while (s1[i])
                {
                        str[i + j] = s1[i];
                        i++;
                }
                while (s2[j])
                {
                        str[i + j] = s2[j];
                        j++;
                }
                str[i + j] = '\0';
        }
        free(s1);
        return (str);
}

char        *ft_substr(char *str, int start, int size)
{
        char        *new_str;
        int                len;
        int                i;

        if (str == NULL)
                return (NULL);
        if (start > ft_strlen(str))
                return (ft_strdup(""));
        len = ft_strlen(&str[start]);
        if (len < size)
                size = len;
        new_str = malloc((size + 1) * sizeof(char));
        if (new_str == NULL)
                return (NULL);
        i = 0;
        while (i < size)
        {
                new_str[i] = str[start];
                start++;
                i++;
        }
        new_str[i] = '\0';
        return (new_str);
}
