#pragma once
#include<string>
#include<iostream>

class Check
{
public:
	//checking input value, for match data type
	template<typename T>
	static T inputCheck(const char* output = "");
};

#include"Check.inl"