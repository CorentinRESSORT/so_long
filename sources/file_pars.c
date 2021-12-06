#include "../includes/so_long.h"

static	char	**create_table(file *f)
{
	int i;
	char **tabF;
	
	i = -1;
	tabF = malloc(sizeof(*tabF) * f->nbline);
	if (tabF == NULL)
	{
		free(tabF);
		return (NULL);
	}
	while (++i < f->nbline)
	{
		tabF[i] = malloc(sizeof(**tabF) * f->nbchar);
		if (tabF[i] == NULL)
		{
			while (i)
				free(tabF[i--]);
			return (NULL);
		}
	}
	return (tabF);
}

char **parse_file(file *f)
{
	int i;
	int y;

	f->parsed_file = create_table(f);
	i = 0;
	y = 0;
	f->fd = open(f->fname, 'r');
	while (i < f->nbline)
	{
		y = 0;
		while (y < f->nbchar)
		{
			read(f->fd, &f->parsed_file[i][y], 1);
			if (f->parsed_file[i][y] != '\n')
				y++;
		}
		f->parsed_file[i][y] = '\0';
		i++;
	}
	close(f->fd);
	return (f->parsed_file);
}