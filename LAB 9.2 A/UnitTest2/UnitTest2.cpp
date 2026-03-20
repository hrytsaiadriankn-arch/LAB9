#include "pch.h"
#include "CppUnitTest.h"

#include "D:\LAB 9.2 A\Project1\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:

		TEST_METHOD(TestSpecialityToString)
		{
			Assert::AreEqual(string("Computer Science"), specialityToString(COMPUTER_SCIENCE));
			Assert::AreEqual(string("Informatics"), specialityToString(INFORMATICS));
			Assert::AreEqual(string("Math & Economics"), specialityToString(MATH_ECONOMICS));
			Assert::AreEqual(string("Physics & Informatics"), specialityToString(PHYSICS_INFORMATICS));
			Assert::AreEqual(string("Labor Training"), specialityToString(LABOR_TRAINING));
		}

		TEST_METHOD(TestStudentData)
		{
			Student s;

			s.surname = "Ivanenko";
			s.course = 2;
			s.speciality = COMPUTER_SCIENCE;
			s.physics = 90;
			s.math = 85;
			s.informatics = 95;

			Assert::AreEqual(string("Ivanenko"), s.surname);
			Assert::AreEqual(2, s.course);
			Assert::AreEqual((int)COMPUTER_SCIENCE, (int)s.speciality);
			Assert::AreEqual(90, s.physics);
			Assert::AreEqual(85, s.math);
			Assert::AreEqual(95, s.informatics);
		}
	};
}
