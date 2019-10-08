/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   testing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/04 16:28:09 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/08 22:17:50 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

# include "lem_in.h"

void	test(t_lem *lem)
{
	ft_printf("Nombre de fourmis: %lld\n", lem->nb_ant);
	ft_printf("Nombre de salles: %d\n", lem->nb_room);
	ft_printf("La salle de depart est: '%s'\n", lem->start);
	ft_printf("La salle de fin est   : '%s'\n", lem->end);

	// int i = 0;
	// while (lem->tabfile[i])
	// {
	// 	ft_putendl(lem->tabfile[i]);
	// 	i++;
	// }
}