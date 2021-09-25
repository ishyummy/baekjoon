#include <stdio.h>
#include <string.h>

char string[20000];
char mo[14] = "koOijpPuhynbml";
char ja[19] = "rsefaqtdwczxvgREQTW";
char two[11][2] = {
	"rt","sw","sg","fr","fa","fq","ft","fx","fv","fg","qt"
};
int count = 0;

void fun1(int n) {
	int flag = 0;
	for (int i = 0; i < 14; i++)
		if (string[n] == mo[i])
			flag = 1;
	if (flag == 0)
		return;
	flag = 0;
	for (int i = 0; i < 19; i++) {
		if (string[n + 1] == ja[i] && ja[i] != 'E' && ja[i] != 'Q' && ja[i] != 'W')
			flag = 1;
	}
	if (flag == 0)
		return;
	flag = 0;
	for (int i = 0; i < 14; i++)
		if (string[n + 2] == mo[i])
			flag = 1;
	if (flag == 0)
		return;
	else {
		count++;
		//printf("fun1, %d\n", n);
	}
		
}

void fun2(int n) {
	int flag = 0;
	for (int i = 0; i < 14; i++)
		if (string[n] == mo[i])
			flag = 1;
	if (flag == 0)
		return;
	flag = 0;
	for (int i = 0; i < 11; i++)
		if (string[n + 1] == two[i][0] && string[n + 2] == two[i][1])
			flag = 1;
	if (flag == 0)
		return;
	flag = 0;
	for (int i = 0; i < 14; i++)
		if (string[n + 3] == mo[i])
			flag = 1;
	if (flag == 0)
		return;
	else {
		count++;
		//printf("fun2, %d\n", n);
	}
		
}

int main() {
	gets(string);
	for (int i = 0; i < strlen(string) - 2; i++)
		fun1(i);
	for (int i = 0; i < strlen(string) - 3; i++)
		fun2(i);
	printf("%d\n", count);
	return 0;
}