#pragma once
#include "stdafx.h"

#include "lib_bit.h"

/**
@return bool :  ���� �۵��� true, �ƴ� ��� false

@param src_num : 2�� ���̳ʸ��� ��� �� ��

@brief 10���� ���� 2���� ��Ʈ ������ ����Ѵ�.

@todo ���� ó�� �̿�
*/
bool DisplayNumToBit(unsigned int src_num) {

	//�ش� �ڷ����� ��Ʈ ���� ���ϱ�
	unsigned int cnt_bit = sizeof(src_num) * 8;

	//��Ʈ MSB������ ����
	unsigned int bit_offset = 1 << (cnt_bit - 1);

	//��� ��Ʈ ����ũ ��Ʈ ����
	unsigned int total_cnt_bit = cnt_bit;

	//MSB ���� ���������� �ݺ�
	for (int i = 1; i <= total_cnt_bit; i++) {

		//��Ʈ ����ũ ����
		if (src_num & bit_offset) {

			putchar('1');
		}
		else {

			putchar('0');
		}

		//8��Ʈ ������ ���� ���� ���!
		if (0 == (i % 8)) {

			putchar(' ');
		}

		bit_offset = bit_offset >> 1;
	}

	putchar('\n');

	return true;
}







/**
@return bool :  ���� �۵��� true, �ƴ� ��� false

@param data : 2�� ��Ʈ ������ ���� ���
@param target_bit_offset : data�� 2�� ��Ʈ ������
@param set_bit_flag : true�� flag on, false�� flag off

@brief ������ ���� 2�� ��Ʈ �÷����� �������� ���� �����Ѵ�.
*/
bool SetBitFlag(unsigned int *data, unsigned int target_bit_offset, bool set_bit_flag) {

	//����ó�� : ���� ǥ�� ������ ��Ʈ ������ ���� üũ üũ
	int available_bit_cnt = sizeof(*data) * 8;

	//insigend int���� ��Ʈ�� 0�� �ڸ������� 31�� �ڸ������� ǥ�� ����
	if (available_bit_cnt <= target_bit_offset) {

		return false;
	}

	int offset_bit = 1 << (target_bit_offset);

	//���� ��Ʈ �������� ��Ʈ �÷��װ� 1�� ���
	if (*data & offset_bit) {

		//�ش� ��Ʈ �������� ���� 0���� �����ϴ� ���
		if (false == set_bit_flag) {

			*data = *data & (~offset_bit);
		}
	}
	//���� ��Ʈ �������� ��Ʈ �÷��װ� 0�� ���
	else {

		//�ش� ��Ʈ ������ ���� 1���� �����ϴ� ���
		if (true == set_bit_flag) {

			*data = *data | (offset_bit);
		}
	}

	return true;
}

