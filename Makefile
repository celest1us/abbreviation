CXX=g++
CXXFLAGS=-Wall -Werror -fpic
SRCS=abbrev.cpp
OBJS=$(subst .cpp,.o,$(SRCS))
RM=rm -f
TARGET_LIB=libabbrev.so

.PHONY: all
all: $(TARGET_LIB)

$(TARGET_LIB): $(OBJS)
	$(CXX) -shared -o $@ $^

test.exe: $(TARGET_LIB) test.o
	$(CXX) -L. -o $@ $^ -labbrev

.PHONY: test
test: test.exe
	LD_LIBRARY_PATH=$(LD_LIBRARY_PATH):. ./$^

.PHONY: clean
clean:
	$(RM) $(OBJS) $(TARGET_LIB) test
