#include <stdio.h>
#include "postFix.h"

int main() {

	char ex1[] = "(A+B)*C-D";
	char ex2[] = "A*B*C/D+E+F*G";
	char ex3[] = "A/B+(C*D)-E";
	char ex4[] = "A*(B+C)-E/F";
	char ex5[] = "A+B+C+D+E";
	char ex6[] = "A*B/((C+D)/E)-G";


	//postfix(ex1);
	//postfix(ex2);
	//postfix(ex3);
	//postfix(ex4);
	//postfix(ex5);
	postfix(ex6);

	return 0;
}