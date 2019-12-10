#include <stdio.h>
#include <ctype.h>
#pragma warning(disable:4996)

void poj_sem(char* text) {
	FILE* fr;
	int pismeno;
	size_t n = 0;

	fr = fopen("sifra.txt", "r");
	if (fr == 0) {
		printf("Spravu sa nepodarilo nacitat\n");
	}
	while ((pismeno = fgetc(fr)) != EOF) {
		text[n] = (char)pismeno;
		n++;
	}
	text[n] = '\0';
	fclose(fr);
}
void tu_sa_tlac(char* text) {
	if (text[0] == '\0') {
		printf("Sprava nie je nacitana\n");
		return;
	}
	int loaded;
	for (loaded = 0; text[loaded] != '\0'; loaded++) {
		text[0] = text[loaded];
		printf("%c", text[0]);
	}
	printf("\n");
}
void morph(char* text, char* text2) {
	int i, n = 0;
	if (text[0] == '\0') {
		printf("Sprava nie je nacitana\n");
		return;
	}
	for (i = 0; i < strlen(text); i++) {
		if (text[i] == '\0') {
			break;
		}
		if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) {
			if (islower(text[i])) {
				text2[n] = toupper(text[i]);
			}
			else {
				text2[n] = text[i];
			}
			n++;
		}
		else
			continue;
	}
	text2[n] = '\0';
}
void u_shall_pass(char* text2) {
	if (text2[0] == '\0') {
		printf("Nie je k dispozcii upravena sprava\n");
		return;
	}
	else
		printf("%s\n", text2);
}
void pismena(char* text) {
	int k, noch;
	if (text[0] == '\0') {
		printf("Sprava nie je nacitana\n");
		return;
	}
	scanf("%i", &k);
	if (k >= 1 && k <= 100) {
		char ch[1000];
		size_t size = strlen(text);
		for (noch = 0; noch < strlen(text); noch++)
			if (text[noch] >= 33 && text[noch] <= 126)
				printf("work in progress ");
		printf('\n');
	}
	else
		return 0;
}
void darude(char* text2) {
	int pozicia, n = 0;
	char darude[26] = { 0 };
	char pismena, ulozisko[1000] = { '\0' };
	if (text2[0] == '\0') {
		printf("Nie je k dispozcii upravena sprava\n");
		return;
	}
	while (text2[n] != '\0') {
		if (text2[n] >= 'A' && text2[n] <= 'Z') {
			pozicia = text2[n] - 'A';
			darude[pozicia]++;
		}
		n++;
	}
	int i, minh, maxh = sizeof(text2);
	for (i = 1; i < n; i++) {
		if (darude[i] > maxh)
			maxh = darude[i];
	}

	for (n = 0; n < 26; n++) {
		size_t size = n;
		for (minh = 0; minh <= maxh; minh++) {
			if (((float)darude[n] / sizeof(text2)) * 100 <= 10 && ((float)darude[n] / sizeof(text2)) * 100 > 0) {
				printf("* ");
			}
			if (((float)darude[n] / sizeof(text2)) * 100 <= 20 && ((float)darude[n] / sizeof(text2)) * 100 > 10) {
				printf("* ");
			}
			if (((float)darude[n] / sizeof(text2)) * 100 <= 30 && ((float)darude[n] / sizeof(text2)) * 100 > 20) {
				printf("* ");
			}
			if (((float)darude[n] / sizeof(text2)) * 100 <= 40 && ((float)darude[n] / sizeof(text2)) * 100 > 30) {
				printf("* ");
			}
			if (((float)darude[n] / sizeof(text2)) * 100 <= 50 && ((float)darude[n] / sizeof(text2)) * 100 > 40) {
				printf("* ");
			}
			if (((float)darude[n] / sizeof(text2)) * 100 <= 60 && ((float)darude[n] / sizeof(text2)) * 100 > 50) {
				printf("* ");
			}
			if (((float)darude[n] / sizeof(text2)) * 100 <= 70 && ((float)darude[n] / sizeof(text2)) * 100 > 60) {
				printf("* ");
			}
			if (((float)darude[n] / sizeof(text2)) * 100 <= 80 && ((float)darude[n] / sizeof(text2)) * 100 > 70) {
				printf("* ");
			}
			if ((darude[n] / sizeof(text2)) * 100 <= 90 && (darude[n] / sizeof(text2)) * 100 > 80) {
				printf("* ");
			}
			if ((darude[n] / sizeof(text2)) * 100 <= 100 && (darude[n] / sizeof(text2)) * 100 > 90) {
				printf("* ");
			}
			if (darude[n] == 0) {
				printf("");
			}
			n++;
		}
		putchar('\n');
	}
	printf("\n");
	for (pismena = 65; pismena <= 90; pismena++) {
		printf("%c ", pismena);
	}
	putchar('\n');
	for (n = 0; n < 26; n++)
		printf("%d ", darude[n]);
	putchar('\0');
}
void sifra(char* text2) {
	char final;
	int posun, n;
	if (text2[0] == '\0') {
		printf("Nie je k dispozcii upravena sprava\n");
		return;
	}
	printf("daj n: ");
	scanf("%d", &n);
	if (n >= 1 && n <= 25) {
		for (posun = 0; text2[posun] != '\0'; ++posun) {
			final = text2[posun];
			if (final >= 'a' && final <= 'z') {
				final = final + n;
				if (final > 'z') {
					final = final - 'z' + 'a' - 1;
				}
				text2[posun] = final;
			}
			else if (final >= 'A' && final <= 'Z') {
				final = final + n;

				if (final > 'Z') {
					final = final - 'Z' + 'A' - 1;
				}
				text2[posun] = final;
			}
		}
		printf("%s\n", text2);
	}
	else
		return 0;
}
int main() {
	char nieco_na_tlacenie, text[1000] = { '\0' }, text2[1000] = { '\0' };

	printf("Napis pismeno: n, v, u, s, d, h, c, k.\n");
	while (scanf_s("%c", &nieco_na_tlacenie) == 1) {
		switch (nieco_na_tlacenie) {
		case 'n':
			poj_sem(text);
			break;
		case 'v':
			tu_sa_tlac(text);
			break;
		case 'u':
			morph(text, text2);
			break;
		case 's':
			u_shall_pass(text2);
			break;
		case 'd':
			pismena(text);
			break;
		case 'h':
			darude(text2);
			break;
		case 'c':
			sifra(text2);
			break;
		case 'k':
			return 0;
			break;
		}
	}
}