all:
	g++ main.cpp ./lib/cpu/cpu.cpp ./lib/tela/tela.cpp ./lib/teclado/teclado.cpp ./lib/botao/botao.cpp ./lib/calculadora/calculadora.cpp -o main.exe
	./main.exe