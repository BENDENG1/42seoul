/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 18:34:01 by gyroh             #+#    #+#             */
/*   Updated: 2022/04/18 11:48:15 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	src_i;

	i = 0;
	src_i = 0;
	while (dest[i] != '\0')
		i++;
	while (src[src_i] != '\0' && src_i < nb)
	{
		dest[i] = src[src_i];
		i++;
		src_i++;
	}
	dest[i] = '\0';
	return (dest);
}
