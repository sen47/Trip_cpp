#pragma once
#include<string>
#include<iostream>

class Check
{
public:
	template<typename T>
	static T inputCheck(const char* output = "");
};

#include"Check.inl"