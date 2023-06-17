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
LDFLAGS= -lstdc++fs

# ==== Teste_GestorAreaConhecimento
Sources_Teste_GestorAreaConhecimento = CCodigoAreaConhecimento.cpp CGestorAreaConhecimento.cpp Teste_GestorAreaConhecimento.cpp CEstadoPersistente.h
Objects_Teste_GestorAreaConhecimento =$(Sources_Teste_GestorAreaConhecimento:.cpp=.o)

# ==== Teste_GestorCodigoDisciplina
Sources_Teste_GestorCodigoDisciplina = CCodigoDisciplina.cpp CGestorCodigoDisciplina.cpp Teste_GestorCodigoDisciplina.cpp  CEstadoPersistente.h
Objects_Teste_GestorCodigoDisciplina =$(Sources_Teste_GestorCodigoDisciplina:.cpp=.o)

# ==== Teste_GestorEmentaDisciplina
Sources_Teste_GestorEmentaDisciplina = CCodigoAreaConhecimento.cpp CGestorAreaConhecimento.cpp CCodigoDisciplina.cpp CGestorCodigoDisciplina.cpp ETipoAvaliacao.cpp CEmentaDisciplina.cpp CGestorEmentaDisciplina.cpp Teste_GestorEmentaDisciplina.cpp  CEstadoPersistente.h
Objects_Teste_GestorEmentaDisciplina =$(Sources_Teste_GestorEmentaDisciplina:.cpp=.o)

# ==== Exemplo
# Lista de arquivos fonte *.cpp
#SOURCES = CCodigoAreaConhecimento.cpp CGestorAreaConhecimento.cpp CCodigoDisciplina.cpp
SOURCES = $(Sources_Teste_GestorAreaConhecimento) $(Sources_Teste_GestorCodigoDisciplina) $(Sources_Teste_GestorEmentaDisciplina)
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
	rm *.h.gch

# Cria um sufixo
#.SUFFIXES: .cpp

# Instrução que converte arquivos .cpp em .o
.cpp.o:
	$(CPP) -c $(CPPFLAGS) $(ALL_CFLAGS) $<

# Instrução que converte arquivos .cpp em .exe
.cpp.exe:
	$(CPP) $(CPPFLAGS) $(ALL_CFLAGS) $< -o $<.exe

# Instrução que converte arquivos .o em .exe
.o.exe:
	$(CPP) $(LDFLAGS) $(ALL_CFLAGS) $< -o $<.exe


help:
	@echo Opções:
	@echo - Teste_GestorAreaConhecimento
	@echo - Teste_GestorCodigoDisciplina
	@echo - Teste_GestorEmentaDisciplina

Teste_GestorAreaConhecimento: $(Sources_Teste_GestorAreaConhecimento) $(Objects_Teste_GestorAreaConhecimento)
# 	g++ -c $(CPPFLAGS) $(ALL_CFLAGS)  CCodigoAreaConhecimento.cpp
# 	g++ -c $(CPPFLAGS) $(ALL_CFLAGS)  CGestorAreaConhecimento.cpp
# 	g++ -c $(CPPFLAGS) $(ALL_CFLAGS)  Teste_GestorAreaConhecimento.cpp
#	g++  $(CPPFLAGS) $(ALL_CFLAGS)  CCodigoAreaConhecimento.o CGestorAreaConhecimento.o Teste_GestorAreaConhecimento.o -o Teste_GestorAreaConhecimento
	g++  $(CPPFLAGS) $(ALL_CFLAGS)  $(Objects_Teste_GestorAreaConhecimento) -o Teste_GestorAreaConhecimento
	mv Teste_GestorAreaConhecimento ../../test

Teste_GestorCodigoDisciplina: $(Sources_Teste_GestorCodigoDisciplina) $(Objects_Teste_GestorCodigoDisciplina)
# 	g++ -c $(CPPFLAGS) $(ALL_CFLAGS)  CCodigoDisciplina.cpp
# 	g++ -c $(CPPFLAGS) $(ALL_CFLAGS)  CGestorCodigoDisciplina.cpp
# 	g++ -c $(CPPFLAGS) $(ALL_CFLAGS)  Teste_GestorCodigoDisciplina.cpp
	g++ $(CPPFLAGS) $(ALL_CFLAGS) CCodigoDisciplina.o CGestorCodigoDisciplina.o Teste_GestorCodigoDisciplina.o -o Teste_GestorCodigoDisciplina
	mv Teste_GestorCodigoDisciplina ../../test

Teste_GestorEmentaDisciplina: $(Sources_Teste_GestorEmentaDisciplina) $(Objects_Teste_GestorEmentaDisciplina)
	g++ $(CPPFLAGS) $(ALL_CFLAGS) CCodigoAreaConhecimento.o CGestorAreaConhecimento.o \
	               CCodigoDisciplina.o CGestorCodigoDisciplina.o \
	               ETipoAvaliacao.o CEmentaDisciplina.o  CGestorEmentaDisciplina.o \
	               Teste_GestorEmentaDisciplina.o -o Teste_GestorEmentaDisciplina
	mv Teste_GestorEmentaDisciplina ../../test
