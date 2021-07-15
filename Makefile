NAME = my_containers

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

HEADER = header.hpp

FLAGS2 =-Wall -Wextra -Werror
FLAGS =-std=c++98 -g -fsanitize-address-poison-custom-array-cookie -fsanitize-address-use-after-scope -fsanitize-address-use-odr-indicator -fsanitize=address

all: $(NAME)

$(NAME):
	@echo "\x1b[33m Preparing $(NAME)...\x1b[0m"
	@clang++ -o $(NAME) $(SRCS) $(FLAGS) $(FLAGS2)
	@echo "\x1b[32m $(NAME) are ready!\x1b[0m"

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

test: re
	@./my_containers

%.o: %.cpp
	@clang++ $(FLAGS) -c $< -o $@

.PHONY:	all clean fclean re
