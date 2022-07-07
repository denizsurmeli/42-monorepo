extern "C"
{
#include "libft/libft.h"
}

#include <gtest/gtest.h>
#include <algorithm>
#include <deque>
#include <iostream>
#include <string>

TEST(libft, ft_lstnew)
{
	char *content = "content";

	t_list *l = ft_lstnew((void *) content);
	EXPECT_EQ(l->content, content);
	EXPECT_EQ(l->next == NULL, 1);
}

TEST(libft, ft_lstadd_front)
{
	std::deque<char *> content_list = {
		"2","3","4","5"
	};

	t_list *l;
	l = ft_lstnew((void *)"1");
	for(auto elem:content_list)
	{
		t_list *t =new t_list{(void *)elem,(t_list *)nullptr};
		ft_lstadd_front(&l,t);
	}
	std::deque<char *> expect = {
		"5","4","3","2","1"
	};
	std::deque<char *> result = {};
	t_list *it = l;

	while(it->next != nullptr)
	{
		result.push_back((char *)it->content);
		it = it ->next;
	}
	result.push_back((char *)it->content);
	EXPECT_EQ(expect.size(),result.size());
	for(size_t i = 0 ; i < expect.size(); i++)
	{
		EXPECT_EQ(std::string(expect.at(i)),std::string(result.at(i)));
	}
}

TEST(libft, ft_lstsize)
{
	std::deque<char *> values =
	{
		"1","2","3","4","5"
	};

	t_list *l = new t_list{(void *)"0",nullptr};
	for(auto value:values)
	{
		ft_lstadd_front(&l,new t_list{(void *) value,nullptr});
	}
	EXPECT_EQ(ft_lstsize(l),6);
}

TEST(libft, ft_lstlast)
{
	std::deque<char *> values =
	{
		"1","2","3","4","5"
	};
	t_list *l = new t_list{(void *)"0",nullptr};
	for(auto value:values)
	{
		ft_lstadd_front(&l,new t_list{(void *) value, nullptr});
	}
	t_list *t = ft_lstlast(l);
	EXPECT_EQ(std::string((char *)(t->content)),"0");
}

TEST(libft, ft_lstadd_back)
{
	std::deque<char *> content_list = {
		"2","3","4","5"
	};

	t_list *l;
	l = ft_lstnew((void *)"1");
	for(auto elem:content_list)
	{
		t_list *t =new t_list{(void *)elem,(t_list *)nullptr};
		ft_lstadd_back(&l,t);
	}
	std::deque<char *> expect = {
		"1","2","3","4","5"
	};
	std::deque<char *> result = {};
	t_list *it = l;

	while(it->next != nullptr)
	{
		result.push_back((char *)it->content);
		it = it ->next;
	}
	result.push_back((char *)it->content);
	EXPECT_EQ(expect.size(),result.size());
	for(size_t i = 0 ; i < expect.size(); i++)
	{
		EXPECT_EQ(std::string(expect.at(i)),std::string(result.at(i)));
	}
}

void	remove(void * v)
{
	if(v != nullptr)
		delete (v);
}
