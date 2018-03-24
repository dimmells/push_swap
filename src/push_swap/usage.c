/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:26:20 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/24 11:47:57 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		usage(void)
{
	ft_putstr_fd("usage ./push_swap [-c [-a]] [-e] [-v [-p]] [-s] ", 2);
	ft_putstr_fd("[list_of_integers]\n", 2);
	ft_putstr_fd("	[-c] show in colours the last operation\n", 2);
	ft_putstr_fd("		[-a] show in colours all operations\n", 2);
	ft_putstr_fd("	[-e] show error details\n", 2);
	ft_putstr_fd("	[-v] display the stack’s status after each operation\n", 2);
	ft_putstr_fd("		[-p] show in colours each stack\n", 2);
	ft_putstr_fd("	[-s] display statistics\n", 2);
	exit(1);
}
