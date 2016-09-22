#include "worldType.h"
#include <time.h>

int main()
{
	WorldType dungeon;
	srand(static_cast<unsigned int>(time(0)));

	while (dungeon.running());


	system("pause");
	return 0;
}