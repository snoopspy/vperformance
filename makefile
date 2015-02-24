INSTALL_PATH=/usr/local/include

all:
	make build

update:
	git pull

build:
	make app_

app_:
	cd app && \
	qmake && \
	make && \
	make clean && \
	cd ..

install:
	cp -R src/* $(INSTALL_PATH)

uninstall:
	rm -rf $(INSTALL_PATH)/VPerformance*
	rm -rf $(INSTALL_PATH)/performance

clean:
	find -name "Makefile*" -type f -delete

