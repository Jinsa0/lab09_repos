// macros.h — константа препроцесора та макроси для обчислення виразу
#pragma once
#include <iostream>

#define Z 5

#define SQR(a) ((a) * (a))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define ABS(a) (((a) < 0) ? -(a) : (a))

#define PRINT(res) (std::cout << #res << " = " << (res) << "\n")