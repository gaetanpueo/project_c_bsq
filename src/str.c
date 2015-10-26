/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpueo--g <gpueo--g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/18 15:26:21 by gpueo--g          #+#    #+#             */
/*   Updated: 2014/09/18 15:37:27 by gpueo--g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *strd, char *stra, int olds, int adds)
{
	int		i;
	int		j;
	char	*str_new;

	i = 0;
	j = 0;
	str_new = (char *)malloc(sizeof(char) * (olds + adds + 1));
	if (str_new == NULL)
		return (NULL);
	while (strd[i])
	{
		str_new[i] = strd[i];
		i++;
	}
	free(strd);
	while (stra[j])
	{
		str_new[i] = stra[j];
		i++;
		j++;
	}
	str_new[i] = '\0';
	return (str_new);
}

int		ft_atoi(char *str)
{
	int		result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ')
		str++;
	if (*str == '-')
		sign = -sign;
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	if (sign == -1)
		result = -result;
	return (result);
}

char	*file_to_str(int fd)
{
	char	buf[BUFFER_SIZE + 1];
	char	*str;
	int		ret;

	str = (char *)malloc(sizeof(char) * 1);
	if (str == NULL)
		return (NULL);
	str[0] = 0;
	while ((ret = read(fd, buf, BUFFER_SIZE)))
	{
		buf[ret] = 0;
		str = ft_strcat(str, buf, ft_strlen(str), ft_strlen(buf));
	}
	return (str);
}

int		countchar(char *str, char token)
{
	int		i;
	int		count;
	int		len;

	i = 0;
	count = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[i] == token)
			count++;
		i++;
	}
	return (count);
}
