#
.DEFAULT_GOAL:=		all
.PHONY:			all clean

#
.c.o:
	${CC} ${CFLAGS} -c $<

#
CFLAGS?=	-O2
LDFLAGS?=	-O2

all:: dfs dfs-optimize1 factors

clean::
	rm -f *.o
	rm -f dfs dfs-optimize1 factors

common.o: common.c common.h
	${CC} ${CFLAGS} -c common.c

dfs:: common.o dfs.o
	${CC} ${LDFLAGS} -o $@ $^

dfs-optimize1:: common.o dfs-optimize1.o
	${CC} ${LDFLAGS} -o $@ $^

factors:: common.o factors.o
	${CC} ${LDFLAGS} -o $@ $^
