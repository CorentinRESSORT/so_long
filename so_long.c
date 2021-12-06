#include "includes/so_long.h"

void	init_flag(file *f)
{
	f->nbchar = 0;
	f->nbline = 0;
	f->fd = 0;
	f->col = 0;
	f->space = 0;
	f->wall = 0;
	f->exit = 0;
	f->player = 0;
	f->c = 0;
	f->fname = 0;
	f->parsed_file = 0;

}

int	ft_strlen(char *s1)
{
	int i;
	
	i = 0;
	while (s1[i])
		i++;
	return (i);
}

int	strcont(char *s1, char *s2)
{
	int i;
	int y;

	i = ft_strlen(s1);
	y = ft_strlen(s2);

	while (y)
	{
		if (s1[i] != s2[y])
			return (0);
		i--;
		y--;
	}
	return (1);
}

int		count(file *f)
{
	int i;
	int	error;

	i = 0;
	error = read(f->fd, &f->c, 1);
	while(error && error != -1)
	{
		if (f->c == '\n')
			f->nbline++;
		else
			i++;
		error = read(f->fd, &f->c, 1);
	}
	if (error == -1)
		return (-1);
	f->nbline++;
	f->nbchar = i / f->nbline;
	return (0);
}

int main(int argc, char **argv)
{
	file f;

	init_flag(&f);
	f.fname = argv[1];
	f.fd = open(f.fname, 'r');
	count(&f);
	close(f.fd);
	f.parsed_file = parse_file(&f);
	if (argc != 2 || f.fd == -1 || control_file(f.parsed_file, &f) == -1)
	{
		printf("Error file");
		return (0);
	}
	return 0;
}