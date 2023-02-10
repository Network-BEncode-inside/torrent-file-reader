PROJECT = torrentfile

CXXFLAGS = -g
RM = rm -f

SRC= \
	src/Dictionary.cpp \
	src/String.cpp \
	src/Element.cpp \
	src/Integer.cpp \
	src/List.cpp \
	src/Indent.cpp \
	src/main.cpp 

INC= \
	src/Dictionary.h \
	src/String.h \
	src/Element.h \
	src/Integer.h \
	src/List.h \
	src/ Indent.h \
	src/Exception.h

OBJ = $(addsuffix .o, $(basename $(SRC)))

TARGET = ${PROJECT}

all: ${TARGET}

${TARGET}: ${OBJ}
	${CXX} $^ -o $@

.SUFFIXES: .cpp

.cpp.o:
	${CXX} ${CXXFLAGS} -c $< -o $@

depend:
	makedepend ${CXXFLAGS} -Y ${SRC}

clean:
	$(RM) ${OBJ} ${TARGET} *~
