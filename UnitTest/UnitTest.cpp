#include "pch.h"
#include "CppUnitTest.h"
#include "../Full-victory/Full-victory.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod)
		{			
			Assert::IsTrue(main(0, 0) == 0);
			Logger::WriteMessage("Pass\n\n");
		}
	};
}

// Классов нет, функций тоже
// Не знаю, что тестировать =)