/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_atoi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 14:54:22 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/23 15:50:44 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		p_atoi(const char *str, t_flag flags)
{
	int					is_neg;
	unsigned long long	res;

	is_neg = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		is_neg = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	res = 0;
	while (str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	if ((res > 2147483648 && is_neg == -1) || (res > 2147483647 && is_neg == 1))
	{
		print_error(3, flags);
		exit(0);
	}
	return ((int)res * is_neg);
}
