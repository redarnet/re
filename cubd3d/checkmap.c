/*
void	checkmap(struct data_s data, int x, int y)
{
	char	**map;

	p->pl->pos = 0;
	map = data.map[x][y];
	if (map[x][y] == 1)
		return ;
	if (x == 0 || y == 0 )
		ft_putstr_fd("ERROR: MAP NOT CLOSED AROUND SPAWN\n", 1);
	if (map[x][y] == 0)
		map[x][y] = 3;
//	if (map[x][y] == 2)
//&		map[x][y] = 4;
	checkmap(p, x + 1, y);
	checkmap(p, x, y + 1);
	checkmap(p, x - 1, y);
	checkmap(p, x, y - 1);
}
*/
