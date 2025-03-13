/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:30:03 by nhaber            #+#    #+#             */
/*   Updated: 2025/02/24 19:29:04 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	parse_input(char **input, int count, int **data)
{
	int	i;
	int	j;
	int	ftatoi;
	int	error;

	i = 0;
	j = 1;
	while (i < count - 1)
	{
		error = new_atoi(input[j], &ftatoi);
		if (error == 0)
		{
			return (false);
		}
		(*data)[i] = ftatoi;
		i++;
		j++;
	}
	return (true);
}
