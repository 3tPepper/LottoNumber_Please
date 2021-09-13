// maker: 3tPepper
// git: https://github.com/3tPepper/LottoNumber_Please

// �ֱ� 30ȸ �ζ� ��ȣ �󵵼��� ����� �ζ� ��ȣ ��±�
// update date: 2021-09-13

// ��Ȯõ���� ���� ���ھ���!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
											//931~961ȸ�� ��÷ �󵵼�
int numFrequency[45] = { 7, 8, 4, 5, 1,		//1~5
						 5, 4, 1, 8, 4,		//6~10
						 5, 5, 3, 4, 4,		//11~15
						 5, 3, 3, 1, 2,		//16~20
						 6, 6, 4, 7, 4,		//21~25
						 4, 2, 5, 5, 3,		//26~30
						 4, 2, 4, 4, 4,		//31~35
						 4, 7, 2, 5, 5,		//36~40
						 5, 5, 3, 2, 2};	//41~45 
int randomF[210] = {0, };		// �󵵼� ��ŭ 1~45 ��ȣ �Է� �迭

void lFrequency();
bool NotEqual(int i, int j, int r, int outNumber[][5]);

int main(void) {
	srand(time(NULL));
	int i, j, k, r = 0;
	int outNumber[6][5] = { 0, };

	lFrequency();

	for (i = 0; i < 6;i++)		//0~209���� ������ �����Ͽ� ���� ��, �� ����
		for (j = 0;j < 5;j++) {
			while (outNumber[i][j] == 0) {		//�迭�� ���� ���ö����� �ݺ�
				r = rand() % 209;
				if (NotEqual(i, j, r, outNumber)) {
					outNumber[i][j] = randomF[r];
				}
			}
		}

	/////���/////
	printf(" \n     ������ �ζ� ��õ ��ȣ��!\n");
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

void lFrequency() {				// random[210]�� �󵵼���ŭ ��ȣ ä��� �Լ�
	int i, j, k = 0;

	for (i = 0;i < 45;i++)			// ����
		for (j = 0;j < numFrequency[i];j++) {	// ���� �� �󵵼� ��ŭ �ݺ�
			randomF[k] = i + 1;
			k++;
		}
}

bool NotEqual(int i, int j, int r, int outNumber[][5]) {
	bool button = true;

	if (j!=0) {//�� ���ڸ� ��ȣ�� �ƴ� ���
		for (int k = 0; k < j; k++) {
			if (outNumber[i][k] == randomF[r])
				button = false;
		}
	}
	return button;
}