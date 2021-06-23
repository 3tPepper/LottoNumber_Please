// maker: shortcutsB
// git: https://github.com/shortcutsB/LottoNumber_Please

// �ֱ� 30ȸ �ζ� ��ȣ �󵵼��� ����� �ζ� ��ȣ ��±�
// update date: 2021-06-23

// ��Ȯõ���� ���� ���ھ���!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
											//931~961ȸ�� ��÷ �󵵼�
int numFrequency[45] = { 8, 6, 3, 6, 2,		//1~5
						 4, 1, 4, 8, 6,		//6~10
						 4, 6, 5, 5, 5,		//11~15
						 3, 1, 5, 3, 5,		//16~20
						 4, 4, 2, 6, 4,		//21~25
						 4, 3, 5, 4, 8,		//26~30
						 5, 3, 6, 6, 8,		//31~35
						 7, 5, 5, 7, 9,		//36~40
						 6, 6, 5, 2, 3};	//41~45 
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