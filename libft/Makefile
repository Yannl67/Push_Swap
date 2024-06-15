# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylamouri <ylamouri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 14:03:08 by ylamouri          #+#    #+#              #
#    Updated: 2024/06/15 16:27:24 by ylamouri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_substr.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \

OBJDIR =		.obj/

OBJS =			${SRCS:%.c=${OBJDIR}%.o}

# ==================== FLAGS ==================== #

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
AR = ar rcs

# ==================== RULES ==================== #

NAME = libft.a

all: libft $(NAME)

libft:
	@printf "$(PINK)"
	@echo " --- LIBFT ---"

${OBJDIR}%.o: %.c
	@mkdir -p ${@D}
	@printf "\r${GREEN}Compilation of $(CYAN)libft${RESET}..."
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

TOTAL := ${words ${SRCS}}
COMPILED := 0

$(NAME):	${OBJS}
	@$(AR) $(NAME) $(OBJS) 
	@echo "\n$(CYAN)${NAME}$(RESET) $(GREEN)has been created $(RESET)✔️"

clean:
	@${RM} ${OBJDIR}
	@echo "$(RED)Deleting $(CYAN)libft $(YELLOW)objs$(RESET) ✔️"

fclean:	clean
	@${RM} ${NAME}
	@echo "$(RED)Deleting $(CYAN)$(NAME)$(RESET) ✔️"

re:		fclean all

.PHONY: all clean fclean re bonus

# ==================== COLOR ==================== #

RED 	:= \033[1;31m
GREEN 	:= \033[1;32m
YELLOW 	:= \033[1;33m
PINK	:= \033[4;35m
CYAN 	:= \033[1;36m
RESET 	:= \033[0m
END 	:= \033[0m