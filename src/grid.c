/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpueo--g <gpueo--g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/18 15:26:21 by gpueo--g          #+#    #+#             */
/*   Updated: 2014/09/18 15:37:27 by gpueo--g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

int		lineindex(int linenumber, t_grid board)
{
	return (board.grid_start_index + (linenumber * (board.width + 1)));
}

int		indexat(int x, int y, t_grid board)
{
	return (lineindex(y, board) + x);
}

char	getat(int x, int y, t_grid board)
{
	int index;

	index = indexat(x, y, board);
	return (board.content[index]);
}

void	setat(int x, int y, t_grid board)
{
	int		index;

	index = indexat(x, y, board);
	board.content[index] = board.square_char;
}

int		hasobstacles(int x, int y, int size, t_grid board)
{
	int		i;
	int		j;
	int		maxy;
	int		maxx;

	i = x;
	j = y;
	maxy = y + size - 1;
	maxx = x + size - 1;
	if (maxy >= board.height || maxx >= board.width)
	{
		return (1);
	}
	while (j <= maxy)
	{
		i = x;
		while (i <= maxx)
		{
			if (getat(i, j, board) == board.obstacle_char)
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}
