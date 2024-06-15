/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamouri <ylamouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:03:08 by ylamouri          #+#    #+#             */
/*   Updated: 2024/06/15 16:27:34 by ylamouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "limits.h"
# include <stdbool.h>

typedef struct s_stack
{
	int					value;
	int					current_position;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_stack		*target_node;
	struct s_stack		*next;
	struct s_stack		*prev;
}	t_stack;

// *** SRCS ***

void	stack_init(t_stack	**stack_a, char **av, int ac);
void	tiny_sort(t_stack **a);
void	quick_sort(t_stack **stack_a, t_stack **stack_b);
void	set_current_position(t_stack *stack);
void	set_price(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *b);
void	init_nodes(t_stack *a, t_stack *b);

// *** UTILS ***

int		check_args(int ac, char **av);
int		ft_error(void);

// *** T_STACK ***

int		ft_is_sorted(t_stack **stack);
void	append_node(t_stack **stack, int nbr);
t_stack	*find_last_node(t_stack *head);
int		stack_len(t_stack *stack);
t_stack	*return_cheapest(t_stack *stack);
t_stack	*find_smallest(t_stack	*stack);

// *** INSTRUCTOIN ***

void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rra(t_stack **a);
void	ss(t_stack **a, t_stack **b);
void	sb(t_stack **b);
void	sa(t_stack	**a);

#endif