CXXFLAGS=-g

EXE=torrent

SRC= \
	main.cpp \
	Dictionary.cpp \
	String.cpp \
	Element.cpp \
	Integer.cpp \
	List.cpp \
	Indent.cpp

OBJ = $(addsuffix .o, $(basename $(SRC)))

${EXE}: ${OBJ}
	${CXX} ${OBJ} -o ${EXE}

.SUFFIXES: .cpp

.cpp.o:
	${CXX} ${CXXFLAGS} -c $<

depend:
	makedepend ${CXXFLAGS} -Y ${SRC}

clean:
	rm -f ${OBJ} ${EXE} *~
# DO NOT DELETE

main.o: Dictionary.h String.h Element.h Exception.h
Dictionary.o: Dictionary.h String.h Element.h Exception.h
String.o: String.h Element.h Exception.h
Element.o: Element.h Dictionary.h String.h Integer.h List.h Exception.h
Integer.o: Integer.h Element.h Exception.h
List.o: List.h Element.h Exception.h
Indent.o: Indent.h
