FROM ubuntu:22.04

# LABEL about the custom image
LABEL maintainer="Maintainer"
LABEL version="0.1"
LABEL description="This is custom Docker Image for \
the Services."

# Disable Prompt During Packages Installation
ARG DEBIAN_FRONTEND=noninteractive

# Install locales and language
RUN apt update && apt -y install locales && locale-gen en_US.UTF-8
ENV LANG en_US.UTF-8
ENV LANGUAGE en_US:en
ENV LC_ALL en_US.UTF-8

# Install common depedency packages
RUN apt install -y cmake make git software-properties-common build-essential clang-format tree python3-opencv

# Install stdc++ library
RUN add-apt-repository ppa:ubuntu-toolchain-r/test -y && \
	apt-get upgrade libstdc++6 -y

# Install gtest
RUN strings /usr/lib/x86_64-linux-gnu/libstdc++.so.6 | grep GLIBCXX && \
	git clone https://github.com/google/googletest.git -b v1.14.0 googletest && \
	mkdir googletest-build && \
	cmake -S googletest -B googletest-build && \
	cmake --build googletest-build && \
	make -C googletest-build install
