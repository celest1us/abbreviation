CXX=g++
SRCS=main.cpp
OBJS=$(subst .cpp,.o,$(SRCS))
RM=rm -f

all: main.exe

main.exe: $(OBJS)
	$(CXX) -o main.exe $(OBJS)

main.o: main.cpp

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) tool