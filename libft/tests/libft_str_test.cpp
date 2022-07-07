#include <cstring>
#include <gtest/gtest.h>
#include <vector>
extern "C"
{
#include "libft/libft.h"
}

TEST(libft, ft_strlen)
{
	std::vector<char *> words = {"test", "expect", "dlkfasAKSDKfjasa231413", "", "\23\234\23"};
	for (const auto &elem : words)
	{
		EXPECT_EQ(ft_strlen(elem), strlen(elem));
	}
}

TEST(libft, ft_strdup)
{
	std::vector<char *> words = {"test", "expect", "dlkfasAKSDKfjasa231413", "", "\23\234\23"};
	for (const auto &elem : words)
	{
		char *temp = ft_strdup(elem);
		EXPECT_TRUE(!strcmp(temp, elem));
		delete temp;
	}
}

TEST(libft, ft_strcpy)
{
	std::vector<char *> words = {"test", "expect", "dlkfasAKSDKfjasa231413", "", "\23\234\23"};
	for (const auto &elem : words)
	{
		char *d = static_cast<char *>(malloc(128));
		EXPECT_FALSE(strcmp(ft_strcpy(d, elem), elem));
		delete d;
	}
}

TEST(libft, ft_strncpy)
{
	size_t memsize_1 = 64;
	size_t memsize_2 = 32;
	int fill_value = 97;

	char *src1 = static_cast<char *>(malloc(memsize_1 + 1));
	src1 = static_cast<char *>(ft_memset(src1, fill_value, memsize_1));
	src1[memsize_1] = '\0';
	char *dest1 = static_cast<char *>(malloc((memsize_1 + 1) * sizeof(char)));
	// Exact copy with full size;
	ft_strncpy(dest1, src1, memsize_1 + 1);
	EXPECT_EQ(strcmp(dest1, src1), 0);
	delete dest1;

	dest1 = static_cast<char *>(malloc((memsize_1 + 1) * sizeof(char)));
	dest1 = static_cast<char *>(ft_memset(dest1, fill_value + 1, memsize_1));
	dest1[memsize_1] = '\0';
	ft_strncpy(dest1, src1, memsize_2);

	for (size_t i = 0; i < memsize_2; i++)
	{
		EXPECT_EQ(dest1[i], src1[i]);
	}
	delete src1, dest1;
}

TEST(libft, ft_strcat)
{
	size_t memsize_1 = 64;
	size_t memsize_2 = 32;

	char filler_1 = 'a';
	char filler_2 = 'b';

	char *s1 = static_cast<char *>(malloc(memsize_1));
	ft_memset(s1, filler_1, memsize_2 - 1);
	s1[memsize_2 - 1] = '\0';

	char *s2 = static_cast<char *>(malloc(memsize_2));
	ft_memset(s2, filler_2, memsize_2 - 1);
	s2[memsize_2 - 1] = '\0';

	ft_strcat(s1, s2);

	char *s3 = static_cast<char *>(malloc(memsize_1 - 1));
	ft_memset(s3, filler_1, memsize_2 - 1);
	ft_memset(s3 + memsize_2 - 1, filler_2, memsize_2 - 1);
	s3[memsize_1 - 2] = '\0';

	EXPECT_EQ(strcmp(s1, s3), 0);

	delete s1, s2, s3;
}


TEST(libft, ft_strncat)
{
	size_t memsize_1 = 64;
	size_t memsize_2 = 32;
	size_t memsize_3 = 16;

	char filler_1 = 'a';
	char filler_2 = 'b';

	char *s1 = static_cast<char *>(malloc(memsize_1));
	ft_memset(s1, filler_1, memsize_2 - 1);
	s1[memsize_2 - 1] = '\0';

	char *s2 = static_cast<char *>(malloc(memsize_2));
	ft_memset(s2, filler_2, memsize_2 - 1);
	s2[memsize_2 - 1] = '\0';

	ft_strncat(s1, s2,memsize_3);

	char *s3 = static_cast<char *>(malloc(memsize_1 - 1));
	ft_memset(s3, filler_1, memsize_2 - 1);
	ft_memset(s3 + memsize_2 - 1, filler_2, memsize_3);
	s3[memsize_2 + memsize_3 - 1] = '\0';

	EXPECT_EQ(strcmp(s1, s3), 0);

	delete s1, s2, s3;
}

TEST(libft, ft_strlcat)
{
	size_t memsize_1 = 64;
	size_t memsize_2 = 32;

	char	*m1 = static_cast<char *>(malloc(memsize_1));
	char 	*m2 = static_cast<char *>(malloc(memsize_2));

	char 	fill = 'a';
	char 	subfill = 'b';


	ft_memset(m1,fill, memsize_2);
	m1[memsize_2] = 0;
	//m1:32aNULL -> 32lenstr, 33 bytes, left 31
	ft_memset(m2,subfill, memsize_2 - 1);
	m2[memsize_2 - 1] = 0;
	//m2:31bNUll -> 31lenstr, 32 bytes, left 0
	size_t res = ft_strlcat(m1,m2,memsize_1);
	EXPECT_EQ(res, memsize_2 * 2 - 1);
	for(size_t i = 0; i < memsize_2; i++){
		EXPECT_EQ(*(m1+i), fill);
	}
	for(size_t i = memsize_2;i < memsize_1 - 1; i++){
		EXPECT_EQ(*(m1+i), subfill);
	}
	EXPECT_EQ(*(m1+memsize_1 - 1),0);

	delete m1,m2;
}

TEST(libft, ft_strchr)
{
	size_t memsize_1 = 64;

	char *m1 = static_cast<char *>(malloc(memsize_1));

	char haystack = 'a';
	char needle = 'b';
	ft_memset(m1, haystack, memsize_1 - 1);
	m1[memsize_1 - 1] = '\0';

	m1[41] = needle;
	EXPECT_EQ(ft_strchr(m1,needle),strchr(m1,needle));
	EXPECT_EQ(ft_strchr(m1,0x64),strchr(m1,0x64));
}

TEST(libft, ft_strrchr)
{
	size_t memsize_1 = 64;

	char *m1 = static_cast<char *>(malloc(memsize_1));

	char haystack = 'a';
	char needle = 'b';
	ft_memset(m1, haystack, memsize_1 - 1);
	m1[memsize_1 - 1] = '\0';

	m1[41] = needle;
	m1[45] = needle;
	EXPECT_EQ(ft_strrchr(m1,needle),strrchr(m1,needle));
	EXPECT_EQ(ft_strrchr(m1,0x64),strrchr(m1,0x64));
}

TEST(libft, ft_strstr)
{
	char	*haystack = "aaaaaaaaaaaaaaaaaaaaaaaaFINDaaaaaaaaaaaaaaaaaa";
	char	*needle = "FIND";
	char 	*non_needle = "NON";

	EXPECT_EQ(ft_strstr(haystack,needle),strstr(haystack,needle));
	EXPECT_EQ(ft_strstr(haystack,non_needle),strstr(haystack,non_needle));
}

TEST(libft, ft_strcmp)
{
	char	*s1 = "AAAAAAAAAAAAABBBBBBBBBB";
	char 	*s2 = "AAAAAAAAAAAAACCCCCCCCCC";

	EXPECT_EQ(ft_strcmp(s1,s2), strcmp(s1,s2));
	EXPECT_EQ(ft_strcmp(s1,""), strcmp(s1,""));
	EXPECT_EQ(ft_strcmp("",""),strcmp("",""));
}
static bool compare_strncmp(const char *s1, const char *s2, size_t n)
{
	return ft_strncmp(s1,s2,n)==strncmp(s1,s2,n);
}

TEST(libft, ft_strncmp)
{
	// https://github.com/Tripouille/libftTester/blob/master/tests/ft_strncmp_test.cpp
	EXPECT_TRUE(compare_strncmp("t","0",0));
	EXPECT_TRUE(compare_strncmp("1234","12345",3));
	EXPECT_TRUE(compare_strncmp("Tripouille", "Tripouille", 42));
	EXPECT_TRUE(compare_strncmp("Tripouille", "Tripouille", 42));
	EXPECT_TRUE(compare_strncmp("", "1", 0));
}


static bool compare_atoi(const char *s)
{
	return ft_atoi(s) == atoi(s);
}

TEST(libft, ft_atoi)
{
	std::vector<char *> words = {"     -100", " -+ 123", "-2147483648","2147483647", "-1234--12-34=","214812aaa328941"};
	for(auto word:words){
		EXPECT_TRUE(compare_atoi(word)) << "Word:"<<word<<"\tft_atoi:" << ft_atoi(word) << "\tatoi:"<< atoi(word) << std::endl;
	}
}

TEST(libft, ft_strnew)
{
	size_t	memsize = 64;
	char	*loc = ft_strnew(memsize);

	for(size_t i = 0 ; i < memsize + 1; i++){
		EXPECT_EQ(loc[i],0);
	}

	delete loc;
}

void	to_a(char *c){
	*c = 'a';
}

char	to_c(char c){
	return 'c';
}

TEST(libft, ft_striter)
{
	size_t memsize = 64;
	void	*toc = malloc(memsize);
	char	*loc = static_cast<char *>(ft_memset(toc,'b',memsize-1));
	loc[memsize-1] = '\0';
	ft_striter(loc,to_a);
	for(size_t i = 0 ; i< memsize - 1; i++){
		EXPECT_EQ(loc[i],'a') << "i:"<<i;
	}
	delete toc;
}

TEST(libft, ft_strmap)
{
	size_t memsize = 64;
	void	*toc = malloc(memsize);
	char 	*loc = static_cast<char *>(ft_memset(toc, 'b', memsize - 1));
	loc[memsize - 1] = 0;
	char	*mapped = ft_strmap(loc,to_c);
	for(size_t i = 0 ; i < memsize - 1; i++)
	{
		EXPECT_EQ(mapped[i], 'c');
	}
	EXPECT_EQ(mapped[memsize - 1] ,0);
	delete mapped, toc;
}

TEST(libft, ft_strequ)
{
	EXPECT_TRUE(ft_strequ("Test","Test"));
	EXPECT_TRUE(ft_strequ("",""));
	EXPECT_TRUE(ft_strequ(NULL,NULL));
	EXPECT_FALSE(ft_strequ("Test","Not"));
	EXPECT_FALSE(ft_strequ("","Test"));
	EXPECT_FALSE(ft_strequ(NULL,"TEST"));
}

TEST(libft, ft_strnequ)
{
	EXPECT_TRUE(ft_strnequ("test","test",2));
	EXPECT_TRUE(ft_strnequ("testthis","testthiK",7));
	EXPECT_FALSE(ft_strnequ(NULL,"TEST",1));
	EXPECT_FALSE(ft_strnequ("TESTTK","TESTTT",6));
	EXPECT_TRUE(ft_strnequ("","",0));
	EXPECT_TRUE(ft_strnequ(NULL,NULL,10));
}

TEST(libft, ft_substr)
{
	size_t memsize_1 = 64;
	size_t memsize_2 = 32;

	char *mem = (char *) ft_memalloc(memsize_1);
	ft_memset((void *) mem, 0x61 , memsize_1 - 1);
	mem[memsize_1 - 1] ='\0';

	char *mem2 = ft_substr((char const *)mem, memsize_2, 16);
	for(size_t i = 0; i < 16; i++){
		EXPECT_EQ(mem2[i], 0x61) << "i:"<<i;
	}
	EXPECT_EQ(mem2[16],0x00);
}

TEST(libft, ft_strjoin)
{
	char *mem1 = ft_strjoin("ABC","DEF");
	EXPECT_EQ(ft_strequ(mem1,"ABCDEF"),1);

	char *mem2 = ft_strjoin(NULL,NULL);
	EXPECT_EQ(mem2==NULL, 1);

	char *mem3= ft_strjoin("ABC",NULL);
	EXPECT_EQ(ft_strequ(mem3,"ABC"),1);

	delete mem1,mem2,mem3;
}

TEST(libft, ft_strtrim)
{
	char const *set = " \t\n";
	EXPECT_EQ(strcmp(ft_strtrim(" whitespace is this ",set),"whitespace is this"),0) << ft_strtrim(" whitespace is this ",set);
	EXPECT_EQ(strcmp(ft_strtrim("     whitespace is \t this \n with this      \t \t \t",set),"whitespace is \t this \n with this"),0) << ft_strtrim("     whitespace is \t this \n with this      \t \t \t",set);
}
static size_t ft_count_words(char const *s, char c)
{
	size_t count;
	int i;
	int j;

	i = 0;
	j = ft_strlen(s) - 1;
	count = 0;
	while(s[i] == c)
		i++;
	while(s[j] == c)
		j--;
	while(i < j)
	{
		while(s[i] != c)
			i++;
		while(s[i] == c)
			i++;
		count++;
	}
	return (count);
}

TEST(libft, ft_strsplit)
{
	char **mem;
	int count;
	std::map<char *, std::vector<char *>> dict
	{
		{"****aaaa****aaaa***",std::vector<char *>{"aaaa","aaaa"}},
		{"aaaa*****aaaa*a*a*a***",std::vector<char *>{"aaaa","aaaa","a","a","a"}},
		{"*****aaaa***aaaa",std::vector<char *>{"aaaa","aaaa"}},
		{"aaaa***aaaa",std::vector<char *>{"aaaa","aaaa"}},
		{"aaaaaaaaaaa",std::vector<char *>{"aaaaaaaaaaa"}},
		{"***********",std::vector<char *>{}}
	};
	for(auto elem:dict)
	{
		mem = ft_split(elem.first, '*');
		count = ft_count_words(elem.first,'*');
		for(int i = 0 ; i < count;i++)
		{
			EXPECT_EQ(std::string(mem[i]),std::string(elem.second.at(i)));
		}
		delete mem;
	}
}

TEST(libft, ft_itoa)
{
	std::map<int,std::string> dict
	{
		{-100,"-100"},
		{100,"100"},
		{0,"0"},
		{2147483647,"2147483647"},
		{-2147483648,"-2147483648"},
		{2147483642,"2147483642"},
		{-2147483645,"-2147483645"},
		{1,"1"},
		{-1,"-1"}
	};
	for(auto elem:dict)
	{
		EXPECT_EQ(std::string(ft_itoa(elem.first)),elem.second);
	}
}