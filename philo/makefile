NAME	=	philo
CC		=	cc
CFLAGS	=	-Werror -Wextra -Wall
SRCS	=	./philo.c				\
			./utils/init.c			\
			./utils/ft_atoi.c		\
			./utils/ft_isdigit.c	\
			./utils/mutex.c			\
			./utils/pthread_wait.c	\
			./utils/connect_philo_with_vars.c \
			./utils/ft_print.c	\
			./utils/get_time.c	\
			./utils/check_philo_isdeath.c

OBJS	=	$(SRCS:.c=.o)

%.o: %.c philo.h
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "	\033[0;33m					\n\
		 .-''-. 						\n\
       _'>     \-.  					\n\
    _.'     _     '._					\n\
  .'   _.='   '=._   '.					\n\
  >_   / /_\ /_\ \   _<					\n\
    / (  \o/ \\o/  ) \					\n\
    >._\ .-,_)-. /_.<					\n\
        /__/ \__\ 						\n\
          '---'     philosophers\033[0m \n\
	"

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all