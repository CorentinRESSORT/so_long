#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
typedef		struct file{
			int 	nbchar;
			int		nbline;
			int		fd;
			int		col;
			int		space;
			int		wall;
			int		exit;
			int		player;
			char	c;
			char	*fname;
			char	**parsed_file;
}			file;

typedef		struct{
			int	pos_x;
			int	pos_y;
			
}			game;

char **parse_file(file *f);
int	control_file(char **files, file *f);

#endif