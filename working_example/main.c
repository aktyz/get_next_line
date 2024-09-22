#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	fd;
	int	i;

	i = 0;
	if (argc != 2)
		return (1);
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (1);
		while (i < 7)
		{
			printf("%s", get_next_line(fd));
			i++;
		}
		printf("\n");
		close(fd);
	}
	return (0);
}

// int	main(void)
// {
// 	int	fd1;
// 	int	fd2;
// 	int	i;

// 	i = 0;
// 	fd1 = open("tests/test00", O_RDONLY);
// 	if (fd1 == -1)
// 		return (1);
// 	fd2 = open("tests/test03", O_RDONLY);
// 	if (fd2 == -1)
// 		return (1);
// 	while (i < 7)
// 	{
// 		printf("%s%s", get_next_line(fd1), get_next_line(fd2));
// 		i++;
// 	}
// 	printf("\n");
// 	close(fd1);
// 	close(fd2);
// 	return (0);
// }
