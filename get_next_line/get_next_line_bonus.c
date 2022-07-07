#include "get_next_line.h"

char    *tidy_history(char **history)
{
	int     head;
	int     size;
	int     i;
	char    *line;


	head = ft_strloc(*history,'\n');
	size = ft_strlen(*history) - 1 - head;
	if (head == 0){
		size = ft_strlen(*history) - 2;
	}
	if (head == - 1){
		free(*history);
		return NULL;
	}

	line = (char *) malloc(sizeof(char) * size);
	i = 0;
	head++;
	while(i < ft_strlen(*history) - head){
		line[i] = (*history)[i+head];
		i++;
	}
	line[i] = 0;
	if(*history != NULL){
		free(*history);
	}
	return line;
}
char    *get_line(char **history)
{
	int     head;
	int     tail;
	int     size;
	int     i;
	char    *line;

	head = 0;
	i = 0;
	tail = ft_strloc(*history, '\n');
	size = tail - head + 1;
	if (tail == head)
		size = 1;
	if (tail == -1)
		size = ft_strlen(*history) + 2;
	line = (char *) malloc(sizeof(char) * (size+1));
	while(i < size)
		line[i++] = (*history)[head++];
	line[i] = 0;
	return line;
}

void    trace_line(char **history, int fd)
{
	char  *line;
	int   read_bytes;


	read_bytes = 1;
	while(ft_strloc(*history,'\n') == -1 && read_bytes > 0)
	{
		line = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (line == NULL)
			return;
		read_bytes = read(fd, line, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(line);
			break;
		}
		line[read_bytes] = 0;
		*history = ft_strjoin(*history,line);
		free(line);
	}
}

char *get_next_line(int fd)
{
	static char *history[4096];
	char* line;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd,0,0) == -1)
		return (0);
	trace_line(&history[fd],fd);
	if (history[fd][0] == 0)
	{
		free(history[fd]);
		return NULL;
	}
	line = get_line(&history[fd]);
	history = tidy_history(&history[fd]);
	return line;
}

int main(){
	char *line;
	int fd = open("../gnlTester/files/alternate_line_nl_no_nl",O_RDONLY);
	int i = 1;
	if (fd < 0){
		printf("annenin ami");
	}else{
		line = get_next_line(fd);
		while(line != NULL)
		{
			printf("%d:%s",i,line);
			line = get_next_line(fd);
			i++;
		}
	}
}