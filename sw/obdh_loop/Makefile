# ####################################################
# I2C
# ####################################################

CC = msp430-gcc
CFLAGS = -mmcu=msp430f249 -O0 -ggdb -fvar-tracking -gdwarf-4 -fvar-tracking-assignments
LDFLAGS = 

TARGET = loop.x
INC_DIR := -I.

SRCS := loop.c
OBJS := $(SRCS:.c=.o)

#------------------------------------------------------
.SILENT:

#------------------------------------------------------
.SUFFIXES: .o .c .h

#------------------------------------------------------
all: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(TARGET) $(LDFLAGS)
#------------------------------------------------------
clean:
	rm -f *.o *~ $(TARGET)
#------------------------------------------------------
distclean: clean
#------------------------------------------------------
bin:
	tar xzf i2c-bin.tgz
#------------------------------------------------------
.c.o:
	$(CC) -c $(CFLAGS) $(INC_DIR) -c $<
	



