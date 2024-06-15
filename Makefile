# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylamouri <ylamouri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 14:03:08 by ylamouri          #+#    #+#              #
#    Updated: 2024/06/15 16:27:41 by ylamouri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	srcs/utils/ft_error.c \
	    srcs/main.c \
		srcs/tiny_sort.c \
		srcs/stack_init.c \
		srcs/quick_sort.c \
		srcs/utils/check_args.c \
		srcs/utils/t_stack.c \
		srcs/utils/quick_sort_utils.c \
		srcs/instructions/push.c \
		srcs/instructions/rotate.c \
		srcs/instructions/swap.c \
		srcs/instructions/reverse_rotate.c \
		
OBJDIR = .obj/

OBJS = ${SRC:%.c=${OBJDIR}%.o}

CC = cc
CFLAGS = -Wall -Werror -Wextra 
RM = rm -rf

NAME = push_swap

all: ps ${NAME}

${OBJDIR}%.o: %.c
	@mkdir -p ${@D}
	@printf "\r${GREEN}Compilation of $(CYAN)push_swap${RESET}..."
	@${CC} ${CFLAGS} -c $< -o $@
	${call progress_bar}


define color_progress
$(if $(shell test $(1) -gt 66 && echo true),$(GREEN),$(if $(shell test $(1) -gt 33 && echo true),$(YELLOW),$(RED)))
endef

define progress_bar
@$(eval COMPILED=$(shell echo $$(($(COMPILED)+1))))
@$(eval PROGRESS_PERCENT=$(shell echo $$((($(COMPILED) * 100) / $(TOTAL)))))
@printf "$(CYAN)❘"
@for number in $$(seq 1 $(COMPILED)); do printf "$(call color_progress,$(PROGRESS_PERCENT))█"; done
@for number in $$(seq 1 $$(($(TOTAL) - $(COMPILED)))); do printf "$(GRAY)•"; done
@printf "$(CYAN)❘ $(COMPILED)/$(TOTAL)$(END) ✔️\r"
endef

TOTAL := ${words ${SRC}}
COMPILED := 0

${NAME}: ${OBJS}
	@echo "\n$(CYAN)${NAME}$(RESET) $(GREEN)has been created $(RESET)✔️\n"
	@make --no-print-directory -C ./libft
	@mv ./libft/libft.a .
	@${CC} ${CFLAGS} ${OBJS} libft.a -o push_swap

clean:
	@make --no-print-directory clean -C ./libft
	@echo "$(RED)Deleting $(CYAN)${NAME} $(YELLOW)objs$(RESET) ✔️"
	@${RM} ${OBJDIR}

ps:
	@printf "${PINK} --- PUSH-SWAP ---\n"

fclean: clean
	@${RM} libft.a
	@${RM} ${NAME} 
	@${RM} a.out

re: fclean all

.PHONY: all clean fclean re

# ==================== COLOR ==================== #

RED 	:= \033[1;31m
GREEN 	:= \033[1;32m
YELLOW 	:= \033[1;33m
PINK	:= \033[4;35m
CYAN 	:= \033[1;36m
RESET 	:= \033[0m
END 	:= \033[0m
