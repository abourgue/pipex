/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:23:32 by abourgue          #+#    #+#             */
/*   Updated: 2023/03/23 11:36:26 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	is_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*res;
	int		i;
	int		j;
	int		size;

	j = ft_strlen(s1) - 1;
	i = 0;
	while (is_set(s1[i], set))
		i++;
	while (j > 0 && is_set(s1[j], set))
		j--;
	size = j - i + 1;
	if (size < 1)
		size = 0;
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (!res)
		return (res);
	size = 0;
	while (i < j + 1)
		res[size++] = s1[i++];
	res[size] = '\0';
	return (res);
}
