# ####################################################
# I2C
# ####################################################

CC = msp430-gcc
CFLAGS = -mmcu=msp430f249 -O0 -ggdb -fvar-tracking -gdwarf-4 -fvar-tracking-assignments
LDFLAGS = 

TARGET = i2cmaster.x
INC_DIR := -I.

SRCS := msp430x24x_uscib0_i2c_10.c
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
	



