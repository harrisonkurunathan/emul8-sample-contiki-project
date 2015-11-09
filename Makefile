all: hello

emul8: all
	emul8 hello-cc2538.emul8

CONTIKI=contiki
TARGET=cc2538dk

CONTIKI_WITH_IPV6 = 1
include $(CONTIKI)/Makefile.include
