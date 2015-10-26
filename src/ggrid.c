/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ggrid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpueo--g <gpueo--g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/18 16:42:19 by gpueo--g          #+#    #+#             */
/*   Updated: 2014/09/18 16:42:20 by gpueo--g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

t_grid	creategrid(int file_desc)
{
	t_grid	board;
	int		endoffirstline;
	int		endofsecondline;

	board.content = file_to_str(file_desc);
	close(file_desc);
	board.contentlength = ft_strlen(board.content);
	endoffirstline = indexof(board.content, '\n', 0);
	endofsecondline = indexof(board.content, '\n', endoffirstline + 1);
	if (endoffirstline == -1 || endofsecondline == -1)
	{
		board.width = 0;
		board.height = 0;
		return (board);
	}
	board.height = ft_atoi(sub_str(board.content, 0, endoffirstline - 3));
	board.square_char = board.content[endoffirstline - 1];
	board.obstacle_char = board.content[endoffirstline - 2];
	board.empty_char = board.content[endoffirstline - 3];
	board.width = endofsecondline - endoffirstline - 1;
	board.grid_start_index = endoffirstline + 1;
	return (board);
}

void	freegrid(t_grid board)
{
	free(board.content);
}

int		maxsquaresize(t_grid board)
{
	return (ft_min(board.width, board.height));
}

void	printgridcontent(t_grid board)
{
	int offset;

	offset = board.grid_start_index * sizeof(char);
	write(1, board.content + offset, board.contentlength - offset);
}

void	drawsquare(t_grid board, int coordinates[])
{
	int i;
	int j;
	int size;

	i = coordinates[0];
	j = coordinates[1];
	size = coordinates[2];
	while (i < coordinates[0] + size)
	{
		j = coordinates[1];
		while (j < coordinates[1] + size)
		{
			setat(i, j, board);
			j++;
		}
		i++;
	}
}
