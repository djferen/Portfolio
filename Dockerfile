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
RUN apt install -y cmake make git software-properties-common build-essential clang-format && \
    rm -rf /var/lib/apt/lists/* && \
    apt clean
    