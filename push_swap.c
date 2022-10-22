/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoung <jeyoung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:52:10 by jeykim            #+#    #+#             */
/*   Updated: 2022/10/22 17:49:48 by jeyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include "./libft/libft.h"
#include <stdio.h>

void	print_error(int type)
{
	if (type >= 1)
	{
		write(2, "Error\n", 7);
	}
	exit(1);
	return (-1);
}

int	ft_atoichk(const char *str)
{
	int					i;
	int					sign;
	long				ret;

	sign = 1;
	ret = 0;
	i = 0;
	while (str[i] == '\n' || str[i] == '\v' || str[i] == '\t' \
	|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = ret * 10 + str[i] - '0';
		i++;
	}
	ret *= (long)sign;
	if (str[i] != '\0' || ret > 2147483647 || ret < -2147483648)
		print_error(1);
	return ((int)(ret));
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	t_info	info;
	int		idx;

	if (argc < 2)
		print_error(-1);
	idx = 0;
	init_stack(&a);
	init_stack(&b);
	info.a = &a;
	info.b = &b;
}
