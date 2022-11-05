/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:29:25 by jeykim            #+#    #+#             */
/*   Updated: 2022/11/05 16:32:24 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(char c)
{
	if (c == '\n' || c == '\v' || c == '\t' \
	|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoichk(const char *str, int i)
{
	int					sign;
	long				ret;
	int					chk;

	sign = 1;
	ret = 0;
	chk = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = -1;
		if (str[i] == '\0')
			print_error(1);
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
		idx++;
	}
	free(parsed_str);
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
	free(stack->top);
	free(stack->bot);
}
