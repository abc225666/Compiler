#include <bits/stdc++.h>

using namespace std;

int a;
int c= a;

int main()
{
	char *num = strdup("1e+5");
	char output[200];
	float a = atof(num);
	sprintf(output,"%f",a);
	printf("%s\n",output);
	return 0;
}

int b;