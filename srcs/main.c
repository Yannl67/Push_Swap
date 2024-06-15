/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamouri <ylamouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:03:11 by ylamouri          #+#    #+#             */
/*   Updated: 2024/06/15 16:21:09 by ylamouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	free_ptr(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

static void	free_av(int split_used, char	**av)
{
	int	i;

	i = -1;
	if (split_used)
	{
		while (++i, av[i])
			free_ptr(av[i]);
		free_ptr(av);
	}
}

static void	sorting(t_stack	**stack_a, t_stack	**stack_b)
{
	if (!ft_is_sorted(stack_a))
	{
		if (stack_len(*stack_a) == 2)
			sa(stack_a);
		else
			quick_sort(stack_a, stack_b);
	}
}

static void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (NULL == stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		split_used;

	split_used = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2 || !av[1][0])
		return (1);
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		split_used = 1;
	}
	if (!check_args(ac, av))
	{
		free_av(split_used, av);
		return (ft_error());
	}
	stack_init(&stack_a, av, ac);
	sorting(&stack_a, &stack_b);
	free_av(split_used, av);
	free_stack(&stack_a);
	return (0);
}
