/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpueo--g <gpueo--g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/18 15:26:21 by gpueo--g          #+#    #+#             */
/*   Updated: 2014/09/18 15:37:27 by gpueo--g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

int		checkvalidchars(t_grid board)
{
	int		i;
	int		length;

	i = board.grid_start_index;
	length = board.contentlength;
	while (i < length)
	{
		if (!(board.content[i] == board.empty_char
			|| board.content[i] == board.obstacle_char
			|| board.content[i] == '\n'))
			return (0);
		i++;
	}
	return (1);
}

int		checklinewidth(t_grid board)
{
	int		i;

	i = 0;
	while (i < board.height)
	{
		if (getat(board.width, i, board) != '\n')
			return (0);
		i++;
	}
	return (1);
}

int		isvalidgrid(t_grid board)
{
	if (board.width == 0 || board.height == 0)
		return (0);
	if (ft_count_char(board.content, '\n') != board.height + 1)
		return (0);
	if (!checkvalidchars(board))
		return (0);
	if (!checklinewidth(board))
		return (0);
	return (1);
}

void	processfile(int file_desc)
{
	int		square[3];
	t_grid	board;

	square[0] = -1;
	square[1] = -1;
	square[2] = -1;
	board = creategrid(file_desc);
	if (isvalidgrid(board))
	{
		findbiggestsquare(board, square);
		drawsquare(board, square);
		printgridcontent(board);
	}
	else
		write(1, "map error\n", 10);
	freegrid(board);
}

int		main(int argc, char **argv)
{
	int		i;
	int		file_desc;

	if (argc == 1)
		processfile(0);
	else
	{
		i = 1;
		while (i < argc)
		{
			file_desc = open(argv[i], O_RDONLY);
			if (file_desc < 0)
				return (1);
			processfile(file_desc);
			i++;
		}
	}
	return (0);
}
