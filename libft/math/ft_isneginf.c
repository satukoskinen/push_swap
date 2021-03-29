/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isneginf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 22:36:38 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/16 21:35:06 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isneginf(double nbr)
{
	return (nbr == -1.0 / 0.0 ? 1 : 0);
}