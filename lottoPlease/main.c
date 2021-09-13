// maker: 3tPepper
// git: https://github.com/3tPepper/LottoNumber_Please

// 최근 30회 로또 번호 빈도수에 기반한 로또 번호 출력기
// update date: 2021-09-13

// 일확천금을 위해 아자아자!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
											//931~961회차 당첨 빈도수
int numFrequency[45] = { 7, 8, 4, 5, 1,		//1~5
						 5, 4, 1, 8, 4,		//6~10
						 5, 5, 3, 4, 4,		//11~15
						 5, 3, 3, 1, 2,		//16~20
						 6, 6, 4, 7, 4,		//21~25
						 4, 2, 5, 5, 3,		//26~30
						 4, 2, 4, 4, 4,		//31~35
						 4, 7, 2, 5, 5,		//36~40
						 5, 5, 3, 2, 2};	//41~45 
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