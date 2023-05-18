/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:05:05 by abourgue          #+#    #+#             */
/*   Updated: 2023/03/23 11:33:34 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_isalnum(int x)
{
	if ((x >= '0' && x <= '9') || (x >= 'A' && x <= 'z'))
	{
		if (x > 'Z' && x < 'a')
			return (0);
		return (1);
	}
	return (0);
}
