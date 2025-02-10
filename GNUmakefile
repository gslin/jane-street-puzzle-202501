#
.DEFAULT_GOAL:=		all

#
.c.o:
	${CC} ${CFLAGS} -c $<

#
CFLAGS?=	-O2
LDFLAGS?=	-O2

all:: dfs

clean::
	rm -f *.o
	rm -f dfs

dfs:: dfs.o
	${CC} ${LDFLAGS} -o $@ $^
