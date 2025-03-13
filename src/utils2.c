/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 11:45:51 by nhaber            #+#    #+#             */
/*   Updated: 2024/08/24 11:45:51 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	strcmp_max(char *max, char *num)
{
	int	lenmax;
	int	lennum;

	lenmax = ft_strlen(max);
	lennum = ft_strlen(num);
	if (lennum > lenmax)
		return (0);
	else if (lennum < lenmax)
		return (1);
	else
	{
		while (*max && *num)
		{
			if (*num > *max)
				return (0);
			else if (*num < *max)
				return (1);
			max++;
			num++;
		}
	}
	return (1);
}
