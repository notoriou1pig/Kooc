
NAME=		babouche
KOOC=		../kooc
CC=		gcc
RM=		rm -rvf

SRCS=		./prog.kc \
		./Exception.kh \
		./prog.kh

CFILES=		$(patsubst %.kh,%.h,$(patsubst %.kc,%.c,$(SRCS)))
OBJS=		$(filter-out %.h,$(CFILES))

CFLAGS=		-I./ -O2
LDFLAGS=	-L .

%.c:		%.kc
	$(KOOC) $<

%.h:		%.kh
	$(KOOC) $<

all:		$(CFILES) $(OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LDFLAGS)

clean:
	$(RM)	$(OBJS)
	$(RM)	$(CFILES)

fclean:		clean
	$(RM)	$(NAME)

re:		fclean all

.PHONY:		all clean fclean re

