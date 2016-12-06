#pragma once
#include <string>

using namespace std;

class Assertions
{
public:
	static void assertTrue(bool expression, string error);
	static void assertEquals(string test_name, float value, float expected);
	template <typename T>
	static void assertEquals(string test_name, T value, T expected);
	static string getErrors();
	static int getCode();

private:
	static string errors;
	static int code;
	Assertions();
};

template <class T>
void Assertions::assertEquals(string test_name, T value, T expected)
{
	Assertions::assertTrue(value == expected, "Test: \"" + test_name + "\" failed. Expected: " + expected + " Actual: " + value);
}
