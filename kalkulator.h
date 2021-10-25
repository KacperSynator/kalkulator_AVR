#ifndef KALKULATOR_H_
#define KALKULATOR_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

class kalkulator
{
private:
	double num;
	double mem;
	double result;
	char znak;
	bool waiting;
	bool reading_num;
	bool point;

	char buf[20];

	void calculate();
public:
	kalkulator();

	void read(int li);
	void clear();
	void clear_last();
	void set_point() {point=true;};
	void mem_add() {mem+=num;};
	void mem_sub() {mem-=num;};
	void mem_clear() {mem=0;};
	void mem_show();
	double get_num() {return num;};
	double get_result() {return result;};
	void set_znak(char z);
	void _sqrt();
	//void _log();  nie kompiluje siê log, jakiœ problem z linkerami


};

#endif /* KALKULATOR_H_ */
