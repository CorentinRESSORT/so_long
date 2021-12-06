#include "../includes/so_long.h"

static	int		verifLine(char **files, file f)
{
	int i;

	i = 0;
	while (i < f.nbchar)
	{
		if (files[0][i] != '1' || files[f.nbline - 1][i] != '1')
			return (-1);
		i++;
	}
	return (0);
}

static	int		verifFlag(file f)
{
	if (f.exit && f.player && f.col)
		return (0);
	return (-1);
}
static	void		count_flag(char **files, file *f)
{
	int i;
	int y;

	y = 0;
	i = 0;
	while (i < f->nbline)
	{
		y = 0;
		while (y < f->nbchar)
		{
			if (files[i][y] == '0')
				f->space += 1;
			if (files[i][y] == 'C')
				f->col+= 1;
			if (files[i][y] == '1')
				f->wall += 1;
			if (files[i][y] == 'E')
				f->exit += 1;
			if (files[i][y] == 'P')
				f->player += 1;
			y++;
		}
		i++;
	}
}

static	int	control_map(file f)
{
	if (f.nbline == f.nbchar)
		return (-1);
	return (0);
}


int	control_file(char **files, file *f)
{
	count_flag(files, f);
	if (verifLine(files, *f) == -1 || verifFlag(*f) == -1 
		|| control_map(*f) == -1)
		return (-1);
	return (1);
}
