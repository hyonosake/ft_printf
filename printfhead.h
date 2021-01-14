/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfhead.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:42:04 by alex              #+#    #+#             */
/*   Updated: 2021/01/14 19:56:23 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTFHEAD_H
# define PRINTFHEAD_H
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct		s_struct
{
	char			format;
	int				f_minus;
	int				f_zero;
	int				neg_number;
	int				width;
	int				precision;
	int				total_printed;
	int				skipped_chars;
	int				chars_to_print;
	int				f_prec;
	int				f_width;
	va_list			args;

}					t_struct;

void				ft_struct_clean(t_struct *blocks);
int					ft_printf(const char *format, ...);
void				ft_parse_flags(const char *format, t_struct *blocks);
int					ft_isdigit(char ch);
int					ft_isformat(char format);
void				parse_width(const char *format, t_struct *blocks);
void				ft_parse_precision(const char *format, t_struct *blocks);
void				ft_parse_format(const char *format, t_struct *blocks);
void				ft_define_n_digits(int n, t_struct *blocks, int base);
void				ft_order_to_print_digits(t_struct *blocks, int n, int base);
int					ft_find_max(int a, int b);
void				ft_print_width_digits(t_struct *blocks);
void				ft_print_precision_digits(t_struct *blocks);
char				ft_check_hex(char tag, char check);
void				ft_putnbr_base(int n, t_struct *blocks, int base);
void				ft_print_width_string(char *s, t_struct *blocks);
void				ft_print_precision_string(char *s, t_struct *blocks);
int					ft_strlen(char *s);
int					ft_find_min(int a, int b);
void				ft_order_to_print_string(char *s, t_struct *blocks);
void				ft_order_to_print_char(int pos, t_struct *blocks);
void				ft_print_negative_int(int n, t_struct *blocks, int base);
void				ft_print_zero_valued_int(int n, t_struct *blocks, int base);
void				ft_print_positive_int(int n, t_struct *blocks, int base);
void				ft_def_u_digits(unsigned int n, t_struct *blocks, int base);
void				ft_init_pointer(t_struct *blocks);
void				ft_print_p(unsigned long n, t_struct *blocks, int base);
void				ft_print_null_pointer(t_struct *blocks);
void				print_not_format_like_format(char ch, t_struct *blocks);
void				ft_print_null_pointer_no_f_m(t_struct *blocks);
void				ft_order_to_print_u_digits(t_struct *blocks,
											unsigned int n, int base);
void				ft_print_neg_int_no_f_minus(int n,
											t_struct *blocks, int base);
void				ft_print_zero_valued_u(unsigned int n,
											t_struct *blocks, int base);
void				ft_print_positive_u(unsigned int n,
											t_struct *blocks, int base);
void				ft_putnbr_base_u(unsigned int n,
											t_struct *blocks, int base);
void				ft_putnbr_pointer(unsigned long n,
									t_struct *blocks, int base);
void				ft_define_pointer(unsigned long n,
									t_struct *blocks, int base);
#endif
