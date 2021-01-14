/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:50:48 by alex              #+#    #+#             */
/*   Updated: 2021/01/13 17:25:33 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printfhead.h"

void	ft_parse_flags(const char *format, t_struct *blocks)
{
	while (1)
	{
		if (*format == '0')
		{
			blocks->f_zero = 1;
			format++;
			blocks->skipped_chars++;
		}
		else if (*format == '-')
		{
			blocks->f_minus = 1;
			format++;
			blocks->skipped_chars++;
		}
		else
			break ;
	}
	parse_width(format, blocks);
}

void	parse_width(const char *format, t_struct *blocks)
{
	if (*format == '*')
	{
		blocks->f_width = 1;
		blocks->skipped_chars++;
		format++;
		blocks->width = va_arg((blocks->args), int);
		if (blocks->width < 0)
		{
			blocks->f_minus = 1;
			blocks->width = -blocks->width;
		}
		ft_parse_precision(format, blocks);
		return ;
	}
	while (ft_isdigit(*format))
	{
		blocks->f_width = 1;
		blocks->width = blocks->width * 10 + *format - '0';
		format++;
		blocks->skipped_chars++;
	}
	ft_parse_precision(format, blocks);
}

void	ft_parse_precision(const char *format, t_struct *blocks)
{
	if (*format != '.')
		ft_parse_format(format, blocks);
	else
	{
		format++;
		blocks->f_prec = 1;
		blocks->skipped_chars++;
		if (*format == '*')
		{
			blocks->skipped_chars++;
			format++;
			blocks->precision = va_arg((blocks->args), int);
			ft_parse_format(format, blocks);
			return ;
		}
		while (ft_isdigit(*format))
		{
			blocks->precision = blocks->precision * 10 + *format - '0';
			format++;
			blocks->skipped_chars++;
		}
		ft_parse_format(format, blocks);
	}
}

void	ft_parse_format(const char *format, t_struct *blocks)
{
	if (ft_isformat(*format))
	{
		blocks->format = *format;
		format++;
		blocks->skipped_chars++;
		if (blocks->format == 'i' || blocks->format == 'd')
			ft_define_n_digits(va_arg((blocks->args), int), blocks, 10);
		else if (blocks->format == 'x' || blocks->format == 'X')
			ft_define_n_digits(va_arg((blocks->args), int), blocks, 16);
		else if (blocks->format == 'o')
			ft_define_n_digits(va_arg((blocks->args), int), blocks, 8);
		else if (blocks->format == 'u')
			ft_def_u_digits(va_arg((blocks->args), unsigned int), blocks, 10);
		else if (blocks->format == 's')
			ft_order_to_print_string(va_arg((blocks->args), char *), blocks);
		else if (blocks->format == 'p')
			ft_init_pointer(blocks);
		else if (blocks->format == 'c')
			ft_order_to_print_char(va_arg(blocks->args, int), blocks);
		else
			return ;
	}
	else
		print_not_format_like_format(*format, blocks);
}

void	print_not_format_like_format(char ch, t_struct *blocks)
{
	blocks->skipped_chars++;
	ft_order_to_print_char(ch, blocks);
}
