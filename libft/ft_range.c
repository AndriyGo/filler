/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agordiyc <agordiyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:27:06 by agordiyc          #+#    #+#             */
/*   Updated: 2017/11/29 18:47:10 by agordiyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *ret;
	int *point;

	if (max <= min)
		return (0);
	if ((ret = (int *)malloc((max - min) * sizeof(int))) == 0)
		return (0);
	point = ret;
	while (min < max)
		*(ret++) = min++;
	return (point);
}
