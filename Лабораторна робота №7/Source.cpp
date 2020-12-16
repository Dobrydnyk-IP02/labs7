#include <iostream>
#include <ctime>
using namespace std;


int main() {
	const int size = 5;//розмір масиву
	int arr[size] /*= { 32,16,8,4,2 }*/; //для перевірки на геом.прогресію,розкоментуйте числа {...}
	float difference;//різниця геометричної прогресії
	float arithmetic_mean(int[], const int);//функція для середнього значення двох крайніх
	void fill_arr(int[], const int); //заповнення масиву рандомно
	void output_arr(int[], const int);//вивід масиву
	bool check_progression(int[], const int, float*);//перевірка на прогресію
	void final_array(int[], const int);//кінцевий масив


	fill_arr(arr, size);//виклик функції
	output_arr(arr, size);//виклик функції
	float result = arithmetic_mean(arr, size);//результат сер.значення

	if (check_progression(arr, size, &difference)) {//якщо прогресія ''тру''
		cout << "difference_of_progression = " << difference << endl;
	}
	else {
		cout << "arithmetic mean= " << result << endl;
		final_array(arr, size);//виклик функції
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
	bool is_progression = true;//є прогресія
	*difference = (float)arr[1] / arr[0];//обчислення різниці геом.прогресії
	for (int i = 1; i < size; i++) {
		if ((float)arr[i] / arr[i - 1] != *difference) {
			is_progression = false; //немає прогресії
		}
	}
	return is_progression;//повернення булевого значення
}

void final_array(int arr[], const int size) {
	float arithmetic_mean(int[], const int);
	float result = arithmetic_mean(arr, size);
	for (int i = 0; i < size; i++) {
		if (arr[i] % 2 != 0) {
			arr[i] = result;//заміна непарних елементів
		}
		cout << arr[i] << "\t";
	}

}

float arithmetic_mean(int arr[], const int size) {
	int sum;
	int res;
	sum = arr[0] + arr[size-1];
	res = sum / 2;
	return res;//сер значення двох крайніх (ціле значення!!!)
}