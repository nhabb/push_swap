/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 22:06:47 by nhaber            #+#    #+#             */
/*   Updated: 2025/02/18 22:06:47 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

bool	is_valid_number(char *str)
{
	long long	num;
	int			j;
	int			sign;

	num = 0;
	j = 0;
	sign = 1;
	if (str[0] == '-')
	{
		j = 1;
		sign = -1;
	}
	if (str[j] == '\0')
		return (false);
	while (str[j] != '\0')
	{
		if (!(str[j] >= '0' && str[j] <= '9'))
			return (false);
		num = num * 10 + (str[j] - '0');
		if ((sign * num) < INT_MIN || (sign * num) > INT_MAX)
			return (false);
		j++;
	}
	return (true);
}

bool	numerical(char **arg, int i)
{
	while (arg[i] != NULL)
	{
		if (!is_valid_number(arg[i]))
			return (false);
		i++;
	}
	return (true);
}

void	process(t_stack_node **a, char **list, int i)
{
	int	value;

	if (!is_numeric(list, i))
		return ;
	while (list[i])
	{
		value = new_atoi(list[i]);
		stack_add_back(a, stack_new(value));
		i++;
	}
}

void	subprocess(t_stack_node **a, char **argv)
{
	char	**list;

	list = ft_split_charset(argv[1], " \n\t\v\f\r");
	process(a, list, 0);
	free_str(list);
}

void	multi_args(t_stack_node **a, char **argv)
{
	char	*combined_args;
	char	**list;
	int		i;

	combined_args = ft_strdup("");
	i = 1;
	while (argv[i])
	{
		combined_args = ft_strjoin_and_free(combined_args, argv[i++]);
		combined_args = ft_strjoin_and_free(combined_args, " ");
	}
	list = ft_split_charset(combined_args, " \n\t\v\f\r");
	free(combined_args);
	process(a, list, 0);
	free_str(list);
}
