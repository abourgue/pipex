/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:12:13 by abourgue          #+#    #+#             */
/*   Updated: 2023/03/23 11:35:11 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strchr(const char *string, int searchedChar)
{
	char	*str;

	str = (char *)string;
	while (*str != (char)searchedChar)
	{
		if (*str == '\0' && (char)searchedChar == '\0')
			return (str);
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (str);
}
