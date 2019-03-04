CC=g++
CPPFLAGS=-march=native -mtune=native -Os -fno-plt -flto -fno-exceptions

compare: Comparator.o
	$(CC) -o compare Comparator.o $(CPPFLAGS)

strip:
	strip -S --strip-unneeded --remove-section=.note.gnu.gold-version --remove-section=.comment --remove-section=.note --remove-section=.note.gnu.build-id --remove-section=.note.ABI-tag compare


.PHONY: clean
clean:
	rm compare *.o
