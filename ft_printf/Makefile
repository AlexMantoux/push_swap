SRC_DIR=srcs

SRC=$(SRC_DIR)/format_d.c\
	$(SRC_DIR)/format_c.c\
	$(SRC_DIR)/format_p.c\
	$(SRC_DIR)/format_x.c\
	$(SRC_DIR)/format_x_upper.c\
	$(SRC_DIR)/format_u.c\
	$(SRC_DIR)/format_s.c\
	$(SRC_DIR)/handle_format.c\
	$(SRC_DIR)/ft_printf.c\

INC_DIR = includes/**

CC = cc

CFLAGS = -Werror -Wextra -Wall -MMD -MP

NAME = libftprintf.a

OBJ = $(SRC:.c=.o)
DEPS = $(SRC:.c=.d)

.PHONY: all clean fclean re

#RULES#
all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)