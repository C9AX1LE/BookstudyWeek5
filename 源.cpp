#include<stdio.h>
#include<stdlib.h>
#define Maxsize 255
typedef struct sstring {
	char ch[Maxsize];
	int length;
}SString;
void InitSString(SString& str) {
	str.length = 0;
}
bool IsemptySString(SString& str) {
	if (str.length == 0) {
		return true;
	}
	return false;
}
void StrtoC(SString& str, char chars[]) {
	int i = 0;
	while (chars[i] != '\0') {
		str.ch[++str.length] = chars[i];
		i++;
	}
}
void strAssign(SString& str1, char ch[]) {
	int Flaglength = str1.length;
	while (str1.length) {
		ch[str1.length - 1] = str1.ch[str1.length];
		str1.length--;
	}
	str1.length = Flaglength;
	ch[str1.length] = '\0';
}
void strCopy(SString& str1, SString& str2) {
	int Flaglength = str1.length;
	while (str1.length) {
		str2.ch[str1.length] = str1.ch[str1.length];
		str1.length--;
	}
	str1.length = Flaglength;
	str2.length = Flaglength;
}
SString strcat(SString& str1, SString& str2) {
	SString str3;
	InitSString(str3);
	for (int i = 1; i <= str1.length; i++) {
		str3.ch[++str3.length] = str1.ch[i];
	}
	for (int i = 1; i <= str2.length; i++) {
		str3.ch[++str3.length] = str2.ch[i];
	}
	return str3;
}
int strCompare(SString& str1, SString& str2) {
	int flag = 1;
	int i, j;
	for (i = 1, j = 1; i <= str1.length && j <= str2.length; i++, j++) {
		if (str1.ch[i] > str2.ch[j]) {
			flag = 1;
			break;
		}
		else if (str1.ch[i] == str2.ch[j]) {
			flag++;
		}
		else if (str1.ch[i] < str2.ch[j]) {
			flag = -1;
			break;
		}
	}
	if (flag == i) {
		if (str1.length > str2.length)
			return 1;
		if (str1.length < str2.length)
			return -1;
		if (str1.length == str2.length)
			return 0;
	}
	else {
		return flag;
	}
}
void subSString(SString& str4, SString str1, int begin, int len) {
	for (int i = 0; i < len; i++) {
		str4.ch[++str4.length] = str1.ch[begin++];
	}
}
int Index(SString& str1, SString& str4) {
	int i = 1, j = 1, k = 1;
	while (j <= str4.length && k <= str1.length) {
		if (str1.ch[i] == str4.ch[j]) {
			i++;
			j++;
		}
		else {
			j = 1;
			k++;
			i = k;
		}
	}
	if (j - 1 == str4.length) {
		return k;
	}
	else {
		return 0;
	}
}
void printStr(SString& str) {
	for (int i = 1; i <= str.length; i++)
		printf("%c", str.ch[i]);
	printf("\n");
}
int main() {
	SString str1, str2, str3, str4;
	InitSString(str1);
	InitSString(str2);
	InitSString(str4);
	char chars[] = "asdfasdfqwer";
	char chars1[] = "";
	StrtoC(str1, chars);
	strCopy(str1, str2);
	strAssign(str1, chars1);
	str3 = strcat(str1, str2);
	int flag = strCompare(str1, str2);
	subSString(str4, str1, 2, 3);
	int sub = Index(str1, str4);
	printf("%d\n", sub);
	printf("%d\n", flag);
	printStr(str4);
	printStr(str1);
	printStr(str2);
	printStr(str3);
	printf("%s\n", chars1);
}

