# Define o shell
SHELL=/bin/bash
# Apaga .SUFFIXES e define com novo valor
.SUFFIXES:
.SUFFIXES: .cpp .o .exe
# Define compilador
CPP=g++
# Define flags para compilador
CPPFLAGS=-std=c++23
# Outros flags
ALL_CFLAGS=
# Diretorio fonte
srcdir=.
# Flags para linker
LDFLAGS=
# Lista de arquivos fonte *.cpp
SOURCES= CCodigoAreaConhecimento.cpp CGestorAreaConhecimento.cpp CCodigoDisciplina.cpp CGestorCodigoDisciplina.cpp ETipoAvaliacao.cpp CEmentaDisciplina.cpp CGestorEmentaDisciplina.cpp Teste_GestorEmentaDisciplina.cpp
# Abaixo note a substituição de variáveis; de .cpp para .o
OBJECTS=$(SOURCES:.cpp=.o)
# Nome dos executáveis
EXECUTABLES=$(SOURCES:.cpp=.exe)

# Compilação de todos os arquivos, executar SOURCES e depois EXECUTABLE
all: $(SOURCES) $(EXECUTABLES)

obj: $(OBJECTS)

exe: $(SOURCES) $(EXECUTABLES)

clean:
	rm *.o

# Instrução que converte arquivos .cpp em .o
.cpp.o:
	$(CPP) -c $(CPPFLAGS) $(ALL_CFLAGS) $<

# Instrução que converte arquivos .cpp em .exe
.cpp.exe:
	$(CPP) $(CPPFLAGS) $(ALL_CFLAGS) $< -o $<.exe

# Instrução que converte arquivos .o em .exe
.o.exe:
	$(CPP) $(LDFLAGS) $(ALL_CFLAGS) $< -o $<.exe

Teste_GestorAreaConhecimento: CCodigoAreaConhecimento.cpp CGestorAreaConhecimento.cpp Teste_GestorAreaConhecimento.cpp
	g++ -std=c++23 -c CCodigoAreaConhecimento.cpp
	g++ -std=c++23 -c CGestorAreaConhecimento.cpp
	g++ -std=c++23 -c Teste_GestorAreaConhecimento.cpp
	g++ -std=c++23 CCodigoAreaConhecimento.o CGestorAreaConhecimento.o Teste_GestorAreaConhecimento.o -o Teste_GestorAreaConhecimento
	mv Teste_GestorAreaConhecimento ../../test

Teste_GestorCodigoDisciplina: CCodigoDisciplina.cpp CGestorCodigoDisciplina.cpp Teste_GestorCodigoDisciplina.cpp
	#g++ -c CVerificaPadrao.h
	g++ -std=c++23 -c CCodigoDisciplina.cpp
	g++ -std=c++23 -c CGestorCodigoDisciplina.cpp
	g++ -std=c++23 -c Teste_GestorCodigoDisciplina.cpp
	g++ -std=c++23 CCodigoDisciplina.o CGestorCodigoDisciplina.o Teste_GestorCodigoDisciplina.o -o Teste_GestorCodigoDisciplina
	mv Teste_GestorCodigoDisciplina ../../test
#CCodigoAreaConhecimento.o CGestorAreaConhecimento.o CCodigoDisciplina.o CGestorCodigoDisciplina.o ETipoAvaliacao.o CEmentaDisciplina.o CGestorEmentaDisciplina.o Teste_GestorEmentaDisciplina.o
#$(SOURCES) $(OBJECTS)
#	g++ -std=c++23 CCodigoAreaConhecimento.o CGestorAreaConhecimento.o \
	               CCodigoDisciplina.o CGestorCodigoDisciplina.o \
	               ETipoAvaliacao.o CEmentaDisciplina.o  CGestorEmentaDisciplina.o \
	               Teste_GestorEmentaDisciplina.o -o Teste_GestorEmentaDisciplina
Teste_GestorEmentaDisciplina: $(SOURCES) $(OBJECTS)
	g++ -std=c++23 CCodigoAreaConhecimento.o CGestorAreaConhecimento.o \
	               CCodigoDisciplina.o CGestorCodigoDisciplina.o \
	               ETipoAvaliacao.o CEmentaDisciplina.o  CGestorEmentaDisciplina.o \
	               Teste_GestorEmentaDisciplina.o -o Teste_GestorEmentaDisciplina
	mv Teste_GestorEmentaDisciplina ../../test
