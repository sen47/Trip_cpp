#pragma once
#include<string>
#include<iostream>

template<typename T>
class Check
{
public:
	//checking input value, for match data type
	static T inputCheck(const char* output = "");
};

#include"Check.inl"