/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 13:35:02 by lguiller          #+#    #+#             */
/*   Updated: 2020/09/09 13:43:44 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_CLASS_HPP
# define GAME_CLASS_HPP

class	Game {
public:
	Game(void);
	Game(int width, int length);
	Game(const Game &cpy);
	~Game(void);

	Game	&operator=(const Game &rhs);
	int		neyghbors(int x, int y);

	int		width;
	int		length;
	char	**board;
};

#endif
