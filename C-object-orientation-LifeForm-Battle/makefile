hepsi: derle calistir

derle:
	gcc -g -I ./include/ -o ./lib/Canli.o -c ./src/Canli.c
	gcc -g -I ./include/ -o ./lib/Bocek.o -c ./src/Bocek.c
	gcc -g -I ./include/ -o ./lib/Pire.o -c ./src/Pire.c
	gcc -g -I ./include/ -o ./lib/Sinek.o -c ./src/Sinek.c
	gcc -g -I ./include/ -o ./lib/Bitki.o -c ./src/Bitki.c
	gcc -g -I ./include/ -o ./lib/CanliBilgi.o -c ./src/CanliBilgi.c
	gcc -g -I ./include/ -o ./lib/Habitat.o -c ./src/Habitat.c
	gcc -g -I ./include/ -o ./lib/MatrisVals.o -c ./src/MatrisVals.c
	gcc -g -I ./include/ -o ./bin/Test ./lib/Canli.o ./lib/Bocek.o ./lib/Pire.o ./lib/Sinek.o ./lib/Bitki.o ./lib/CanliBilgi.o ./lib/Habitat.o ./lib/MatrisVals.o ./src/Test.c

calistir:
	./bin/Test
