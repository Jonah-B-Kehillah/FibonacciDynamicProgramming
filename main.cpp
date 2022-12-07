#include <iostream>
#include <chrono>
#include "the_function.h"
using namespace std;
using namespace std::chrono;

void test(const string &type, int i, int (*fn)(int)) {
	auto start = high_resolution_clock::now();
	int out = fn(i);
	auto stop = high_resolution_clock::now();

	cout << type << "(" << i << "): " << out << ", took " << duration_cast<microseconds>(stop - start).count() << "us" << endl;

}

int main() {

//	cout << the_function::fib(0) << ", " << the_function::fib(1) << ", "
//	<< the_function::fib(2) << ", " << the_function::fib(3) << ", "
//	<< the_function::fib(4) << ", " << the_function::fib(5) << endl;

	string nd = "nonDynamic";
	string d = "dynamic";

	test(nd, 5, the_function::fib);
	test(nd, 8, the_function::fib);
	test(nd, 12, the_function::fib);
	test(nd, 18, the_function::fib);
	test(nd, 25, the_function::fib);
	cout << endl;
	test(d, 5, the_function::fib_DP);
	test(d, 8, the_function::fib_DP);
	test(d, 12, the_function::fib_DP);
	test(d, 18, the_function::fib_DP);
	test(d, 25, the_function::fib_DP);

	return EXIT_SUCCESS;
}