#include "pch.h"
#include "CppUnitTest.h"

#include "D:\LAB 9.2 B\Project1\Source.cpp"

#include <string>
using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestB
{
	TEST_CLASS(UnitTestB)
	{
	public:

		TEST_METHOD(TestComputerScienceStudent)
		{
			Student s;

			s.surname = "Petrenko";
			s.course = 1;
			s.speciality = COMPUTER_SCIENCE;
			s.physics = 80;
			s.math = 75;
			s.third.programming = 95;

			Assert::AreEqual(string("Petrenko"), s.surname);
			Assert::AreEqual(1, s.course);
			Assert::AreEqual((int)COMPUTER_SCIENCE, (int)s.speciality);
			Assert::AreEqual(80, s.physics);
			Assert::AreEqual(75, s.math);
			Assert::AreEqual(95, s.third.programming);
		}

		TEST_METHOD(TestInformaticsStudent)
		{
			Student s;

			s.surname = "Ivanenko";
			s.course = 2;
			s.speciality = INFORMATICS;
			s.physics = 70;
			s.math = 85;
			s.third.numerical = 88;

			Assert::AreEqual(string("Ivanenko"), s.surname);
			Assert::AreEqual(2, s.course);
			Assert::AreEqual((int)INFORMATICS, (int)s.speciality);
			Assert::AreEqual(70, s.physics);
			Assert::AreEqual(85, s.math);
			Assert::AreEqual(88, s.third.numerical);
		}

		TEST_METHOD(TestOtherStudent)
		{
			Student s;

			s.surname = "Shevchenko";
			s.course = 3;
			s.speciality = OTHER;
			s.physics = 60;
			s.math = 65;
			s.third.pedagogy = 90;

			Assert::AreEqual(string("Shevchenko"), s.surname);
			Assert::AreEqual(3, s.course);
			Assert::AreEqual((int)OTHER, (int)s.speciality);
			Assert::AreEqual(60, s.physics);
			Assert::AreEqual(65, s.math);
			Assert::AreEqual(90, s.third.pedagogy);
		}

		TEST_METHOD(TestArrayOfStudents)
		{
			const int n = 2;
			Student s[n];

			s[0].surname = "A";
			s[0].speciality = COMPUTER_SCIENCE;
			s[0].third.programming = 100;

			s[1].surname = "B";
			s[1].speciality = OTHER;
			s[1].third.pedagogy = 50;

			Assert::AreEqual(string("A"), s[0].surname);
			Assert::AreEqual(100, s[0].third.programming);

			Assert::AreEqual(string("B"), s[1].surname);
			Assert::AreEqual(50, s[1].third.pedagogy);
		}
	};
}

