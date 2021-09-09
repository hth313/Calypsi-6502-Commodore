VPATH = src

# Lirbary products
ALL_LIBS = c64.a

# Common source files
ASM_SRCS = stub_exit.s stub_putchar.s stub_read.s
C_SRCS = stub_lseek.c stub_write.c stub_close.c

# Object files
OBJS = $(ASM_SRCS:%.s=%.o) $(C_SRCS:%.c=%.o)

%.o: %.s
	as6502 --core=6502 --list-file=$(@:%.o=obj/%.lst) -o obj/$@ $<

%.o: %.c
	cc6502 --core=6502 -O2 --list-file=$(@:%.o=obj/%.lst) -o obj/$@ $<

all: $(ALL_LIBS)

c64.a: $(OBJS)
	(cd obj ; nlib ../$@ $^)

clean:
	-(cd obj ; rm $(OBJS) $(OBJS:%.o=%.lst))
	-rm $(ALL_LIBS)
