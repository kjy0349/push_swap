/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoung <jeyoung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:52:10 by jeykim            #+#    #+#             */
/*   Updated: 2022/11/02 14:40:41 by jeyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include "./libft/libft.h"
#include <stdio.h>

int	print_error(int type)
{
	if (type >= 1)
	{
		write(2, "Error\n", 7);
	}
	system("leaks a.out");
	exit(1);
	return (-1);
}

int	ft_isspace(char c)
{
	if (c == '\n' || c == '\v' || c == '\t' \
	|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoichk(const char *str)
{
	int					i;
	int					sign;
	long				ret;

	sign = 1;
	ret = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = ret * 10 + (str[i] - '0');
		i++;
	}
	ret *= (long)sign;
	if (str[i] != '\0' || ret > 2147483647 || ret < -2147483648)
		print_error(1);
	return ((int)(ret));
}

int	split_size(char **parsed_str)
{
	int	idx;

	idx = 0;
	while (parsed_str[idx])
		idx++;
	return (idx);
}

void	free_split(char **parsed_str)
{
	int	idx;

	idx = 0;
	while (parsed_str[idx])
	{
		free(parsed_str[idx]);
		parsed_str[idx] = NULL;
		idx++;
	}
	free(parsed_str);
	parsed_str = NULL;
}

void	set_str_array(int *array, int *arr_idx, char **str)
{
	int	tmp;
	int	idx;

	idx = 0;
	while (str[idx])
	{
		tmp = ft_atoichk(str[idx]);
		array[*arr_idx] = tmp;
		(*arr_idx)++;
		idx++;
	}
}

int	get_input_size(int argc, char *argv[])
{
	int		idx;
	int		size;
	int		elem_cnt;
	char	**parsed_str;

	idx = 1;
	size = 0;
	while (idx < argc)
	{
		elem_cnt = 0;
		while (argv[idx][elem_cnt])
		{
			if (!ft_isspace(argv[idx][elem_cnt]))
				break ;
			elem_cnt++;
		}
		if (argv[idx][elem_cnt] == '\0')
			print_error(1);
		parsed_str = ft_split(argv[idx], ' ');
		size += split_size(parsed_str);
		free_split(parsed_str);
		idx++;
	}
	return (size);
}

int	*make_array(int argc, char *argv[], int size)
{
	int		ac_idx;
	int		arr_idx;
	int		*array;
	char	**split_str;

	ac_idx = 1;
	arr_idx = 0;
	array = (int *)malloc(sizeof(int) * (size + 1));
	if (!array)
		print_error(1);
	while (ac_idx < argc)
	{
		split_str = ft_split(argv[ac_idx], ' ');
		set_str_array(array, &arr_idx, split_str);
		free_split(split_str);
		ac_idx++;
	}
	array[arr_idx] = '\0';
	return (array);
}

void	arr_to_stack(t_info *info, int *array, int size)
{
	int		idx;

	idx = size - 1;
	while (idx >= 0)
	{
		add(info->a, array[idx]);
		idx--;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	t_info	info;
	int		arr_size;
	int		*arr;

	if (argc < 2)
		print_error(-1);
	arr_size = 0;
	init_stack(&a);
	init_stack(&b);
	info.a = &a;
	info.b = &b;
	arr_size = get_input_size(argc, argv);
	arr = make_array(argc, argv, arr_size);
	arr_to_stack(&info, arr, arr_size);
	print_stack(&info);
	system("leaks a.out");
}
