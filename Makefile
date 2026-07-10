CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

INCLUDES = includes/

VPATH = sources:
SRCS = Append.c Char.c Copy.c Dup.c Join.c Length.c Split.c

OBJDIR = objs
OBJS = $(addprefix $(OBJDIR)/str, $(SRCS:.c=.o))

NAME = libstr.a

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $^

$(OBJDIR)/%.o : %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

$(OBJDIR) :
	mkdir -p $@

clean :
	rm -rf $(OBJDIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
