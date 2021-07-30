# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/21 12:06:58 by mterresa          #+#    #+#              #
#    Updated: 2021/07/30 23:21:23 by cmalt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = norm

GCC = clang++

SRC =	main.cpp \
		tester/print_test.cpp \
        tester/vector/capacity.cpp \
		tester/vector/access.cpp \
        tester/vector/const_iterator.cpp \
        tester/vector/const_reverse_iterator.cpp \
        tester/vector/constructors.cpp \
        tester/vector/iterator.cpp \
        tester/vector/modifiers.cpp \
        tester/vector/operators.cpp \
        tester/vector/reverse_iterator.cpp \
        tester/vector/test_vector.cpp \
        tester/map/access.cpp \
        tester/map/capacity.cpp \
        tester/map/const_iterator.cpp \
        tester/map/const_reverse_iterator.cpp \
        tester/map/constructors.cpp \
        tester/map/iterator.cpp \
        tester/map/modifiers.cpp \
        tester/map/observers.cpp \
        tester/map/operations.cpp \
        tester/map/reverse_iterator.cpp \
        tester/map/test_map.cpp \
		tester/stack/methods.cpp \
        tester/stack/operators.cpp \
        tester/stack/test_stack.cpp


OBJ =	$(SRC:.cpp=.o)


all: $(NAME)

%.o:		%.cpp
	$(GCC) -c $< -o $@

vector:

$(NAME): $(OBJ)
	$(GCC) $(OBJ) -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME) test/

re: fclean all