/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpueo--g <gpueo--g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/18 15:26:21 by gpueo--g          #+#    #+#             */
/*   Updated: 2014/09/18 15:37:27 by gpueo--g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

char	*sub_str(char *str, int start, int end)
{
	int		strsize;
	char	*out;
	int		i;

	strsize = end - start;
	out = malloc(strsize * sizeof(char));
	i = 0;
	while (i < strsize)
	{
		out[i] = str[start + i];
		i++;
	}
	return (out);
}

int		indexof(char *str, char tofind, int start)
{
	int		i;
	int		length;

	i = start;
	length = ft_strlen(str);
	while (i < length)
	{
		if (str[i] == tofind)
			return (i);
		i++;
	}
	return (-1);
}

int		nindexof(char *str, char tofind, int hit)
{
	int		i;
	int		hitcount;
	int		length;

	i = 0;
	hitcount = 0;
	length = ft_strlen(str);
	while (i < length)
	{
		if (str[i] == tofind)
		{
			if (hitcount == hit)
				return (i);
			hitcount++;
		}
		i++;
	}
	return (-1);
}

int		ft_min(int a, int b)
{
	return (a > b ? b : a);
}

int		ft_min2(int a, int b, int c)
{
	int		m;

	m = ft_min(a, b);
	return (ft_min(m, c));
}
