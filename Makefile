CXX_OPTIONS = -Wall -Wconversion -Werror -Wextra -Wformat=2 \
	      -Wpointer-arith -Wsign-conversion \
	      -Wstrict-overflow=5 -pedantic

SOURCE	= pacify.cc

all: $(SOURCE)
	$(CXX) $(CXX_OPTIONS) -o pacify $(SOURCE)

clean:
	rm -f core pacify

distclean: clean purge

purge:
	rm -f *~
