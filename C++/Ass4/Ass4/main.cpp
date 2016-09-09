/*
RPG Character Maker
Write a program that simulates the character creation process found in most RPG games. The character must be defined by the following traits: name, race, class, strength, dexterity, constitution, wisdom, intelligence, and charisma.

•	The character data must be stored inside a c++ class called Character. 
	The functionality of the class is up to you (think about what data members
	you need, and what access you require).
•	The user can enter name, race, and class manually (BONUS: Only allow name 
	to be entered manually. Race and class are selected from a list of predefined 
	options*).
•	The 6 traits cannot be lower than 8 or greater than 18. Use 10 as an average, 
	and randomize between -2 and 8 to ADD to the base value.
•	Write a Character class function called Display that will show the character’s 
	traits in a readable format. Use this function to show the character after the 
	creation process.
•	Ask the user if they are happy with the results. If not, generate the character 
	again.
•	*BONUS: Add bonuses or penalties to the traits based on race/class selection. 
	The details of which are up to you (e.g. picking an Elf class assigns a bonus 
	of +2 dex, but -2 str). The bonuses CAN modify the stats beyond the range of 8 – 18.

Example:
Please enter a name: Jeff
Select a race: Dwarf
Select a class: Thief
Character Sheet:
Name: Jeff
Race: Dwarf
Class: Thief
STR: 12	DEX: 13
CON: 14	WIS: 8
INT: 10	CHA: 9
Is this ok? (y/n): y
Happy gaming!

*/