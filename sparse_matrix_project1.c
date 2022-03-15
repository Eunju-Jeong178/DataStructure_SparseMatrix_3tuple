// by Eunju Jeong, eunju0316@sookmyung.ac.kr

#include <stdio.h>
#define ROW 10  // 2차원 배열(arr2d[][])의 행을 10으로 정함
#define COL 10  // 2차원 배열(arr2d[][])의 열을 10으로 정함
#define MAX_TERMS 100  // 구조체 배열 a[100]까지 최대 생성 가능

struct sparse // 희소행렬(sparse matrix)을 사용할 때 쓰일 구조체
{
	// 3가지 멤버변수로 구성되어 있음
	int s_row; // 0이 아닌 요소의 행을 저장
	int s_col;  // 0이 아닌 요소의 열을 저장
	int s_value;  // 0이 아닌 요소의 값을 저장
};

int main(void)
{
	int row, col, value, size;
	int i,j;
	int k = 1;
	struct sparse a[MAX_TERMS]; // 크기가 100인 구조체 배열 생성

	int arr2d[ROW][COL] = { 0, }; // 10x10 2차원 배열의 요소를 모두 0으로 초기화
	
	printf("*****입력하신 10x10 행렬(2차원 배열)을 3tuple 구조로 변환해주는 프로그램입니다.*****\n\n");

	printf("'0'이 아닌 입력 데이터의 개수를 입력하세요 : ");
	scanf_s("%d", &size); // size 변수에 저장

	for (i = 0; i < size; i++)
	{
		printf("0이 아닌 데이터의 행, 열, 값을 차례로 입력하세요.: ");
		scanf_s("%d %d %d", &row, &col, &value);  // 사용자로부터 행, 열, 값(0이 아닌)을 입력받음

		a[k].s_row = row;  // 사용자로부터 입력받은 행을 구조체 배열에 저장
		a[k].s_col = col;  // 사용자로부터 입력받은 열을 구조체 배열에 저장
		a[k].s_value = value;  // 사용자로부터 입력받은 값을 구조체 배열에 저장
		k++; // 예를들어, a[1].s_row, a[1].s_col, a[1].s_value 를 다 채웠으니 a[2]로 넘어감.

		arr2d[row][col] = value;  // 사용자가 선택적으로 입력한 값을 10x10 2차원 배열의 해당 행과 열에 저장
	}
	a[0].s_row = ROW; 
	a[0].s_col = COL;
	a[0].s_value = size;
	// 구조체 a[0]에 10x10의 2차원 배열의 행과 열, 그리고 0이 아닌 요소의 개수가 저장

	printf("\n\n**입력하신 10x10 행렬은 다음과 같습니다.**\n\n");
	for (i = 0; i < ROW; i++) // 입력한 2차원 배열 출력
	{
		for (j = 0; j < COL; j++)
		{
			printf("%d ", arr2d[i][j]);
		}
		printf("\n"); // 한 행의 10개 요소를 다 출력하면 줄 바꿈
	}
	
	printf("\n\n***입력하신 sparse matrix를 3tuple 구조로 변환했습니다.***\n\n");
	printf("row col value\n");

	for (k = 0; k < size + 1; k++)  //a[0]의 요소 3개부터 a[size]의 요소 3개까지 출력
	{
		printf("%d   %d   %d\n", a[k].s_row, a[k].s_col, a[k].s_value); // 0이 아닌 요소의 행, 열, 값을 차례로 출력
	}
	return 0;  // 프로그램 종료
}
