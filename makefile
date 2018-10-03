client: main.o sensor.o http.o
	clang -o client main.o sensor.o http.o -lcurl -lwiringPi

main.o: src/main.c
	clang -c src/main.c

sensor.o: src/sensor.c
	clang -c src/sensor.c

http.o: src/http.c
	clang -c src/http.c

clean:
	rm client
	rm main.o
