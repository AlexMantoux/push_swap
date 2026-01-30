NAME        = push_swap
NAME_BONUS  = checker
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -MMD -MP -g

PRINTF_DIR  = ft_printf
INC_DIR     = includes
SRC_DIR     = srcs
TRANS_DIR   = srcs/transformations
GNL_DIR     = gnl
BONUS_DIR	= bonus
SIMPLE_ALGO_DIR = srcs/simple_algorithm
MEDIUM_ALGO_DIR = srcs/medium_algorithm
COMPLEX_ALGO_DIR = srcs/complex_algorithm
ADAPTIVE_ALGO_DIR = srcs/adaptive_algorithm
PARSING_DIR = srcs/parsing
UTILS_DIR = srcs/utils

PRINTF_LIB  = $(PRINTF_DIR)/libftprintf.a

SRC         = $(SRC_DIR)/main.c \
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
			  $(PARSING_DIR)/parsing_utils.c \
			  $(PARSING_DIR)/flags.c \
			  $(PARSING_DIR)/bench_flag.c \
			  $(UTILS_DIR)/linked_list_utils.c \
			  $(UTILS_DIR)/algorithm_utils.c \
			  $(UTILS_DIR)/free_utils.c \
			  $(UTILS_DIR)/disorder.c \

SRC_BONUS   = $(GNL_DIR)/get_next_line.c \
              $(GNL_DIR)/get_next_line_utils.c \
			  $(filter-out $(SRC_DIR)/main.c, $(SRC)) \
			  $(BONUS_DIR)/main.c
			  

OBJ         = $(SRC:.c=.o)
OBJ_BONUS   = $(SRC_BONUS:.c=.o)
DEPS        = $(SRC:.c=.d)
DEPS_BONUS	= $(SRC_BONUS:.c=.d)

INCLUDES    = -I $(INC_DIR) -I $(PRINTF_DIR)/includes

.PHONY: all clean fclean re libftprintf bonus

all: libftprintf $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(PRINTF_LIB) -o $(NAME)

bonus: libftprintf $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(PRINTF_LIB) -o $(NAME_BONUS)

libftprintf:
	@make -C $(PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make -C $(PRINTF_DIR) clean
	rm -rf $(OBJ) $(OBJ_BONUS) $(DEPS) $(DEPS_BONUS)

fclean: clean
	@make -C $(PRINTF_DIR) fclean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

-include $(DEPS) $(DEPS_BONUS)