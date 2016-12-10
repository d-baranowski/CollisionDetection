#pragma once
#include <string>

using namespace std;

class Assertions
{
public:
	static void assert_true(bool expression, string error);
	template <typename T>
	static void assert_equals(string test_name, T value, T expected);
	static string getErrors();
	static int getCode();

private:
	static string errors;
	static int code;
	Assertions();
};

template <class T>
void Assertions::assert_equals(string test_name, T value, T expected)
{
	Assertions::assert_true(value == expected, "Test: \"" + test_name + "\" failed. Expected: " + expected + " Actual: " + value);
}
