#include <stdio.h>
#define WIDTH 4
#define IN 1
#define OUT 0

int enough_for_tab(int size);

int main(){
	int ch, tabstop, space;
	tabstop = 0;
	while((ch=getchar()) != EOF){
		if (ch == ' ') {
			tabstop++;
			// printf("found space, tabstop value: %d\n", tabstop);
			while ((space = getchar()) == ' ') {
				tabstop++;
				// printf("again, tabstop value: %d\n", tabstop);
				if (tabstop == WIDTH) {
					printf("%c",'\t');
					tabstop = 0;
					break;
				}
			}
			if (tabstop < WIDTH) {
				while (tabstop > 0) {
					putchar(' ');
					tabstop--;
				}
			}
			if (space != ' ') putchar(space);

		}
		
		else putchar(ch);
	}
		
}
