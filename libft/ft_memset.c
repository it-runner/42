/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoehne <phoehne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:54:41 by phoehne           #+#    #+#             */
/*   Updated: 2024/12/12 16:04:28 by phoehne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	The memset() function fills the first n bytes of the memory area
	pointed to by s with the constant byte c.

	The memset() function returns a pointer to the memory area s.
*/

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t			i;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *)ptr;
	while (i < num)
	{
		s[i] = (unsigned char)value;
		i++;
	}
	return (ptr);
}
