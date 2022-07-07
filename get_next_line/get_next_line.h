#ifndef GNL
# define GNL

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
char    *tidy_history(char **history);
char    *get_line(char **history);
void    trace_line(char **history, int fd);
char	*get_next_line(int fd);
int		ft_strloc(const char *s, int c);
char	*ft_strjoin(char *left_str, char *buff);
int 	ft_strlen(char *str);

#endif