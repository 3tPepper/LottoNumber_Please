// maker: 3tPepper
// git: https://github.com/3tPepper/LottoNumber_Please

// �ֱ� 30ȸ �ζ� ��ȣ �󵵼��� ����� �ζ� ��ȣ ��±�
// update date: 2023-12-16

// ��Ȯõ���� ���� ���ھ���!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
											//1068~1098ȸ�� ��÷ �󵵼�
int numFrequency[45] = { 7, 1, 4, 6, 1,		//1~5
						 7, 6, 4, 2, 5,		//6~10
						 4, 5, 3, 6, 5,		//11~15
						 7, 5, 8, 4, 3,		//16~20
						 6, 6, 6, 5, 1,		//21~25
						 4, 4, 5, 3, 7,		//26~30
						 5, 3, 5, 6, 6,		//31~35
						 6, 6, 6, 2, 6,		//36~40
						 4, 3, 7, 8, 4};	//41~45 
int randomF[210] = {0, };		// �󵵼� ��ŭ 1~45 ��ȣ �Է� �迭

void lFrequency();
bool NotEqual(int i, int j, int r, int outNumber[][5]);

int main(void) {
	srand(time(NULL));
	int i, j, k, r = 0;
	int outNumber[5][6] = { 0, };

	lFrequency();

	for (i = 0; i < 5;i++)		//0~209���� ������ �����Ͽ� ���� ��, �� ����
		for (j = 0;j < 6;j++) {
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

	for (i = 0; i < 5;i++) {
		for (j = 0;j < 6;j++) {
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

bool NotEqual(int i, int j, int r, int outNumber[][6]) {
	bool button = true;

	if (j!=0) {//�� ���ڸ� ��ȣ�� �ƴ� ���
		for (int k = 0; k < j; k++) {
			if (outNumber[i][k] == randomF[r])
				button = false;
		}
	}
	return button;
}