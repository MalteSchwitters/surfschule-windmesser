client: main.o
	clang -o client main.o -lcurl -lwiringPi

main.o: src/main.c sensor.o http.o
	clang -c src/main.c sensor.o http.o

sensor.o: src/sensor.c
	clang -c src/sensor.c

http.o: src/http.c
	clang -c src/http.c

clean:
	rm client
	rm *.o
