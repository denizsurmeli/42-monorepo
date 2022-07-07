#include <cstring>
#include <gtest/gtest.h>
#include <vector>
extern "C"
{
#include "libft/libft.h"
}

TEST(libft, ft_memset)
{
	// set 64 bytes filled with 'v'.
	size_t memsize = 64;
	int c = 'v';
	void *mem = malloc(sizeof(unsigned char) * memsize);
	auto *temp_mem = (unsigned char *)memset(mem, c, memsize);
	// if null returned, no fill.
	if (temp_mem == NULL)
	{
		FAIL();
	}
	// expect every byte in size of memsize is equal to filled char.
	for (size_t i = 0; i < memsize; i++)
	{
		EXPECT_EQ(temp_mem[i], (unsigned char)c) << "Values differ between libc and implementation.";
	}
	delete mem, temp_mem;
}

TEST(libft, ft_bzero)
{
	size_t memsize = 64;
	void *mem = malloc(sizeof(unsigned char) * memsize);
	ft_bzero(mem, memsize);

	auto *temp_mem = (unsigned char *)mem;
	for (size_t i = 0; i < memsize; i++)
	{
		EXPECT_EQ(temp_mem[i], 0) << "Values differ between libc and implementation.";
	}
	delete mem, temp_mem;
}

TEST(libft, ft_memcpy)
{
	size_t memsize = 64;
	auto *mem = (unsigned char *)malloc(sizeof(unsigned char) * memsize);
	auto *dest = (unsigned char *)malloc(sizeof(unsigned char) * memsize);
	int ch = 'c';
	mem = (unsigned char *)ft_memset(mem, ch, memsize);
	ft_memcpy(dest, mem, memsize);
	for (size_t i = 0; i < memsize; i++)
	{
		EXPECT_EQ(mem[i], dest[i]) << "Values differ between libc and implementation.";
	}

	delete mem, dest;
}

TEST(libft, ft_memccpy)
{
	size_t memsize = 64;
	auto *mem = (unsigned char *)malloc(sizeof(unsigned char) * memsize);
	auto *dest_1 = (unsigned char *)malloc(sizeof(unsigned char) * memsize);
	auto *dest_2 = (unsigned char *)malloc(sizeof(unsigned char) * memsize);
	int ch = 'c';
	int cb = 'k';

	mem = (unsigned char *)ft_memset(mem, ch, memsize);
	mem[16] = cb;

	auto *l1 = (unsigned char *)ft_memccpy(dest_1, mem, cb, memsize);
	auto *l2 = (unsigned char *)memccpy(dest_2, mem, cb, memsize);
	for (size_t i = 0; i < 16; i++)
	{
		EXPECT_EQ(dest_1[i], dest_2[i]) << "Values differ between libc and implementation.";
	}
	EXPECT_EQ(l1 - dest_1, l2 - dest_2) << "Distance between memory locations of locations are not consistent between libc and implementation.";
	EXPECT_EQ(l1 - dest_1, 17) << "Exact size of memory difference is not met.";

	delete mem, dest_1, dest_2;
}

TEST(libft, ft_memmove)
{
	/// https://github.com/Tripouille/libftTester/blob/master/tests/ft_memmove_test.cpp
	/// Also very good article if man seems vague:https://stackoverflow.com/questions/1201319/what-is-the-difference-between-memmove-and-memcpy
	char s[] = {65, 66, 67, 68, 69, 0, 45};
	char s0[] = {0, 0, 0, 0, 0, 0, 0};
	char sCpy[] = {65, 66, 67, 68, 69, 0, 45};
	char sResult[] = {67, 68, 67, 68, 69, 0, 45};
	char sResult2[] = {67, 67, 68, 68, 69, 0, 45};

	// No overlap -> one of the paths depending on how they located.
	EXPECT_EQ(ft_memmove(s0, s, 7), s0);
	EXPECT_EQ(memcmp(s, s0, 7), 0);
	// Overlap -> no byte read
	EXPECT_TRUE(ft_memmove(s, s + 2, 0));
	EXPECT_EQ(memcmp(s, sCpy, 7), 0);
	// Overlap -> dest < src, cpy in reverse.
	EXPECT_EQ((ft_memmove(s, s + 2, 2)), s);
	EXPECT_EQ(memcmp(s, sResult, 7), 0);
	// Overlap -> src < dest, cpy regular.
	EXPECT_EQ(ft_memmove(sResult + 1, sResult, 2), sResult + 1);
	EXPECT_EQ(memcmp(sResult, sResult2, 7), 0);
}

TEST(libft, ft_memchr)
{
	size_t memsize = 64;
	char *mem = (char *)malloc(memsize * sizeof(char));
	char fb = 'b';
	char ff = 'f';
	ft_memset(mem, fb, memsize);
	mem[16] = ff;

	char *f_locate = static_cast<char *>(ft_memchr(mem, ff, memsize));
	EXPECT_EQ(f_locate, mem + 16);

	char *f_nolocate = static_cast<char *>(ft_memchr(mem, 'g', memsize));
	EXPECT_EQ(f_nolocate, nullptr);

	delete mem;
}

TEST(libft, ft_memcmp)
{
	size_t memsize = 64;
	char *mem_1 = (char *)malloc(memsize * sizeof(char));
	char *mem_2 = (char *)malloc(memsize * sizeof(char));
	char filler = 'a';
	char differ = 'b';

	ft_memset(mem_1, filler, memsize);
	ft_memset(mem_2, filler, memsize);

	mem_2[memsize - 1] = differ;
	EXPECT_EQ(ft_memcmp(mem_1, mem_2, memsize), memcmp(mem_1, mem_2, memsize));

	mem_2[memsize - 1] = filler;
	mem_1[memsize - 1] = differ;

	EXPECT_EQ(ft_memcmp(mem_1, mem_2, memsize), memcmp(mem_1, mem_2, memsize));

	delete mem_1, mem_2;
}

TEST(libft, ft_memalloc)
{
	size_t	memsize = 64;

	char *mem = static_cast<char *>(ft_memalloc(memsize));

	for(size_t i = 0 ; i < memsize ; i++){
		EXPECT_EQ(mem[i], 0);
	}
}
