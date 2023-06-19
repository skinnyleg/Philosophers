CC = cc

CFLAGS = -Wall -Werror -Wextra #-g -fsanitize=thread

CFILES = main.c\
		ft_checknum_bonus.c\
		utils_bonus.c\
		ft_split_bonus.c\
		ft_atoi_bonus.c\
		shared_bonus.c\
		ft_routine_bonus.c\
		destroy_all_bonus.c\

OFILES = $(addprefix $(OBJ_DIR)/,$(CFILES:.c=.o))

OBJ_DIR = ./OBJ

SRC_DIR = ./SRC

INC = includes/philo_bonus.h

NAME = philo_bonus

bonus : $(NAME)

$(NAME) : $(OFILES)
	@$(CC) $(OFILES) -pthread -g -fsanitize=thread -o $(NAME)
	@echo "done for philo_bonus"

$(OBJ_DIR) :
	@mkdir OBJ

$(OFILES) : $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(INC) | $(OBJ_DIR)
	@$(CC) -c $(CFLAGS) $< -o $@

clean :
	@rm -rf $(OBJ_DIR)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

all : $(NAME)

.PHONY : re all clean fclean
