/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:29:35 by abourgue          #+#    #+#             */
/*   Updated: 2023/03/23 11:34:13 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t len)
{
	size_t	i;
	char	*pt1;
	char	*pt2;

	pt1 = (char *)ptr1;
	pt2 = (char *)ptr2;
	i = 0;
	while (i < len)
	{
		if (pt1[i] != pt2[i])
			return (((unsigned char *)pt1)[i] - ((unsigned char *)pt2)[i]);
		i++;
	}
	return (0);
}
