/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:59:49 by abourgue          #+#    #+#             */
/*   Updated: 2023/03/23 11:35:26 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin(const char *str1, const char *str2)
{
	char	*res;
	int		size;
	int		i;
	int		j;

	i = 0;
	j = 0;
	size = ft_strlen(str1) + ft_strlen(str2);
	res = malloc(sizeof(*res) * size + 1);
	if (!res)
		return (res);
	while (i < size && str1[i])
	{
		res[i] = str1[i];
		i++;
	}
	while (i < size && str2[j])
		res[i++] = str2[j++];
	res[i] = '\0';
	return (res);
}
