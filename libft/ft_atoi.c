/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:14:37 by abourgue          #+#    #+#             */
/*   Updated: 2023/03/23 11:32:57 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_atoi(const char *str)
{
	char	*lst;
	int		neg;
	long	res;
	int		i;

	lst = (char *)str;
	neg = 1;
	res = 0;
	i = 0;
	while (lst[i] == ' ' || lst[i] == '\n' || lst[i] == '\t' || lst[i] == '\v'
		|| lst[i] == '\f' || lst[i] == '\r')
		i++;
	if (lst[i] == '-' || lst[i] == '+')
	{
		if (lst[i] == '-')
			neg *= -1;
		i++;
	}
	while (lst[i] >= 48 && lst[i] <= 57)
	{
		res = res * 10 + (lst[i] - 48);
		lst++;
	}
	return (res * neg);
}
