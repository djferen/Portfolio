
.PHONY: install-format
install-format:
	pip3 install clang-format

.PHONY: install-gtest
install-gtest:
	git clone https://github.com/google/googletest.git -b v1.14.0 googletest
	mkdir -p googletest/build
	cd googletest/build
	cmake ..
	make
	sudo make install
	cd ../..
	rm -rf googletest

.PHONY: check-format
check-format:
	find . -name "*.cpp" -exec clang-format -n --verbose {} \;
	find . -name "*.h" -exec clang-format -n --verbose {} \;

.PHONY: format
format:
	find . -name "*.cpp" -exec clang-format -i {} \;
	find . -name "*.h" -exec clang-format -i {} \;
