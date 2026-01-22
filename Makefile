NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -MMD -MP -g

PRINTF_DIR  = ft_printf
INC_DIR     = includes
SRC_DIR     = srcs
TRANS_DIR   = srcs/transformations
SIMPLE_ALGO_DIR = srcs/simple_algorithm
MEDIUM_ALGO_DIR = srcs/medium_algorithm
COMPLEX_ALGO_DIR = srcs/complex_algorithm
ADAPTIVE_ALGO_DIR = srcs/adaptive_algorithm
PARSING_DIR = srcs/parsing

PRINTF_LIB  = $(PRINTF_DIR)/libftprintf.a

SRC         = $(SRC_DIR)/main.c \
              $(SRC_DIR)/disorder.c \
              $(SRC_DIR)/linked_list_utils.c \
			  $(SRC_DIR)/algorithm_utils.c \
			  $(SRC_DIR)/bench_flag.c \
              $(TRANS_DIR)/push_transform.c \
              $(TRANS_DIR)/reverse_rotate_transform.c \
              $(TRANS_DIR)/rotate_transform.c \
              $(TRANS_DIR)/swap_transform.c \
			  $(SIMPLE_ALGO_DIR)/selection_sort.c \
			  $(MEDIUM_ALGO_DIR)/chunk_based_sort.c \
			  $(COMPLEX_ALGO_DIR)/radix_sort.c \
			  $(ADAPTIVE_ALGO_DIR)/adaptive_sort.c \
			  $(PARSING_DIR)/ft_atoi.c \
			  $(PARSING_DIR)/ft_isdigit.c \
			  $(PARSING_DIR)/ft_split.c \
			  $(PARSING_DIR)/ft_strjoin.c \
			  $(PARSING_DIR)/parsing.c \
			  $(PARSING_DIR)/flags.c \



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