SHELL:=/bin/bash

DEFAULT_TYPE='Release'
BUILD_TYPE=${BUILD_TYPE:-$DEFAULT_TYPE}

.PHONY: install-format
install-format:
	pip3 install clang-format

.PHONY: install-gtest
install-gtest:
	git clone https://github.com/google/googletest.git -b v1.14.0 googletest
	mkdir googletest-build
	cmake -S googletest -B googletest-build
	cmake --build googletest-build
	sudo make -C googletest-build install
	rm -rf googletest googletest-build

.PHONY: install-python
install-python:
	pip install pipenv

.PHONY: check-format
check-format:
	find . -name "*.cpp" -exec clang-format -n --verbose {} \;
	find . -name "*.h" -exec clang-format -n --verbose {} \;

.PHONY: format
format:
	find . -name "*.cpp" -exec clang-format -i {} \;
	find . -name "*.h" -exec clang-format -i {} \;

.PHONY: run-python
run-python:
	python python/djikstra.py

.PHONY: build
build:
	rm -fr build
	cmake -B build -DCMAKE_BUILD_TYPE=${BUILD_TYPE}
	cmake --build build --config ${BUILD_TYPE}
