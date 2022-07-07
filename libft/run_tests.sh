#!/bin/sh
#sh put_headers.sh
#norminette libft
cmake -S . -B build
cmake --build build
cd build/tests && ./ft_test