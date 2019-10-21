/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   testing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/04 16:28:09 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 19:20:12 by nsalle      ###    #+. /#+    ###.fr     */
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

	ft_putendl("\n");
	int i = 0;
	while (lem->room_matrix[i])
	{
		ft_putendl(lem->room_matrix[i]);
		i++;
	}
	ft_putendl("\n");
}
