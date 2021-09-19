CXX=g++
CXXFLAGS=-Wall -Werror -fpic
SRCS=abbrev.cpp
OBJS=$(subst .cpp,.o,$(SRCS))
RM=rm -f
TARGET_LIB=libabbrev.so
TEST_EXE=test.exe

.PHONY: all
all: $(TARGET_LIB)

$(TARGET_LIB): $(OBJS)
	$(CXX) -shared -o $@ $^

$(TEST_EXE): $(TARGET_LIB) test.o
	$(CXX) -L. -o $@ $^ -labbrev

.PHONY: test
test: $(TEST_EXE)
	LD_LIBRARY_PATH=$(LD_LIBRARY_PATH):. ./$^

.PHONY: clean
clean:
	$(RM) $(OBJS) $(TARGET_LIB) $(TEST_EXE)
