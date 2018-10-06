#include<iostream>
using namespace std;

int k, num, dir;
int topnee[5][8];

int change(int num, int d){
	int temp=0;

	if (d == 1){	//�ð����
		temp = topnee[num][7];
		for (int a = 7; a >= 1; a--){
			topnee[num][a] = topnee[num][a - 1];
		}
		topnee[num][0] = temp;
	}
	else if (d == -1){	//�ݽð����
		temp = topnee[num][0];
		for (int a = 0; a <= 6; a++){
			topnee[num][a] = topnee[num][a + 1];
		}
		topnee[num][7] = temp;
	}
	else{
		cout << "Error : ȸ������ ����!" << endl;
		return -1;
	}
	return 0;
}

int check_left(int num, int d){
	if (num < 1 || num>4) return 0;	//ȸ���� ��ϰ� ���ٸ� return

	if (topnee[num][2] != topnee[num + 1][6]){	//�ٸ� ���� ���
		d = (d == 1) ? -1 : 1;	//ȸ������ ����
		check_left(num - 1, d);	//���� ���� ��� Ȯ��
		change(num, d);	//���� ��� ȸ��
	}
}

int check_right(int num, int d){
	if (num < 1 || num>4) return 0;	//ȸ���� ��ϰ� ���ٸ� return

	if (topnee[num][6] != topnee[num - 1][2]){	//�ٸ� ���� ���
		d = (d == 1) ? -1 : 1;	//ȸ������ ����
		check_right(num + 1, d);	//���� ������ ��� Ȯ��
		change(num, d);	//���� ��� ȸ��
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int result;	//�����
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> k;	//ȸ��Ƚ�� �Է�
		result = 0;

		for (int i = 1; i < 5; i++){
			for (int j = 0; j < 8; j++){
				cin >> topnee[i][j];	//��� ���� �Է�
			}
		}

		for (int z = 0; z < k; z++){
			cin >> num >> dir;	//ȸ���� ��� ��ȣ�� ���� �Է�

			check_left(num - 1, dir);	//���� ��� Ȯ��
			check_right(num + 1, dir);	//������ ��� Ȯ��

			change(num, dir);	//���� ��� ȸ��
		}
		
		result = topnee[1][0] + (topnee[2][0] * 2) + (topnee[3][0] * 4) + (topnee[4][0] * 8);

		cout << "#" << test_case << " " << result << endl;
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}