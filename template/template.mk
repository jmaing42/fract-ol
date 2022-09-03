
NAME = fractol
NAME_LIBFT = libft.a
NAME_LIBFTO = libfto.a

EXECUTABLE_TARGETS = $(NAME_PUSH_SWAP) $(NAME_CHECKER)
LIBRARY_TARGETS = $(NAME_LIBFT) $(NAME_LIBFTO)
OBJS = $(OBJS_FRACTOL) $(OBJS_LIBFT) $(OBJS_LIBFTO)

OTHER_USEFUL_FILES = .editorconfig .gitignore

CFLAGS = -Wall -Wextra -Werror
LDFLAGS := -lmlx
ARFLAGS := cr


default: all
.PHONY: default


.PHONY: all
all: $(NAME) $(OTHER_USEFUL_FILES)

.PHONY: bonus
bonus: all

.PHONY: clean
clean:
	rm -f $(OBJS) $(LIBRARY_TARGETS) $(OTHER_USEFUL_FILES)

.PHONY: fclean
fclean: clean
	rm -f $(EXECUTABLE_TARGETS)

.PHONY: re
re:
	$(MAKE) fclean
	$(MAKE) all


.editorconfig:
	printf "root = true\n\n[*]\ncharset = utf-8\nend_of_line = lf\nindent_size = 4\nindent_style = tab\ninsert_final_newline = true\ntrim_trailing_whitespace = true\n" > .editorconfig

.gitignore:
	(printf ".*\n*.o\n\n" && echo "$(EXECUTABLE_TARGETS) $(LIBRARY_TARGETS)" | xargs -n 1 echo) > $@


$(EXECUTABLE_TARGETS):
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBRARY_TARGETS)
$(LIBRARY_TARGETS):
	$(AR) $(ARFLAGS) $@ $^

$(NAME): $(OBJS_FRACTOL)
$(NAME_LIBFT): $(OBJS_LIBFT)
$(NAME_LIBFTO): $(OBJS_LIBFTO)
