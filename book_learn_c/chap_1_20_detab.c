#include <stdio.h>
#define WIDTH 4


int main(){
	int ch;
	while((ch=getchar()) != EOF){
		if (ch =='\t') {
			for(int i = 0; i < WIDTH; i++){
				putchar('-');
			}
			continue;
		}
		else {
			putchar(ch);
		}
	}
}