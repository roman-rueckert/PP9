application_header_only:
	gcc-10 main.c -o main.elf -lm

application_staticlib:staticlib
	gcc-10 calc_GAUSS_erwartungsw_stdabw.c -lstaticlib_gauss -o calc_GAUSS_erwartungsw_stdabw.elf -lm


staticlib:
	gcc-10 staticlib_gauss.c -c
	ar -crs libstaticlib_gauss.a staticlib_gauss.o
	sudo cp staticlib_gauss.h /usr/include
	sudo cp libstaticlib_gauss.a /usr/lib
