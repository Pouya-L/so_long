/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:26:23 by plashkar          #+#    #+#             */
/*   Updated: 2023/04/20 19:05:38 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoined;

	strjoined = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!strjoined)
		return (NULL);
	ft_strlcpy(strjoined, s1, (ft_strlen(s1) + 1));
	ft_strlcat(strjoined, s2, ((ft_strlen(s2) + ft_strlen(s1)) + 1));
	return (strjoined);
}

/*int	main(void)
{
	char s1[] = "If you want to join the Peoples Front of Judea, ";
	char s2[] = "you have to really hate the Romans.";
	printf("%s", ft_strjoin(s1, s2));
	return(0);
}*/
