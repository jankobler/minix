# Makefile for terminal driver (TTY)

PROG=	tty

.include "arch/${MACHINE_ARCH}/Makefile.inc"

SRCS +=	tty.c

DPADD+=	${LIBCHARDRIVER} ${LIBSYS} ${LIBTIMERS}
LDADD+=	-lchardriver -lsys -ltimers

MAN=

BINDIR?= /usr/sbin

SUBDIR= keymaps

# Needs kernel/const.h, etc
CPPFLAGS+=	-I${.CURDIR}	-I${NETBSDSRCDIR}

.include <minix.service.mk>
.include <bsd.subdir.mk>
