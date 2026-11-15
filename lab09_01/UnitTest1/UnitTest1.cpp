#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>
#include "../lab09_01/var.cpp"
#include "../lab09_01/dod.cpp"
#include "../lab09_01/sum.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		// 1. Перевірка dod(): перехід від a0 до a1 (n = 1, x = -2)
		TEST_METHOD(TestDodFirstStep)
		{
			nsVar::x = -2.0;
			nsVar::a = -1.0 / nsVar::x;   // a0 = 0.5
			nsVar::n = 1;
			nsDod::dod();                 // a1 = 1 / (3 * (-8)) = -1/24
			Assert::AreEqual(-1.0 / 24.0, nsVar::a, 1e-9);
		}

		// 2. Перевірка dod(): перехід від a1 до a2 (n = 2, x = -2)
		TEST_METHOD(TestDodSecondStep)
		{
			nsVar::x = -2.0;
			nsVar::a = -1.0 / 24.0;       // a1 = -1/24
			nsVar::n = 2;
			nsDod::dod();                 // a2 = -1 / (5 * (-32)) = 1/160
			Assert::AreEqual(1.0 / 160.0, nsVar::a, 1e-9);
		}

		// 3. Перевірка sum() при x = -2 та eps = 0.0001
		TEST_METHOD(TestSumAtMinus2)
		{
			nsVar::x = -2.0;
			nsVar::eps = 0.0001;
			nsSum::sum();
			Assert::AreEqual(atan(nsVar::x), nsVar::s, nsVar::eps);
			Assert::IsTrue(nsVar::n > 0);
		}

		// 4. Перевірка sum() при x = -5 з високою точністю eps = 1e-6
		TEST_METHOD(TestSumSmallEps)
		{
			nsVar::x = -5.0;
			nsVar::eps = 1e-6;
			nsSum::sum();
			Assert::AreEqual(atan(nsVar::x), nsVar::s, nsVar::eps);
		}

		// 5. Перевірка sum() поблизу межі збіжності (x = -1.2), де потрібно багато доданків
		TEST_METHOD(TestSumNearBoundary)
		{
			nsVar::x = -1.2;
			nsVar::eps = 0.001;
			nsSum::sum();
			Assert::AreEqual(atan(nsVar::x), nsVar::s, nsVar::eps);
			Assert::IsTrue(nsVar::n > 5);
		}

		// 6. Перевірка логіки головного модуля: прохід по всьому інтервалу [x_p; x_k] з кроком dx
		TEST_METHOD(TestMainLoopInterval)
		{
			nsVar::x_p = -4.0;
			nsVar::x_k = -2.0;
			nsVar::dx = 0.5;
			nsVar::eps = 0.0001;

			int steps = 0;
			nsVar::x = nsVar::x_p;
			while (nsVar::x <= nsVar::x_k)
			{
				nsSum::sum();
				Assert::AreEqual(atan(nsVar::x), nsVar::s, nsVar::eps);
				nsVar::x += nsVar::dx;
				steps++;
			}
			Assert::AreEqual(5, steps); // точки: -4.0, -3.5, -3.0, -2.5, -2.0
		}
	};
}