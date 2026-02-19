CC = gcc
CFLAGS = -Wall -g

kernel_shell: main.c switch.s
	$(CC) $(CFLAGS) main.c switch.s -o kernel_shell

clean:
	rm -f kernel_shell