/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:46:52 by abourgue          #+#    #+#             */
/*   Updated: 2023/03/23 11:36:22 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *string, int searchedChar)
{
	char	*str;
	char	*oc;

	str = (char *)string;
	oc = NULL;
	while (*str != '\0')
	{
		if (*str == (char)searchedChar)
			oc = str;
		str++;
	}
	if ((char)searchedChar == '\0')
		return (str);
	return (oc);
}
