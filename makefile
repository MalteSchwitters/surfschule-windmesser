client: main.o
	clang -o client main.o -lcurl -lwiringPi
main.o: src/main.c
	clang -c src/main.c
clean:
	rm client
	rm main.o
