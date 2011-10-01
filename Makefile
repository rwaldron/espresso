PROJECT = espresso
HEX = src/$(PROJECT).hex

default: all

all:
	cd src; $(MAKE) $@

flash: all
	./upload.sh $(HEX)

clean:
	cd src; $(MAKE) $@

.PHONY: all flash clean
