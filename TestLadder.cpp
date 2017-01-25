#include "Game.h"
#include "Game.cpp"
#include <ctype.h>


int main()
{  
	
	const int RANDOMCT = 1;
	Game g("dictionary.txt");
	g.listWords();  //Lists the first ten words in the dictionary as a test.
	//g.play("this", "those");
	//g.play("vicki", "allan");
	g.play("oops", "pops");
	//g.play("happily", "angrily");
	//g.play("slow", "fast");
	//g.play("stone", "money");
	// for (int i = 0; i < RANDOMCT; i++)
 //      g.play("flute");  //if two arguments are not provided, randomly pick both strings.  Use the length of provided argument as length of strings
    
    
}
