/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:59:01 by abourgue          #+#    #+#             */
/*   Updated: 2023/03/23 11:45:03 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memset(void *ptr, int c, size_t len)
{
	char	*str;

	str = ptr;
	while (len)
	{
		*str = c;
		str++;
		len--;
	}
	return (ptr);
}
