/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrixxx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpueo--g <gpueo--g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/18 15:26:21 by gpueo--g          #+#    #+#             */
/*   Updated: 2014/09/18 15:37:27 by gpueo--g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

char	getmemoat(int x, int y, int width, int boardcontent[])
{
	int		index;

	index = (y * width) + x;
	return (boardcontent[index]);
}

char	setmemoat(int square[], int boardcontent[], int val)
{
	int		index;
	int		x;
	int		y;
	int		width;

	x = square[0];
	y = square[1];
	width = square[2];
	index = (y * width) + x;
	return (boardcontent[index] = val);
}
