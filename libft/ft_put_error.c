#include "includes/libft.h"
#include <stdlib.h>

void		ft_put_error(char *s, int fd, int error)
{
	ft_putendl_fd(s, fd);
	exit(error);
}