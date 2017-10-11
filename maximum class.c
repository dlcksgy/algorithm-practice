#include <stdio.h>  //�̿��ε�
#include <string.h>
#include <stdlib.h>

typedef struct subject_st {
	int max_num_people;
	int num_people;
	int mileages[100];
}subject_t;

void input_sub(subject_t* input);

int mlg_for_sub(subject_t sub);  // ���� ������ �ʿ��� �ּ� ���ϸ����� ���ϴ� �Լ�


int calculate(int s_num, subject_t sub[], int mileage); //�������

int main()
{
	char first_input[100];
	int my_mileage;
	int subject_num;
	subject_t subject[100];
	int i;
	
	fgets(first_input, 99, stdin);  //���α׷� ������ �� ���ϸ����� ��ü ���� �� �Է�
	my_mileage = atoi(strtok(first_input, " \t"));
	subject_num = atoi(strtok(NULL, " \t"));

	for (i = 0; i < subject_num; i++) {
		input_sub(&subject[i]);
	}
	printf("%i\n", calculate(subject_num, subject, my_mileage));

}

void input_sub(subject_t* input)
{
	int i;
	char in[1000];
	fgets(in, 999, stdin);  //ù�ٿ� ���� ��û�� �����, �ִ�����ο� �Է�
	input->num_people = atoi(strtok(in, " \t"));
	input->max_num_people = atoi(strtok(NULL, " \t"));
	fgets(in, 999, stdin);   //�ι�°�ٿ� ��û�� ������� ������ ���ϸ��� �Է�
	(input->mileages)[0] = atoi(strtok(in, " \t"));
	for (i = 1; i < (input->max_num_people); i++) {
		(input->mileages)[i] = atoi(strtok(NULL, " \t"));
	}
}

int mlg_for_sub(subject_t sub)  // ���� ������ �ʿ��� �ּ� ���ϸ����� ���ϴ� �Լ�
{
	int i, j;
	int buffer;
	int mlgs[100];
	if (sub.max_num_people > sub.num_people) {
		return 1;
	}
	for (i = 0; i < sub.num_people; i++) {
		mlgs[i] = (sub.mileages)[i];  // mlgs�� ������� ������ ���ϸ��� ����Ʈ�� ����
	}

	for (i = 0; i < sub.num_people; i++) {  //������� ������ ���ϸ����� ����
		for (j = 0; j < (sub.num_people - i - 1); j++) {
			if (mlgs[j] > mlgs[j + 1]) {
				buffer = mlgs[j];
				mlgs[j] = mlgs[j + 1];
				mlgs[j + 1] = buffer;
			}
		}
	}
	return mlgs[sub.max_num_people];
}

int calculate(int s_num, subject_t sub[], int mileage)
{
	int i, j;
	int min[100];
	int ret;
	int buffer;
	int a;
	ret = 0;
	for (i = 0; i < s_num; i++) {
		min[i] = mlg_for_sub(sub[i]);
	}
	for (i = 0; i < s_num; i++) {
		for (j = 0; j < (s_num - i - 1); j++) {
			if (min[j] > min[j + 1]) {
				buffer = min[j];
				min[j] = min[j + 1];
				min[j + 1] = buffer;
			}
		}
	}
	a = 0;
	while ((mileage - min[a]) > 0) {
		mileage = mileage - min[a];
		a++;
		ret++;
	}
	return ret;
}
