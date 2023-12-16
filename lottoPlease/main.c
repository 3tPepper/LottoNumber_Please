// maker: 3tPepper
// git: https://github.com/3tPepper/LottoNumber_Please

// 최근 30회 로또 번호 빈도수에 기반한 로또 번호 출력기
// update date: 2023-12-16

// 일확천금을 위해 아자아자!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
											//1068~1098회차 당첨 빈도수
int numFrequency[45] = { 7, 1, 4, 6, 1,		//1~5
						 7, 6, 4, 2, 5,		//6~10
						 4, 5, 3, 6, 5,		//11~15
						 7, 5, 8, 4, 3,		//16~20
						 6, 6, 6, 5, 1,		//21~25
						 4, 4, 5, 3, 7,		//26~30
						 5, 3, 5, 6, 6,		//31~35
						 6, 6, 6, 2, 6,		//36~40
						 4, 3, 7, 8, 4};	//41~45 
int randomF[210] = {0, };		// 빈도수 만큼 1~45 번호 입력 배열

void lFrequency();
bool NotEqual(int i, int j, int r, int outNumber[][5]);

int main(void) {
	srand(time(NULL));
	int i, j, k, r = 0;
	int outNumber[5][6] = { 0, };

	lFrequency();

	for (i = 0; i < 5;i++)		//0~209까지 난수를 생성하여 대입 후, 값 저장
		for (j = 0;j < 6;j++) {
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

	for (i = 0; i < 5;i++) {
		for (j = 0;j < 6;j++) {
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

bool NotEqual(int i, int j, int r, int outNumber[][6]) {
	bool button = true;

	if (j!=0) {//맨 앞자리 번호가 아닌 경우
		for (int k = 0; k < j; k++) {
			if (outNumber[i][k] == randomF[r])
				button = false;
		}
	}
	return button;
}