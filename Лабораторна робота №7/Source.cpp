#include <iostream>
#include <ctime>
using namespace std;


int main() {
	const int size = 5;//����� ������
	int arr[size] /*= { 32,16,8,4,2 }*/; //��� �������� �� ����.��������,������������� ����� {...}
	float difference;//������ ����������� �������
	float arithmetic_mean(int[], const int);//������� ��� ���������� �������� ���� ������
	void fill_arr(int[], const int); //���������� ������ ��������
	void output_arr(int[], const int);//���� ������
	bool check_progression(int[], const int, float*);//�������� �� ��������
	void final_array(int[], const int);//������� �����


	fill_arr(arr, size);//������ �������
	output_arr(arr, size);//������ �������
	float result = arithmetic_mean(arr, size);//��������� ���.��������

	if (check_progression(arr, size, &difference)) {//���� �������� ''���''
		cout << "difference_of_progression = " << difference << endl;
	}
	else {
		cout << "arithmetic mean= " << result << endl;
		final_array(arr, size);//������ �������
	}


	system("pause");


}

void fill_arr(int arr[], const int size) {
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 10 + 1;
	}
	
}

void output_arr(int arr[], const int size) {
	cout << "Array:" << endl;
	for (int i = 0; i < size; i++) {
		cout<< arr[i] << endl;
	}

}

bool check_progression(int arr[], const int size, float* difference) {
	bool is_progression = true;//� ��������
	*difference = (float)arr[1] / arr[0];//���������� ������ ����.�������
	for (int i = 1; i < size; i++) {
		if ((float)arr[i] / arr[i - 1] != *difference) {
			is_progression = false; //���� �������
		}
	}
	return is_progression;//���������� �������� ��������
}

void final_array(int arr[], const int size) {
	float arithmetic_mean(int[], const int);
	float result = arithmetic_mean(arr, size);
	for (int i = 0; i < size; i++) {
		if (arr[i] % 2 != 0) {
			arr[i] = result;//����� �������� ��������
		}
		cout << arr[i] << "\t";
	}

}

float arithmetic_mean(int arr[], const int size) {
	int sum;
	int res;
	sum = arr[0] + arr[size-1];
	res = sum / 2;
	return res;//��� �������� ���� ������ (���� ��������!!!)
}