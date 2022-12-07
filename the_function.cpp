#include <iostream>
#include "the_function.h"

int the_function::fib(int i){ // normal
	if(i<0) throw std::invalid_argument("i cannot be less than 0");
	if(i<2) return 1;

	int fb1 = fib(i-1);
	int fb2 = fib(i-2);

	return fb1+fb2;
}

int the_function::fib_DP(int in) { //dynamic programming

	int len = in + 2; // if `in` is less than `2`, this stops manual assignment of first two values from causing error
	int seq [len];

	seq[0] = 1;
	seq[1] = 1;

	for(int i = 2; i < in+1; i++) {
		seq[i] = seq[i-1] + seq[i-2];
	}

	return seq[in];

}