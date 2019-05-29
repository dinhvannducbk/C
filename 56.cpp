#include<iostream>

using namespace std;

#define max 210

int num[max] = {0};
int sum[max] = {0};

void sapxep(int arr[]){
	for(int i=max-1;i>0;i--){
		if(arr[i] >= 10){
			arr[i-1] += arr[i]/10;
			arr[i] = arr[i]%10;
		} 
	}
}

// Tinh a^b
void tinh(int a, int b){
	for(int i=max-2;i>=0;i--){
		num[i] = 0;
	}
	num[max-1] = 1;
	for(int k=1;k<=b;k++){
		for(int i=max-1;i>0;i--){
			num[i] *= a;
		}
		sapxep(num);
	}
}

int main(){
	int result = 0;
	for(int a=99;a>0;a--){
		for(int b=99;b>0;b--){
			tinh(a,b);
			for(int i=0;i<max;i++){
				sum[i] += num[i];
			}
			sapxep(sum);
		}
	}
	for(int i=0;i<max;i++){
//		cout << sum[i];
		result += sum[i];
	}
	cout << result;
	return 0;
}
