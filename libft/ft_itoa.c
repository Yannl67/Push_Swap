/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamouri <ylamouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:03:08 by ylamouri          #+#    #+#             */
/*   Updated: 2024/06/15 16:25:20 by ylamouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	trouve_taille(int n);

char	*ft_itoa(int n)
{
	char	*result;
	int		negatif;	

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	negatif = 0;
	if (n < 0)
	{
		n *= -1;
		negatif = 1;
	}
	result = ft_calloc(trouve_taille(n) + negatif + 1, sizeof(char));
	if (!result)
		return (NULL);
	while (n)
	{
		result[trouve_taille(n) + negatif - 1] = (n % 10) + 48;
		n /= 10;
	}
	if (negatif)
		result[0] = '-';
	return (result);
}

int	trouve_taille(int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}
