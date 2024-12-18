ifndef BUILD_TYPE
override BUILD_TYPE = Release
endif

ifndef VERBOSE
override VERBOSE = OFF
endif

.PHONY: check-format
check-format:
	find . -name "*.cpp" -exec clang-format -n --verbose {} \;
	find . -name "*.h" -exec clang-format -n --verbose {} \;

.PHONY: format
format:
	find . -name "*.cpp" -exec clang-format -i {} \;
	find . -name "*.h" -exec clang-format -i {} \;

.PHONY: install-python
install-python:
	sudo apt-get install python3-pip -y
	pip install -r python/requirements.txt

.PHONY: run-python
run-python:
	python python/djikstra.py
	python python/mytf.py
	python python/arrays.py
	python python/iterative_dfs.py
	python python/recursive_dfs.py
	python python/questions.py

.PHONY: install-rust
install-rust:
	curl https://sh.rustup.rs -sSf > install-rust.sh
	chmod 755 install-rust.sh
	./install-rust.sh -y	
	rm ./install-rust.sh
	export PATH="${HOME}/.cargo/bin:${PATH}"

.PHONY: install-prerequisites
install-prerequisites:
	sudo apt-get update
	sudo TZ="America/Los_Angeles" apt-get install sudo cmake make git software-properties-common build-essential clang-format -y
	sudo add-apt-repository ppa:ubuntu-toolchain-r/test -y
	sudo apt-get update
	sudo apt-get upgrade libstdc++6
	strings /usr/lib/x86_64-linux-gnu/libstdc++.so.6 | grep GLIBCXX
	git clone https://github.com/google/googletest.git -b v1.14.0 googletest
	mkdir googletest-build
	cmake -S googletest -B googletest-build
	cmake --build googletest-build
	sudo make -C googletest-build install
	rm -rf googletest googletest-build

.PHONY: build-rust
build-rust: install-rust
	cargo check --manifest-path projects/hello-rust/hello_cargo/Cargo.toml
	cargo build --manifest-path projects/hello-rust/hello_cargo/Cargo.toml
	cargo check --manifest-path projects/hello-threads/Cargo.toml
	cargo build --manifest-path projects/hello-threads/Cargo.toml

.PHONY: test-rust
test-rust: build-rust
	cargo run --manifest-path projects/hello-rust/hello_cargo/Cargo.toml
	cargo run --manifest-path projects/hello-threads/Cargo.toml

.PHONY: build-local-env
build-local-env:
	docker build . -t local-env/latest

.PHONY: build
build:
	cmake -B build -DCMAKE_BUILD_TYPE=${BUILD_TYPE} -DCMAKE_VERBOSE_MAKEFILE=${VERBOSE}
	cmake --build build --config ${BUILD_TYPE}

.PHONY: test
test: build
	cd build && make Test

.PHONY: clean
clean:
	rm -fR build
