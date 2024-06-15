/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamouri <ylamouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:00:35 by ylamouri          #+#    #+#             */
/*   Updated: 2024/06/15 16:22:14 by ylamouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-' && num[1] != '\0')
		i++;
	while (num[i])
	{
		if (ft_isdigit(num[i]))
			i++;
		else
		{
			return (0);
		}
	}
	return (1);
}

static int	repetition(char *number, char **av, int ac)
{
	int	i;
	int	time;
	int	nbr;

	time = 0;
	i = 0;
	if (ac != 2)
		i = 1;
	nbr = ft_atoi(number);
	while (av[i])
	{
		if (nbr == ft_atoi(av[i]))
			time++;
		i++;
	}
	if (time > 1)
		return (1);
	return (0);
}

int	check_args(int ac, char **av)
{
	int		i;
	long	tmp;

	i = 0;
	if (ac != 2)
		i = 1;
	while (av[i])
	{
		tmp = ft_atoi(av[i]);
		if (tmp < INT_MIN || tmp > INT_MAX)
		{
			return (0);
		}
		if (!ft_isnum(av[i]))
		{
			return (0);
		}
		if (repetition(av[i], av, ac))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
