NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -MMD -MP

PRINTF_DIR  = ft_printf
INC_DIR     = includes
SRC_DIR     = srcs
TRANS_DIR   = srcs/transformations

PRINTF_LIB  = $(PRINTF_DIR)/libftprintf.a

SRC         = $(SRC_DIR)/main.c \
              $(SRC_DIR)/push_swap.c \
              $(SRC_DIR)/argument_utils.c \
              $(SRC_DIR)/disorder.c \
              $(SRC_DIR)/linked_list_utils.c \
              $(TRANS_DIR)/push_transform.c \
              $(TRANS_DIR)/reverse_rotate_transform.c \
              $(TRANS_DIR)/rotate_transform.c \
              $(TRANS_DIR)/swap_transform.c

OBJ         = $(SRC:.c=.o)
DEPS        = $(SRC:.c=.d)

INCLUDES    = -I $(INC_DIR) -I $(PRINTF_DIR)/includes

.PHONY: all clean fclean re libftprintf

all: libftprintf $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(PRINTF_LIB) -o $(NAME)

libftprintf:
	@make -C $(PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make -C $(PRINTF_DIR) clean
	rm -rf $(OBJ) $(DEPS)

fclean: clean
	@make -C $(PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)