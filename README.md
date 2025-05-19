# cppUnit52

cpp Testing Framework

```cpp
#include "cppUnit52.hpp"

int sum(int a, int b)
{
	return (a + b);
}

int diff(int a, int b)
{
	return (a - b);
}

void test_sum_posivif(Expect<void> &expect)
{
	expect(sum(1,2)).toBe(3);
	expect(sum(3,9)).toBe(12);
}

void test_sum_negatif(Expect<void> &expect)
{
	expect(sum(-1,-2)).toBe(-3);
	expect(sum(-3,-9)).toBe(-12);
}

void test_diff_posivif(Expect<void> &expect)
{
	expect(diff(1,2)).toBe(-1);
	expect(diff(3,9)).toBe(-6);
}

void test_diff_negatif(Expect<void> &expect)
{
	expect(diff(-1,-2)).toBe(1);
	expect(diff(-3,-9)).toBe(6);
}

int main(int argc, char const *argv[])
{
	Tester tester(argc,argv);

	Describe &descSum = tester.describe("test somme");
	descSum.test("valeur positif",test_sum_posivif)
		.test("valeur negatif",test_sum_negatif);

	Describe &descDiff = tester.describe("test diff");
	descDiff.test("valeur positif",test_diff_posivif)
		.test("valeur negatif",test_diff_negatif);

	return tester.run();
}
```
