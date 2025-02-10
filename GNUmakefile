#
.DEFAULT_GOAL:=		all

#
.c.o:
	${CC} ${CFLAGS} -c $<

#
CFLAGS?=	-O2 -g
LDFLAGS?=	-O2 -g

all:: dfs dfs-optimize1

clean::
	rm -f *.o
	rm -f dfs dfs-optimize1

common.o: common.c common.h
	${CC} ${CFLAGS} -c common.c

dfs:: common.o dfs.o
	${CC} ${LDFLAGS} -o $@ $^

dfs-optimize1:: common.o dfs-optimize1.o
	${CC} ${LDFLAGS} -o $@ $^
