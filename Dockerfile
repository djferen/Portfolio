FROM ubuntu:20.04

# LABEL about the custom image
LABEL maintainer="Maintainer"
LABEL version="0.1"
LABEL description="This is custom Docker Image for \
the Services."

# Disable Prompt During Packages Installation
ARG DEBIAN_FRONTEND=noninteractive

# Update Ubuntu Software repository
RUN apt update

# Install from ubuntu repository
RUN apt install -y cmake make git software-properties-common build-essential clang-format

RUN add-apt-repository ppa:ubuntu-toolchain-r/test -y && \
	apt-get upgrade libstdc++6 -y

RUN strings /usr/lib/x86_64-linux-gnu/libstdc++.so.6 | grep GLIBCXX && \
	git clone https://github.com/google/googletest.git -b v1.14.0 googletest && \
	mkdir googletest-build && \
	cmake -S googletest -B googletest-build && \
	cmake --build googletest-build && \
	make -C googletest-build install
