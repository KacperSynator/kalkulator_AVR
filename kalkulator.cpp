#include "kalkulator.h"


kalkulator::kalkulator()
{
	num=0;
	mem=0;
	result=0;
	znak=0;
	waiting=false;
	reading_num=false;
	point=false;
}

void kalkulator::clear()
{
	waiting=false;
	reading_num=false;
	point=false;
	num=0;
	result=0;
	znak=0;
}
void kalkulator::clear_last()
{
	if(reading_num)
		num=0;
	point=false;
}
void kalkulator::set_znak(char z)
{
	point=false;
	if((waiting && reading_num) || z=='=')
	{
		calculate();
		reading_num=false;
	}
	else if(waiting && !reading_num && z!='z')
	{
		znak=z;
		num=result;
	}
	else if(!waiting)
	{
		reading_num=false;
		waiting=true;
		znak=z;
	}
}

void kalkulator::read(int li)
{
	if(waiting && !reading_num)
	{
		if(num!=0) result=num;
		num=0;
	}
	reading_num=true;
	if(!point)
	{
		num*=10;
		num+=li;
		sprintf(buf,"%d.",(int)num);
	}
	else
	{
		sprintf(buf,"%s%d",buf,li);
		num = atof(buf);
	}
}


void kalkulator::mem_show()
{
	point=false;
	reading_num=false;
	num=mem;
}
void kalkulator::_sqrt()
{
	znak='s';
	reading_num=false;
	waiting=true;
	calculate();
}

/*void kalkulator::_log()
{
	znak='l';
	reading_num=false;
	waiting=true;
	calculate();
}*/

void kalkulator::calculate()
{
	point=false;
	switch(znak)
	{
	case '+':
	{
		result+=num;
		break;
	}
	case '-':
	{
		result -=num;
		break;
	}
	case '*':
	{
		result *=num;
		break;
	}
	case '/':
	{
		if(num!=0) result/=num;
		break;
	}
	case '^':
	{
		if(num==0) result=1;
		double tmp = result;
		for(int i=1;i<num;i++)
			result*=tmp;
		break;
	}
	case '%':
	{
		result=fmod(result,num);
		break;
	}
	case 's':
	{
		if(num>=0) result=sqrt(num);
		num=result;
		break;
	}
	/*case 'l':
	{
		if(num>=0) result=log(num);
		num=result;
		break;
	}*/
	}
}


