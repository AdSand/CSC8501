#pragma once
class LargePowers
{
};

template <typename T>
T customPower(T base, T exponent)
{
	if (base == 0 || base == 1 || exponent == 0) return 1;
	T original = base;
	for (int i = 1; i < exponent; i++)
	{
		base *= original;
	}
	return base;
}

template <typename T>
bool verifyLargeConjecture(T A, T x, T B, T y, T C, T z)
{
	if ((x <= 2) || (y <= 2) || (z <= 2))
	{
		return false;
	}
	return ((customPower<T>(A, x) + customPower<T>(B, y)) == customPower<T>(C, z));
}