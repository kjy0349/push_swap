/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:52:10 by jeykim            #+#    #+#             */
/*   Updated: 2022/11/03 17:54:28 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include "./libft/libft.h"
#include <stdio.h>

int	print_error(int type)
{
	if (type >= 1)
		write(2, "Error\n", 7);
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

void	free_stack(t_stack *stack)
{
	int		idx;
	t_node	*n_idx;
	t_node	*tmp;

	idx = 0;
	n_idx = stack->bot->next;
	while (idx < stack->size)
	{
		tmp = n_idx;
		free(tmp);
		n_idx = n_idx->next;
		idx++;
	}
	tmp = NULL;
	free(stack->top);
	free(stack->bot);
	stack->top = NULL;
	stack->bot = NULL;
}

void	sort_triple(t_info *info)
{
	int	top;
	int	bot;
	int	mid;

	top = info->a->top->prev->data;
	bot = info->a->bot->next->data;
	mid = info->a->bot->next->next->data;
	if (top < mid && mid > bot && top < bot)
	{
		sa(info);
		ra(info);
	}
	else if (top > mid && mid < bot && top < bot)
		sa(info);
	else if (top < mid && mid > bot && top > bot)
		rra(info);
	else if (top > mid && bot > mid && top > bot)
		ra(info);
	else if (top > mid && mid > bot && top > bot)
	{
		sa(info);
		rra(info);
	}
}

void	divide_triple(t_info *info, int piv1, int piv2)
{
	if (info->a->top->prev->data < piv1)
	{
		pb(info);
		rb(info);
	}
	else if (info->a->top->prev->data < piv2)
		pb(info);
	else
		ra(info);
}

void	set_pivot_divide(t_info *info)
{
	int	idx;
	int	piv1;
	int	piv2;
	int	*array;

	array = info->array;
	idx = info->a->size / 3;
	piv1 = (info->array)[idx];
	piv2 = (info->array)[idx * 2];
	idx = info->a->size;
	while (idx > 0)
	{
		divide_triple(info, piv1, piv2);
		idx--;
	}
}

void	sort_all(t_info *info)
{
	set_pivot_divide(info);
	while (info->a->size > 3)
		pb(info);
}

void	sort_elem(t_info *info)
{
	if (info->a->size == 2)
	{
		if (info->a->bot->next->data > info->a->top->prev->data)
		{
			sa(info);
		}
	}
	else if (info->a->size == 3)
		sort_triple(info);
	else
		sort_all(info);
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
	info.array = arr;
	arr_to_stack(&info, arr, arr_size);
	sort_elem(&info);
	free(info.array);
	system("leaks push_swap");
}
