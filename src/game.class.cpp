/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 13:42:00 by lguiller          #+#    #+#             */
/*   Updated: 2020/09/09 13:55:56 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.class.hpp"

Game::Game(void) : width(0), length(0), board(0) {
	return;
}

Game::Game(int width, int length) : width(width), length(length) {
	this->board = new char *[length];
	for (int y(0) ; y < length ; ++y) {
		this->board[y] = new char [width];
		for (int x(0) ; x < width ; ++x) {
			this->board[y][x] = 0;
		}
	}
	return;
}

Game::Game(const Game &cpy) {
	*this = cpy;
	return;
}

Game::~Game(void) {
	for (int y(0) ; y < this->length ; ++y)
		delete this->board[y];
	delete this->board;
	return;
}

Game	&Game::operator=(const Game &rhs) {
	this->width = rhs.width;
	this->length = rhs.length;
	this->board = new char *[this->length];
	for (int y(0) ; y < this->length ; ++y) {
		this->board[y] = new char [this->width];
		for (int x(0) ; x < this->width ; ++x) {
			this->board[y][x] = rhs.board[y][x];
		}
	}
	return *this;
}

int		Game::neyghbors(int i, int j) {
	int neyghbors(0);

	for (int y(-1) ; y <= 1 ; ++y) {
		for (int x(-1) ; x <= 1 ; ++x) {
			if (!(y == 0 && x == 0) && i != 0 && j != 0
				&& i != this->width - 1 && j != this->length - 1) {
				if (this->board[y + j][x + i] == 1)
					++neyghbors;
			}
		}
	}
	return neyghbors;
}
