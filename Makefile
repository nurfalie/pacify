CXX_OPTIONS = -Wall -Wconversion -Werror -Wextra -Wformat=2 \
	      -Wpointer-arith -Wsign-conversion \
	      -Wstack-protector -Wstrict-overflow=5 \
	      -fPIE -fstack-protector-all -pedantic

SOURCE	= pacify.cc

all: $(SOURCE)
	$(CXX) $(CXX_OPTIONS) -o pacify $(SOURCE)

clean:
	rm -f core pacify

distclean: clean purge

purge:
	rm -f *~
