# include <iostream>
using namespace std;

class Hanoi {
public:
	void HanoiTowers(int n, char a, char b, char c);
	void Move(int n, char s, char t);
};

void Hanoi::HanoiTowers(int n, char a, char b, char c) {
	if (n == 1) {
		Move(1, a, b);
	}
	else {
		HanoiTowers(n - 1, a, c, b);
		Move(n, a, b);
		HanoiTowers(n - 1, c, b, c);
	}

	return ;
}

void Hanoi::Move(int n, char s, char t) {
	cout << "move the " << n << "th dish from " << s << " to " << t << endl;
	return ;
}

int main() {
	Hanoi h;
	int n;
	cout << "Please enter the number of dishes: ";
	cin >> n;
	h.HanoiTowers(n, 'A', 'B', 'C');
	
	system("pause");
	return 0;
}