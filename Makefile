NAME = my_containers

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

FLAGS =-Wall -Wextra -Werror -O2

all: $(NAME)

$(NAME):
	@echo "\x1b[33m Preparing $(NAME)...\x1b[0m"
	@clang++ -o $(NAME) $(SRCS) $(FLAGS)
	@echo "\x1b[32m $(NAME) are ready!\x1b[0m"

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

test:

%.o: %.cpp
	@clang++ $(FLAGS) -c $< -o $@

.PHONY:	all clean fclean re