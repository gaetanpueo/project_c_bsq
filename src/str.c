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

char	*ft_strcat_s(char *strd, char *stra, int olds, int adds)
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
		str = ft_strcat_s(str, buf, ft_strlen(str), ft_strlen(buf));
	}
	return (str);
}
