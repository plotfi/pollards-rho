CC = gcc
CFLAGS = -Wall -Werror -O2 
BIN = rho.bin

rho: rho.c 
	$(CC)  -o  $(BIN) $(CFLAGS) -DSTEPS -lm rho.c 

debug: rho.c 
	$(CC)  -o  $(BIN) $(CFLAGS) -DSTEPS -DDEBUG  -lm rho.c 

prompt: rho.c 
	$(CC)  -o  $(BIN) $(CFLAGS) -DSTEPS -DPRMPT  -lm rho.c 
    
clean:
	rm -rf $(BIN)



