extern "C"{
#include "../libft/libft.h"
};
#include <iostream>
#include <cstring>

int main(){
	//if you want an app
	char *src = "/|\x12\xff\x09\0\x42\042\0\42|\\";
	int size = 12;
	std::cout<< memchr(src, '\0', size) << "," << ft_memchr(src, '\0', size) << std::endl;
}