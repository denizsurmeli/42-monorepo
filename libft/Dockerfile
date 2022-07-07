FROM ubuntu:latest

RUN apt-get update \
    && apt-get install -y \
    git \
    g++ \
    gcc \
    cmake \
    make

WORKDIR /src
COPY . libft

WORKDIR /src/libft
RUN mkdir build
RUN cmake -S . -B build
RUN cmake --build build
WORKDIR /src/libft/build/tests
RUN ctest


