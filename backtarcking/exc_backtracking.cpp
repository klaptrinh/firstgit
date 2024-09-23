#include<iostream>
#include<math.h>
#define MAX 105
ádasdasdasdasd
void swap(int& a, int& b) {
	/*a = a + b;
	b = a - b;
	a = a - b;*/
	int temp = a;
	a = b;
	b = temp;
}

void merga(int a[], int start, int mid, int end, int n) {
	int n1 = (mid - start) +1;
	int n2 = end - mid;
	int L[MAX], R[MAX];
	for (int i = 0; i < n1; i++) {
		L[i] = a[start + i];
	}
	for (int i = 0; i < n2; i++) {
		R[i] = a[(mid+1) + i];
	}
	int i = 0, j = 0;
	int k = start;
	for (; i < n1 && j < n2; k++) {
		if (abs(n - L[i]) < abs(n - R[j])) {
			a[k] = L[i++];
		}
		else {
			a[k] = R[j++];
		}
	}
	for (; i < n1; i++) {
		a[k++] = L[i];
	}
	for (; j < n2; j++) {
		a[k++] = R[j];
	}
}
void mergasort(int a[], int start, int end, int n) {
	if (start >= end) {
		return;
	}
	int mid = (end + start) / 2;
	mergasort(a, start, mid,n);
	mergasort(a, mid+1, end,n);
	merga(a, start, mid, end,n);
}



//algorithm 6.3
/*{
void bublesort(int a[], int n) {
	for (bool checkswap = true; checkswap == true;) {
		checkswap = false;
		for (int i = 0; i < n - 1; i++) {
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				checkswap = true;
			}
		}
	}
}
void detached(int a[], int &n) {//tách các số >10 thành số có 1 chữ số
	int count = 0, b[MAX];
	for (int i = 0; i < n; i++) {	
		if (a[i] > 10) {
			//biến count tăng dựa vào số phần tử để làm index cho array con
			while (a[i] > 10) {
				b[count++] = a[i] % 10;
				a[i] = a[i] / 10;
			}
			b[count++] = a[i] % 10;
		}
		else {
			b[count++] = a[i];
		}
	}
	//copy lại các số 1 chữ số đó vào mảng ban đầu
	n = count;
	for (int i = 0; i < n; i++) {
		a[i] = b[--count];
	}
}
void omitied(int a[], int& n) {
	int n2 = 0;
	for (int j = 0; j < n; j++) {
		if (a[n2] != a[j]) {
			a[++n2] = a[j];
		}
	}
	n = n2 + 1;
}
}*/
//selection sort
/*{void selection_sort(int a[], int n) {
	int minindex;
	for (int i = 0; i < n-1; i++) {
		minindex = i;
		for (int j = i+1; j < n; j++) {
			if (a[j] < a[minindex]) {
				minindex = j;
			}
		}
		swap(a[i], a[minindex]);
	}
}}*/
//insertion sort
/*{void insertion_sort(int a[], int n) {
	int temp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = n - 1; j > i; j--) {
			if (a[i] > a[j]) {
				temp = a[j];
				for (int v = j; v >= i; v--) {
					a[v] = a[v - 1];
				}
				a[i] = temp;
			}
		}
	}
}}*/
//selection sort 2.0
/*{void selection_sort20(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				swap(a[i], a[j]);
			}
		}
	}
}}*/
//buble sort
/*{void buble_sort(int a[], int n) {
	for (bool check_swap = true; check_swap == true;) {
		check_swap = false;
		for (int i = 0; i < n - 1; i++) {
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				check_swap = true;
			}
		}
	}
}}*/
// merga sort
/*{void merga(int a[], int start, int mid, int end) {
	int n1 = mid - start + 1;
	int n2 = end - mid;

	int L[MAX], R[MAX];
	for (int i = 0; i < n1; i++) {
		L[i] = a[start + i];
	}
	for (int i = 0; i < n2; i++) {
		R[i] = a[(mid+1) + i];
	}


	int j = 0, i = 0, k = start;
	for (; i < n1 && j < n2; k++) {
		if (L[i] < R[j]) {
			a[k] = L[i];
			i++;
		}
		else {
			a[k] = R[j];
			j++;
		}
	}

	while (i < n1) {
		a[k++] = L[i++];
	}

	while (j < n2) {
		a[k++] = R[j++];
	}
}
void merga_sort(int a[], int start, int end) {
	if (start >= end) return;
	int mid = (start + end) / 2;
	merga_sort(a, start, mid);
	merga_sort(a, mid+1, end);
	merga(a, start, mid, end);
}}*/
//quick sort
/*{int pratition(int a[], int start, int end) {
int i_big = end + 1;
for (int i = end; i > start; i--) {
	if (a[i] > a[start]) {
		swap(a[i], a[--i_big]);
	}
}
swap(a[start], a[i_big - 1]);
return i_big - 1;
}
void quick_sort(int a[], int start, int end) {// a[start], a[end]
	if (start >= end) {
		return;
	}
	int pivot = pratition(a, start, end);
	quick_sort(a, start, pivot - 1);
	quick_sort(a, pivot + 1, end);
}
}*/
/*{int a[MAX],n;
int check_pair;
int p;
int idex[MAX];
void input(int a, int x[]) {
	for (int i = 1; i <= a; i++) {
		std::cin >> x[i];
	}
}
void pair_equal() {
	for (int i = 1; i <= n; i++) {
		for (int j = n; j > i; j--) {
			check_pair = a[j] - a[i];
			if (check_pair >= p && j - i > idex[0]) {
				idex[0] = j - i;
				idex[1] = i;
				idex[2] = j;
				idex[3] = a[i];
				idex[4] = a[j];
			}
		}
	}
}
}*/
/*{
int a[MAX], b[MAX];
bool check_n[MAX], check_m[MAX];
int n, m;
int count = 0;
 void input(int a, int x[]) {
	for (int i = 0; i < a; i++) {
		std::cin >> x[i];
	}
}
void swap(int& a, int& b) {
	int temp = b;
	b = a;
	a = temp;
}
void sort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] < a[j]) {
			swap(a[i], a[j]);
			}
		}
	}
}
void dance() {
	for (int i = 0; i < n && check_n[i] != true; i++) {
		for (int j = 0; j < m && check_m[j] != true; j++) {
			if (a[i] > b[j]) {
				check_n[i] = true;
				check_m[j] = true;
				count++;
			}
		}
	}
}
}*/
/*{
	void swap(int& a, int& b) {
		int temp = b;
		b = a;
		a = temp;
	}
	void sum(int& a) {
		int x = 0;
		for (int i = a; i >= 1; i--) {
			x += i;
		}
		a = x;
	}
	void sort(int a[], int n) {
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (a[i] > a[j]) {
					swap(a[i], a[j]);
				}
			}
		}
	}
	void display(int a[], int n) {
		int y = 0;
		int x = 0;
		for (int i = 0; i < n - 1; i++) {
			if (a[i] == a[i + 1]) {
				y++;

			}
			else {
				sum(y);
				std::cout << y << " ";
				x += y;

				y = 0;
			}
		}
		std::cout << "\n" << x;
	}
}*/
/*{
int a[MAX], b[MAX];
int n, m; 
void input(int n, int a[]) {
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	 }
}
void display(int n, int a[]) {
	for (int i = 0; i < n; i++) {
		std::cout << a[i] << " ";
	}
}
void swap(int &a, int &b) {
	int temp = b;
	b = a;
	a = temp;
}
void sort(int a[], int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				swap(a[i], a[j]);
			}
		}
		
	}
}
}*/
/*{int arr_square[MAX];
int arr_n[MAX];
int n;
int start = 1, end = n;
void input(int n) {
	for (int i = 1; i <= n; i++) {
		std::cin >> arr_n[i];
	}
}
void create_square_number() {
	int i = 1, j = 0,v;
	while ( j < MAX) {
		v = sqrt(i);
		if (i == v * v) {
			arr_square[j] = i;
			j++;
		}
		i++;
	}
}
int search_square_number(int start, int end, int a) {
	int mid = (end + start) / 2;
	//std::cout << mid << start << end << "\n";
	if (end == start) {
		return -1;
	}
	if (arr_n[mid] == a) {
		return a;
	}
	else {
		if (a > arr_n[mid]) {
			search_square_number(mid+1,end,a);
		}
		else {
			search_square_number(start,mid,a);
		}
	}
}}*/
/*search fibonacy
{int fib[MAX];
int arr_fibon[MAX];
int n;
int start = 0, end = MAX - 1;
void creata_list_fibon() {
	int a = 0, b = 1;
	fib[0] = a;
	fib[1] = b;
	for (int i = 2; i < MAX; i++) {
		int c = a + b;
		fib[i] = c;
		a = b;
		b = c;
	}
}
int check_fibon_by_binary(int start, int end, int x) {
	int mid = (end + start) / 2;
	//std::cout << start << "-" << end;
	if (end - start == 1) {
		return -1;
	}
	if (fib[mid] == x) {
		return x;
	}
	else {
		if (x > fib[mid]) {
			return check_fibon_by_binary(mid,end,x);
		}
		else {
			return check_fibon_by_binary(start,mid,x);
		}
	}	
}}*/
/*int arr[MAX];
int n;
bool check_nguyen_to(int a) {
	for (int i = 2; i < a; i++) {
		if (a % i == 0) {
			return false;
		}
	}
	return true;
}
void so_nguyen_to() {
	for (int i = 0; i < n; i++) {
		if (check_nguyen_to(arr[i])) {
			std::cout << arr[i] << " ";
		}
	}
}*/
/*int binary_search(int start, int end, const int &x) {
	int mid = (end + start) / 2;
	if (arr[mid] == x) {
		return mid;
	}
	else{
		if (x > arr[mid]) {
			return binary_search(mid, end, x);
		}
		else {
			return binary_search(start, mid, x);
		}
		return -1;
	}
}*/
/*void baitoanmachdien(){
	int n, m, y = 0;
	char x[MAX];
	bool check_C[MAX], checkn = true, checkm = true;
	void print() {
		for (int i = 1; i <= n + m; i++) {
			std::cout << x[i] << " ";
		}
		std::cout << std::endl;
	}
	// chia mạch điện
	void elec(int i) {
		for (int v : {67, 79}) {
			x[i] = v;
			if (v == 67) {
				check_C[i] = true;
			}
			else {
				check_C[i] = false;
			}
			if (true) {
				if (i == n + m) {
					for (int a = 1; a <= n + m; a++) {
						if (a >= 1 && a <= m) {
							if (check_C[a] != true) {
								checkm = false;
							}
						}
						else {
							if (check_C[a] != true) {
								checkn = false;
							}
						}
						//std::cout << checkn << " " << checkm << " ";
					}
					if (checkn == true || checkm == true) {
						print();
						y++;

					}
				}
				else {
					elec(i + 1);
				}
				checkm = true; checkn = true;
			}
		}
	}
}*/
/*void baitoanchiatien() {
	int n, y = 0, check, sumx[MAX], a[MAX];
	char x[MAX];

	void input() {
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
	}

	void print() {
		for (int i = 1; i <= n; i++) {
			std::cout << x[i] << " ";
		}
		std::cout << "\n";
	}

	void half() {
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			sum += a[i];
		}
		check = sum / 2;
	}

	//bài toán chia tiền
	void AB(int i) {
		for (int v : {65, 66}) {
			sumx[v] += a[i];
			if (sumx[v] <= check) {
				x[i] = v;
				if (sumx[65] == sumx[66] && i == n) {
					print();
					y++;
				}
				else {
					AB(i + 1);
				}
			}
			sumx[v] -= a[i];
		}
	}

}*/

void solution(){
	
}
void input(int a[], int n) {
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
}
void display(int a[], int n) {
	for (int i = 0; i < n; i++) {
		std::cout << a[i] << " ";
	}
}

int main() {
	int a[MAX], n, k;
	std::cin >> n >> k;
	input(a, n);
	mergasort(a, 0, n - 1, k);
	display(a, n);
	return 0;
}



