CC = cc

CFLAGS = -Wall -Werror -Wextra

CFILES = philo.c\
		ft_atoi.c\
		ft_split.c\
		ft_checknum.c\
		utils.c\
		args.c\
		destroy_all.c\
		fork.c\
		shared.c\

OFILES = $(addprefix $(OBJ_DIR)/,$(CFILES:.c=.o))

OBJ_DIR = ./OBJ

SRC_DIR = ./SRC

INC = includes/philo.h

NAME = philo

$(NAME) : $(OFILES)
	@$(CC) $(OFILES) -pthread -o $(NAME)
	@echo "done for philo"

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
