#include "pch.h"
#include "CppUnitTest.h"
#include "../lab09_02_01/macros.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		// 1. Перевірка макросу SQR (зокрема з виразом у дужках та від'ємним числом)
		TEST_METHOD(TestSqrMacro)
		{
			Assert::AreEqual(25.0, SQR(2.0 + 3.0), 1e-9);
			Assert::AreEqual(16.0, SQR(-4.0), 1e-9);
		}

		// 2. Перевірка макросу MIN
		TEST_METHOD(TestMinMacro)
		{
			Assert::AreEqual(3.0, MIN(3.0, 7.0), 1e-9);
			Assert::AreEqual(-5.0, MIN(-2.0, -5.0), 1e-9);
		}

		// 3. Перевірка макросу MAX
		TEST_METHOD(TestMaxMacro)
		{
			Assert::AreEqual(10.0, MAX(4.0, 10.0), 1e-9);
			Assert::AreEqual(-1.0, MAX(-1.0, -3.0), 1e-9);
		}

		// 4. Перевірка макросу ABS
		TEST_METHOD(TestAbsMacro)
		{
			Assert::AreEqual(7.0, ABS(-7.0), 1e-9);
			Assert::AreEqual(7.0, ABS(7.0), 1e-9);
		}

		// 5. Перевірка формули Варіанта 12 для активної гілки Z
		TEST_METHOD(TestVariant12Formula)
		{
			double x = 2.0, y = 1.0, w = 0.0;

#if (Z >= 1) && (Z < 10)
			w = SQR(MIN(x + y, x + Z));
			double expected = ((x + y) < (x + Z) ? (x + y) : (x + Z));
			expected *= expected;
#else
			w = MAX(SQR(x), 5 * ABS(y - Z));
			double diff = (y - Z) < 0 ? -(y - Z) : (y - Z);
			double expected = (x * x > 5 * diff) ? (x * x) : (5 * diff);
#endif

			Assert::AreEqual(expected, w, 1e-9);
		}
	};
}