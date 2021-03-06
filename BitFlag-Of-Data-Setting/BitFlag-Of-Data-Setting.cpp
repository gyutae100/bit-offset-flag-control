/**
@file BitFlag-Of-Data-Setting.cpp

@mainpage 쉬프트 연산자를 이용한 비트단위 ON/OFF

@date 2018/04/23

@author 김규태(gyutae100@gmail.com)

@details 특정 정수의 비트 값을 쉬프트 연산자를 이용해서 선택한 비트 오프셋의 플래그값을 변경 후 2진 바이너리 값으로 출력한다.

@version 0.0.1
*/

#include "stdafx.h"

#include <stdio.h>
#include <string.h>

#include "lib_bit.h"

/**
@return int : 프로그램 정상 종료 여부 파악한다.

@brief 특정 정수의 비트 값을 쉬프트 연산자를 이용해서 선택한 비트 오프셋의 플래그값을 변경 후 2진 바이너리 값으로 출력한다.

@todo scanf_s로 bool type을 받을 수 있는가 조사
*/
void main(void)
{

	//비트 연산 대상
	unsigned int data = 0;

	unsigned int offset_bit = 0;
	unsigned int bit_value = 0;
	bool bit_flag = false;

	//해당 자료형의 비트 갯수 구하기
	unsigned int num_bit = sizeof(data) * 8;

	while (1)
	{

		//변경 할 비트 오프셋 및 오프셋의 변경 값 입력
		puts("\n비트 위치(0~ ) : ");
		scanf_s("%d", &offset_bit);

		puts("OFF/ON [0,1] : ");
		scanf_s("%d", &bit_value);


								
		//입력 정수 값을 불 값으로 변경
		if (bit_value == 0) {

			bit_flag = false;
		}
		else if (bit_value == 1) {

			bit_flag = true;
		}


		//해당 값의 비트 오프셋 셋팅 함수 호출
		if (SetBitFlag(&data, offset_bit, bit_flag)) {

			//변경 된 값을 비트 단위 출력
			DisplayNumToBit(data);
			puts("작업 성공");
		}
		else {

			puts("작업 실패, 다시 진행해주세요");
		}



	}


}