kernel_shell: main.c switch.s fibre.c
	$(CC) $(CFLAGS) main.c switch.s fibre.c -o kernel_shell