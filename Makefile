# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/26 14:00:46 by lguiller          #+#    #+#              #
#    Updated: 2020/09/09 14:19:11 by lguiller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################
##  VARIABLES   ##
##################

OPE_SYS			= $(shell uname)
NAME			= gameoflife

SRCS1			= main.cpp
SRCS1			+= game.class.cpp

SRCS			= $(addprefix $(SRCS_DIR)/, $(SRCS1))
OBJS			= $(addprefix $(OBJS_DIR)/, $(SRCS1:.cpp=.o))

SRCS_DIR		= ./src
OBJS_DIR		= ./obj
INCLUDES_DIR	= ./include

HEADER			= $(INCLUDES_DIR)/gameoflife.hpp
HEADER			+= $(INCLUDES_DIR)/game.class.hpp

FRAMEWORK		= -F ~/Library/Frameworks

FLAGS			= -Wall -Wextra -Werror -g
CC				= clang++

INCLUDES		= $(addprefix -I, $(INCLUDES_DIR))

##################
##    COLORS    ##
##################

_BLACK		= "\033[30m"
_RED		= "\033[31m"
_GREEN		= "\033[32m"
_YELLOW		= "\033[33m"
_BLUE		= "\033[34m"
_VIOLET		= "\033[35m"
_CYAN		= "\033[36m"
_WHITE		= "\033[37m"
_END		= "\033[0m"
_CLEAR		= "\033[2K"
_HIDE_CURS	= "\033[?25l"
_SHOW_CURS	= "\033[?25h"
_UP			= "\033[A"
_CUT		= "\033[k"

##################
##   TARGETS    ##
##################

.PHONY: all launch clean fclean re title
.SILENT:

all: launch

launch: title
	echo $(_CLEAR)$(_YELLOW)"building - "$(_GREEN)$(NAME)$(_END)
	$(MAKE) $(NAME)
	echo $(_GREEN)"\nDone."$(_END)$(_SHOW_CURS)

$(OBJS_DIR):
	mkdir $@

FORCE:

$(NAME): $(OBJS_DIR) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(FRAMEWORK) -framework SDL2 -o $(NAME)

$(OBJS): $(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp $(HEADER)
	$(CC) $(FLAGS) $(INCLUDES) $(FRAMEWORK) -c $< -o $@
	printf $<

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) -s fclean
	$(MAKE) -s

title:
	echo $(_RED)
	echo "◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆"
	echo
	echo "              :::::::::: :::::::::::           :::        ::::::::        "
	echo "             :+:            :+:               :+:       :+:    :+:        "
	echo "            +:+            +:+               +:+       +:+                "
	echo "           :#::+::#       +#+               +#+       +#++:++#++          "
	echo "          +#+            +#+               +#+              +#+           "
	echo "         #+#            #+#               #+#       #+#    #+#            "
	echo "        ###            ###    ########## ########## ########              "
	echo
	echo "◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆"
	printf $(_YELLOW)
	echo "                                                           2018 © lguiller"
	echo $(_END)
