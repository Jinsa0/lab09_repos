// lab09_02_01.cpp
// Кіц Роман Романович
// Лабораторна робота № 9.2.1
// Директиви препроцесора.
// Варіант 12
#include "macros.h"

using namespace std;

int main()
{
	double x, y, w;

	cout << "x = "; cin >> x;
	cout << "y = "; cin >> y;

	#if (Z >= 1) && (Z < 10)
		w = SQR(MIN(x + y, x + Z));
	#else
		w = MAX(SQR(x), 5 * ABS(y - Z));
	#endif

	PRINT(w);

	return 0;
}