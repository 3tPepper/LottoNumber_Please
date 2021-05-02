#include <stdio.h>
#include <stdlib.h>
#include <time.h>
											//931~961ȸ�� ��÷ �󵵼�
int numFrequency[45] = { 7, 5, 4, 7, 2,		//1~5
						 2, 2, 4, 7, 8,		//6~10
						 5, 5, 5, 5, 7,		//11~15
						 3, 2, 6, 2, 6,		//16~20
						 2, 5, 3, 5, 3,		//21~25
						 5, 4, 3, 5, 8,		//26~30
						 5, 5, 6, 2, 8,		//31~35
						 7, 5, 5, 6, 8,		//36~40
						 6, 5, 5, 3, 4};	//41~45 
int randomF[210] = {0, };		// �󵵼� ��ŭ 1~45 ��ȣ �Է� �迭

void lFrequency();

int main(void) {
	srand(time(NULL));
	int i, j, r = 0;
	int outNumber[6][5] = { 0, };

	lFrequency();

	for (i = 0; i < 6;i++)		//0~209���� ������ �����Ͽ� ���� ��, �� ����
		for (j = 0;j < 5;j++) {
			r = rand() % 209;
			outNumber[i][j] = randomF[r];
		}

	/////���/////
	printf(" ������ �ζ� ��õ ��ȣ��!\n\n");

	for (i = 0; i < 6;i++) {
		for (j = 0;j < 5;j++) {
			printf("%d  ", outNumber[i][j]);
		}
		printf("\n");
	}
}

void lFrequency() {				// random[210]�� �󵵼���ŭ ��ȣ ä��� �Լ�
	int i, j, k = 0;

	for (i = 0;i < 45;i++)			// ����
		for (j = 0;j < numFrequency[i];) {	// ���� �� �󵵼� ��ŭ �ݺ�
			randomF[k] = i + 1;
		}
}