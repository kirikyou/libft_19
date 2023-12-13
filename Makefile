# A list of source files for the standard functions of the library 
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
ft_calloc.c ft_strdup.c ft_toupper.c ft_tolower.c \
ft_strchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
ft_strnstr.c ft_atoi.c ft_strrchr.c ft_substr.c \
ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

# A list of source files for the bonus functions of the library
SRCSB = ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
ft_lstsize_bonus.c ft_lstlast_bonus.c \
ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
ft_lstclear_bonus.c ft_lstiter_bonus.c \
ft_lstmap_bonus.c

# The object files generated from the standard source files
OBJS = ${SRCS:.c=.o}

# The object files generated from the bonus source files
OBJSB = ${SRCSB:.c=.o}

# The name of the final static library
NAME = libft.a

# The command to archive object files into a static library, including indexing it
LIBC = ar rcs

# The compiler used
CC = cc

#The command to remove files
RM = rm -f

# Compiler flags for adding warnings and error settings
CFLAGS = -Wall -Wextra -Werror

# This rule states how to make a .o file from a .c file using the defined compiler and flags.
# The output object file will have the same base name as the source file
.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

# This rule specifies how to make the static library.
# It depends on all object files from the standard functions.
# The ar rcs command archives the object files into a static library and indexes it.
${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

# The default goal that gets executed when you run make without arguments.
# It depends on the ${NAME} target
all: ${NAME}

# This target is for compiling the bonus part of the library.
# It first ensures the standard part is compiled and then adds the bonus object files to the library.
bonus: ${NAME} ${OBJSB}
	${LIBC} ${NAME} ${OBJSB}

# This rule removes all object files (both standard and bonus)
clean:
	${RM} ${OBJS} ${OBJSB}

fclean: clean
	${RM} ${NAME}

# This rule depends on fclean and all, effectively rebuilding the entire library from scratch
re: fclean all

.PHONY : all bonus clean fclean re