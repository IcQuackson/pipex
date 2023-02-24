# Compiler settings
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Directories
SRCDIR = src
OBJDIR = obj

# Source files
SRCS = $(SRCDIR)/mandatory/main.c \
	   $(SRCDIR)/mandatory/utils_1.c \
	   $(SRCDIR)/mandatory/utils_2.c \
	   $(SRCDIR)/mandatory/utils_3.c
#$(SRCDIR)/subdir/foo.c
#$(SRCDIR)/subdir/bar.c

OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

FILE1 = input.txt
CMD1 = "ls -l"
CMD2 = "wc -laaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
CMD3 = "echo"
FILE2 = out.txt

# Targets
NAME = pipex

all: $(NAME)

bonus:

clean:
		rm -f $(OBJS)

fclean:	clean
		rm $(NAME)

main:	all
		./pipex $(FILE1) $(CMD1) $(CMD2) $(FILE2)

gdb:	all
		gdb $(NAME)

valgrind: 	all
			valgrind --leak-check=yes ./$(NAME) $(FILE1) $(CMD1) $(CMD2) $(FILE2)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: all clean fclean bonus main
