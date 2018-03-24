/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:26:20 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/24 18:00:06 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		usage(void)
{
	ft_putstr_fd("usage ./checker [-e] [list_of_integers]\n", 2);
	ft_putstr_fd("	[-e] show error details\n", 2);
	exit(1);
}
