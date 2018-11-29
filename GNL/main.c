#include "get_next_line.h"
#include <fcntl.h>

int		main(void)
{
	char *line;
	int fd;

	fd = open("test", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		ft_putendl(line);
		ft_strdel(&line);
	}
	close(fd);
	return (0);
}
