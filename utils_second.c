/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_second.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:51:02 by alex              #+#    #+#             */
/*   Updated: 2021/01/14 19:55:48 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printfhead.h"

int					ft_find_max(int a, int b)
{
	return ((a) > (b) ? (a) : (b));
}

char				ft_check_hex(char tag, char check)
{
	if ((tag == 'x' || tag == 'p') && check >= 'A' && check <= 'F')
		return (check + 32);
	else
		return (check);
}

void				ft_define_pointer(unsigned long n,
									t_struct *blocks, int base)
{
	unsigned long	tmp;

	tmp = n;
	while (tmp > 0)
	{
		blocks->chars_to_print++;
		tmp /= base;
	}
	blocks->width -= 2;
	ft_print_p(n, blocks, base);
	return ;
}
