#include "ReverseInteger.h"
#include <climits>

int Solution6::reverseInteger(int x) {
	return x < 0 ? -reverseInteger(-x) : reverseInteger(x);
}