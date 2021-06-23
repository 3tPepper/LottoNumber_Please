// maker: shortcutsB
// git: https://github.com/shortcutsB/LottoNumber_Please

// 최근 30회 로또 번호 빈도수에 기반한 로또 번호 출력기
// update date: 2021-06-23

// 일확천금을 위해 아자아자!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
											//931~961회차 당첨 빈도수
int numFrequency[45] = { 8, 6, 3, 6, 2,		//1~5
						 4, 1, 4, 8, 6,		//6~10
						 4, 6, 5, 5, 5,		//11~15
						 3, 1, 5, 3, 5,		//16~20
						 4, 4, 2, 6, 4,		//21~25
						 4, 3, 5, 4, 8,		//26~30
						 5, 3, 6, 6, 8,		//31~35
						 7, 5, 5, 7, 9,		//36~40
						 6, 6, 5, 2, 3};	//41~45 
int randomF[210] = {0, };		// 빈도수 만큼 1~45 번호 입력 배열

void lFrequency();
bool NotEqual(int i, int j, int r, int outNumber[][5]);

int main(void) {
	srand(time(NULL));
	int i, j, k, r = 0;
	int outNumber[6][5] = { 0, };

	lFrequency();

	for (i = 0; i < 6;i++)		//0~209까지 난수를 생성하여 대입 후, 값 저장
		for (j = 0;j < 5;j++) {
			while (outNumber[i][j] == 0) {		//배열에 값이 들어올때까지 반복
				r = rand() % 209;
				if (NotEqual(i, j, r, outNumber)) {
					outNumber[i][j] = randomF[r];
				}
			}
		}

	/////출력/////
	printf(" \n     금주의 로또 추천 번호는!\n");
	printf("------------------------------------\n");

	for (i = 0; i < 6;i++) {
		for (j = 0;j < 5;j++) {
			printf("%d\t", outNumber[i][j]);
		}
		printf("\n\n");
	}

	getch();
	return 0;
}

void lFrequency() {				// random[210]에 빈도수만큼 번호 채우는 함수
	int i, j, k = 0;

	for (i = 0;i < 45;i++)			// 숫자
		for (j = 0;j < numFrequency[i];j++) {	// 숫자 별 빈도수 만큼 반복
			randomF[k] = i + 1;
			k++;
		}
}

bool NotEqual(int i, int j, int r, int outNumber[][5]) {
	bool button = true;

	if (j!=0) {//맨 앞자리 번호가 아닌 경우
		for (int k = 0; k < j; k++) {
			if (outNumber[i][k] == randomF[r])
				button = false;
		}
	}
	return button;
}