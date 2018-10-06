#include<iostream>
using namespace std;

int k, num, dir;
int topnee[5][8];

int change(int num, int d){
	int temp=0;

	if (d == 1){	//시계방향
		temp = topnee[num][7];
		for (int a = 7; a >= 1; a--){
			topnee[num][a] = topnee[num][a - 1];
		}
		topnee[num][0] = temp;
	}
	else if (d == -1){	//반시계방향
		temp = topnee[num][0];
		for (int a = 0; a <= 6; a++){
			topnee[num][a] = topnee[num][a + 1];
		}
		topnee[num][7] = temp;
	}
	else{
		cout << "Error : 회전방향 오류!" << endl;
		return -1;
	}
	return 0;
}

int check_left(int num, int d){
	if (num < 1 || num>4) return 0;	//회전할 톱니가 없다면 return

	if (topnee[num][2] != topnee[num + 1][6]){	//다른 극일 경우
		d = (d == 1) ? -1 : 1;	//회전방향 변경
		check_left(num - 1, d);	//다음 왼쪽 톱니 확인
		change(num, d);	//현재 톱니 회전
	}
}

int check_right(int num, int d){
	if (num < 1 || num>4) return 0;	//회전할 톱니가 없다면 return

	if (topnee[num][6] != topnee[num - 1][2]){	//다른 극일 경우
		d = (d == 1) ? -1 : 1;	//회전방향 변경
		check_right(num + 1, d);	//다음 오른쪽 톱니 확인
		change(num, d);	//현재 톱니 회전
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int result;	//결과값
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> k;	//회전횟수 입력
		result = 0;

		for (int i = 1; i < 5; i++){
			for (int j = 0; j < 8; j++){
				cin >> topnee[i][j];	//톱니 정보 입력
			}
		}

		for (int z = 0; z < k; z++){
			cin >> num >> dir;	//회전할 톱니 번호와 방향 입력

			check_left(num - 1, dir);	//왼쪽 톱니 확인
			check_right(num + 1, dir);	//오른쪽 톱니 확인

			change(num, dir);	//현재 톱니 회전
		}
		
		result = topnee[1][0] + (topnee[2][0] * 2) + (topnee[3][0] * 4) + (topnee[4][0] * 8);

		cout << "#" << test_case << " " << result << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}