# Nombre del ejecutable
TARGET = Gestion

# Compilador
CXX = g++

# Opciones de compilación
CXXFLAGS = -std=c++11 -Wall

# Directorios de archivos fuente
SRCDIRS = . campos grupos tablahash utilidades

# Archivos fuente
SRCS := $(wildcard *.cpp) $(wildcard */*.cpp)

# Objetos generados
OBJS := $(SRCS:.cpp=.o)

# Incluir directorios de encabezados
INCFLAGS := $(addprefix -I, $(SRCDIRS))

# Regla principal: compilar el programa
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla para compilar archivos fuente
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c -o $@ $<

# Regla para limpiar archivos generados
clean:
	rm -f $(TARGET) $(OBJS)

# Regla para eliminar los archivos temporales generados durante la compilación
.PHONY: clean
