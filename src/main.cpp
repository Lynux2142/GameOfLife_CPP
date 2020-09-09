/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 13:29:35 by lguiller          #+#    #+#             */
/*   Updated: 2020/09/09 14:20:41 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gameoflife.hpp"

static void	rand_board(Game &board) {
	for (int y(0) ; y < board.length ; ++y) {
		for (int x(0) ; x < board.width ; ++x) {
			board.board[y][x] = rand() % 2;
		}
	}
}

static void	print_cell(SDL_Renderer *renderer, SDL_Rect r, Game board) {
	for (int y(0) ; y < board.length ; ++y) {
		for (int x(0) ; x < board.width ; ++x) {
			if (board.board[y][x] == 1) {
				r.x = x * SIZE;
				r.y = y * SIZE;
				SDL_RenderFillRect(renderer, &r);
			}
		}
	}
}

static void	next_cycle(Game &board) {
	Game	tmp(board);
	int		neyghbors;

	for (int y(0) ; y < tmp.length ; ++y) {
		for (int x(0) ; x < tmp.width ; ++x) {
			neyghbors = tmp.neyghbors(x, y);
			if (tmp.board[y][x] == 1) {
				if (!(neyghbors == 2 || neyghbors == 3))
					board.board[y][x] = 0;
			} else {
				if (neyghbors == 3)
					board.board[y][x] = 1;
			}
		}
	}
}

static void	start_rendering(SDL_Renderer *renderer) {
	Game		board(WIDTH, LENGTH);
	SDL_Event	event;
	SDL_Rect	r;

	r.w = SIZE;
	r.h = SIZE;
	rand_board(board);
	while (1) {
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT)
			break;
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		print_cell(renderer, r, board);
		next_cycle(board);
		for (int i(0) ; i < NB_RAND_CELLS ; ++i)
			board.board[rand() % LENGTH][rand() % WIDTH] = 1;
		SDL_RenderPresent(renderer);
		SDL_Delay(DELAY);
	}
}

int			main(void) {
	SDL_Window		*window;
	SDL_Renderer	*renderer;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
		return 3;
	}
	window = SDL_CreateWindow(
		"Game Of Life",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WIDTH * SIZE,
		LENGTH * SIZE,
		SDL_WINDOW_OPENGL
	);
	if (window == NULL) {
		cout << "Could not create window: " << SDL_GetError() << endl;
		return 1;
	}
	renderer = SDL_CreateRenderer(window, -1, 0);
	start_rendering(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
