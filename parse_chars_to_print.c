/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_chars_to_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:08:24 by alex              #+#    #+#             */
/*   Updated: 2021/01/13 17:25:41 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printfhead.h"

void	ft_define_n_digits(int n, t_struct *blocks, int base)
{
	unsigned int tmp;

	if (n < 0 && base == 10)
	{
		tmp = -n;
		blocks->neg_number = 1;
	}
	else
		tmp = n;
	if (n == 0)
		blocks->chars_to_print++;
	while (tmp > 0)
	{
		blocks->chars_to_print++;
		tmp /= base;
	}
	ft_order_to_print_digits(blocks, n, base);
	return ;
}

void	ft_def_u_digits(unsigned int n, t_struct *blocks, int base)
{
	unsigned int tmp;

	tmp = n;
	if (tmp == 0)
		blocks->chars_to_print++;
	while (tmp > 0)
	{
		blocks->chars_to_print++;
		tmp /= base;
	}
	ft_order_to_print_u_digits(blocks, n, base);
	return ;
}
