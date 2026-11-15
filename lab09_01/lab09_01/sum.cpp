// sum.cpp — реалізація обчислення суми ряду Тейлора із заданою точністю eps
#include <math.h>
#include "dod.h"
#include "sum.h"
#include "var.h" // підключили зовнішні оголошення змінних

using namespace nsDod;
using namespace nsVar;

void nsSum::sum() {
	n = 0;
	a = -1.0 / x;
	s = -2 * atan(1.0) + a;
	do {
		n++;
		dod(); // виклик процедури обчислення доданку
		s += a;
	} while (fabs(a) > eps);
}