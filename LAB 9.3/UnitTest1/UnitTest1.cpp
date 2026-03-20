#include "pch.h"
#include "CppUnitTest.h"

#include "D:\LAB 9.3\Project1\Source.cpp"

#include <string>
using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestNotes
{
	TEST_CLASS(UnitTestNotes)
	{
	public:

		TEST_METHOD(TestFindBySurname_Found)
		{
			Note arr[2];

			arr[0].surname = "Ivanenko";
			arr[1].surname = "Petrenko";

			int index = findBySurname(arr, 2, "Petrenko");

			Assert::AreEqual(1, index);
		}

		TEST_METHOD(TestFindBySurname_NotFound)
		{
			Note arr[2];

			arr[0].surname = "Ivanenko";
			arr[1].surname = "Petrenko";

			int index = findBySurname(arr, 2, "Shevchenko");

			Assert::AreEqual(-1, index);
		}

		TEST_METHOD(TestSortByPhone)
		{
			Note arr[3];

			arr[0].phone = "999";
			arr[1].phone = "111";
			arr[2].phone = "555";

			sortByPhone(arr, 3);

			Assert::AreEqual(string("111"), arr[0].phone);
			Assert::AreEqual(string("555"), arr[1].phone);
			Assert::AreEqual(string("999"), arr[2].phone);
		}

		TEST_METHOD(TestSortSingleElement)
		{
			Note arr[1];
			arr[0].phone = "123";

			sortByPhone(arr, 1);

			Assert::AreEqual(string("123"), arr[0].phone);
		}

		TEST_METHOD(TestEmptyArraySearch)
		{
			Note* arr = nullptr;

			int result = findBySurname(arr, 0, "Test");

			Assert::AreEqual(-1, result);
		}

		TEST_METHOD(TestFullRecord)
		{
			Note n;

			n.surname = "Bond";
			n.name = "James";
			n.phone = "007";
			n.birth[0] = 1;
			n.birth[1] = 1;
			n.birth[2] = 2000;

			Assert::AreEqual(string("Bond"), n.surname);
			Assert::AreEqual(string("James"), n.name);
			Assert::AreEqual(string("007"), n.phone);
			Assert::AreEqual(1, n.birth[0]);
			Assert::AreEqual(1, n.birth[1]);
			Assert::AreEqual(2000, n.birth[2]);
		}
	};
}

