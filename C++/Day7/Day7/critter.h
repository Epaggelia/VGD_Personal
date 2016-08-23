/*
Critter
========
-hunger: int
-boredom: int
========
+talk(): void
+feed(int): void
+entertain(int): void
+passTime(int h=1, int b=1): void
critter(int h=0, int b=0)
*/

#ifndef CRITTER_H
#define CRITTER_H

class Critter
{
private:
	int _hunger;
	int _boredom;
	
public:
	void talk();
	void feed(int food);
	void entertain(int fun);
	void passtime(int hunger = 1, int boredom = 0);
	Critter(int hunger = 0, int boredom = 0);
};


#endif