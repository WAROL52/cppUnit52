#include "cppUnit52.hpp"

int sum(int a, int b)
{
	return (a + b);
}

int diff(int a, int b)
{
	return (a - b);
}

void test_sum_posivif(Expect<int> &expect)
{
	int val1 = sum(1, 2);
	expect(val1).toBe(3).toBe(45).toBe(789);

	int val2 = sum(3, 9);
	expect(val2).toBe(12);
}

void test_sum_negatif(Expect<int> &expect)
{
	int val1 = sum(-1, -2);
	expect(val1).toBe(-3);

	int val2 = sum(-3, -9);
	expect(val2).toBe(-12);
}

void test_diff_posivif(Expect<int> &expect)
{
	int val1 = diff(1, 2);
	expect(val1).toBe(-1);

	int val2 = diff(1, 2);
	expect(val2).toBe(-6);
}

void test_diff_negatif(Expect<int> &expect)
{
	int val1 = diff(-1, -2);
	expect(val1).toBe(1);

	int val2 = diff(-3, -9);
	expect(val2).toBe(6);
}


/* void	test_plus(Expect<int> &expect)
{
	int result(1 + 2);

	expect(result).toBe(3).Not->toBe(4);
}

int main(void)
{
	Describe	desc("test");

	desc.test("une", test_plus);
	return (0);
} */


int main(int argc, char **argv)
{
	Tester tester(argc, argv);

	Describe &descSum = tester.describe("test somme");
	descSum.test("valeur positif", test_sum_posivif)
		.test("valeur negatif", test_sum_negatif);

	Describe &descDiff = tester.describe("test diff");
	descDiff.test("valeur positif", test_diff_posivif)
		.test("valeur negatif", test_diff_negatif);

	return tester.run();
}
