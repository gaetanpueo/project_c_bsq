/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrixx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpueo--g <gpueo--g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/18 15:26:21 by gpueo--g          #+#    #+#             */
/*   Updated: 2014/09/18 15:37:27 by gpueo--g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

void	populateleftline(t_grid board, int *memo)
{
	int		j;
	char	c;
	int		args[3];

	j = 0;
	while (j < board.width)
	{
		c = getat(j, 0, board);
		buildargs(args, j, 0, board.width);
		setmemoat(args, memo, c == board.empty_char ? 1 : 0);
		j++;
	}
}

void	populateat(int i, int j, t_grid board, int *memo)
{
	int		val;
	int		val1;
	int		val2;
	int		val3;
	int		args[3];
	char	c;

	c = getat(j, i, board);
	if (c == board.empty_char)
	{
		val1 = getmemoat(j - 1, i, board.width, memo);
		val2 = getmemoat(j, i - 1, board.width, memo);
		val3 = getmemoat(j - 1, i - 1, board.width, memo);
		val = ft_min2(val1, val2, val3) + 1;
		buildargs(args, j, i, board.width);
		setmemoat(args, memo, val);
	}
	else
	{
		buildargs(args, j, i, board.width);
		setmemoat(args, memo, 0);
	}
}

void	populateall(t_grid board, int *memo)
{
	int		j;
	int		i;

	i = 1;
	while (i < board.height)
	{
		j = 1;
		while (j < board.width)
		{
			populateat(i, j, board, memo);
			j++;
		}
		i++;
	}
}

void	findbiggestsquare(t_grid board, int square[])
{
	int		*memo;

	memo = buildmemboard(board.width, board.height);
	populatetopline(board, memo);
	populateleftline(board, memo);
	populateall(board, memo);
	findmaxsquarefrommemo(memo, board.width, board.height, square);
	free(memo);
}

void	populatetopline(t_grid board, int *memo)
{
	int		i;
	int		args[3];
	char	c;

	i = 0;
	while (i < board.height)
	{
		c = getat(0, i, board);
		buildargs(args, 0, i, board.width);
		setmemoat(args, memo, c == board.empty_char ? 1 : 0);
		i++;
	}
}
