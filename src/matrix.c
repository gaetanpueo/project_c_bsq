/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpueo--g <gpueo--g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/18 15:26:21 by gpueo--g          #+#    #+#             */
/*   Updated: 2014/09/18 15:37:27 by gpueo--g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

int		*buildmemboard(int width, int height)
{
	return (malloc(width * height * sizeof(int)));
}

void	processlines(int j, int width, int memo[], int square[])
{
	int		i;
	int		v;

	i = 0;
	while (i < width)
	{
		v = getmemoat(i, j, width, memo);
		if (v > square[2])
		{
			square[0] = i - v + 1;
			square[1] = j - v + 1;
			square[2] = v;
		}
		i++;
	}
}

void	findmaxsquarefrommemo(int mem[], int wid, int heig, int sqr[])
{
	int		j;

	j = 0;
	while (j < heig)
	{
		processlines(j, wid, mem, sqr);
		j++;
	}
}

void	buildargs(int args[], int arg1, int arg2, int arg3)
{
	args[0] = arg1;
	args[1] = arg2;
	args[2] = arg3;
}
