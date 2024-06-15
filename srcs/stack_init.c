/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamouri <ylamouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:48:40 by ylamouri          #+#    #+#             */
/*   Updated: 2024/06/15 16:21:23 by ylamouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stack_init(t_stack	**stack_a, char **av, int ac)
{
	int	i;

	i = 0;
	if (ac != 2)
		i = 1;
	while (av[i])
	{
		append_node(stack_a, ft_atoi(av[i]));
		++i;
	}
}
