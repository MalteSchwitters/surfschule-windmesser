client:
	clang -o client src/main.c -lcurl -lwiringPi
clean:
	rm client
