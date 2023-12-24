all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/AVLAgaci.cpp -o ./lib/AVLAgaci.o
	g++ -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o
	g++ -c -I "./include" ./src/DYigin.cpp -o ./lib/DYigin.o
	g++ -c -I "./include" ./src/Yigin.cpp -o ./lib/Yigin.o
	g++ -c -I "./include" ./src/Liste.cpp -o ./lib/Liste.o	
	g++ -c -I "./include" ./src/LDugum.cpp -o ./lib/LDugum.o
	g++ -c -I "./include" ./src/YListe.cpp -o ./lib/YListe.o
	g++ -c -I "./include" ./src/YDugum.cpp -o ./lib/YDugum.o	
bagla:
	g++ ./lib/Dugum.o ./lib/AVLAgaci.o ./lib/YListe.o ./lib/YDugum.o ./lib/LDugum.o ./lib/Yigin.o ./lib/DYigin.o ./lib/Liste.o ./lib/main.o -o ./bin/program
calistir:
	./bin/program