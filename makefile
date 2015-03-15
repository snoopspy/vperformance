first: all

all: app_

update:
	git pull

app_:
	cd app && qmake && make && make clean && cd ..

clean:
	find -type d -name 'build-*'    -exec rm -r {} \;
	find -type f -name '*.o'        -delete
	find -type f -name '*.pro.user' -delete
	find -type f -name 'Makefile*'  -delete
