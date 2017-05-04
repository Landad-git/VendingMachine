#pragma once

class LFSR {
public:
	LFSR(string seed, int t); // constructor to create LFSR with the given initial seed and tap
	string to_string();     // return a string representation of the LFSR's current state
	int step();          // simulate one step and return the new bit as 0 or 1
	int generate(int k); // simulate k steps and return k-bit integer


private:   // data members:
	int N;     //  number of bits in the LFSR
	int* reg;  //  reg[i] = ith bit of LFSR, reg[0] is rightmost bit
	int tap;   //  index of the tap bit

};
