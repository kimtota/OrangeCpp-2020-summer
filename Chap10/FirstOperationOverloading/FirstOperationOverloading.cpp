#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{ }
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;	//따옴표 주의!!!
	}
	Point operator+(const Point& ref)	//operator+ 라는 이름의 함수
	{
		Point pos(xpos + ref.xpos, ypos + ref.ypos);
		return pos;
	}
};

int main(void) {
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3 = pos1.operator+(pos2);	//pos1 객체의 멤버함수 operator+를 호출하며 인자로 pos2 객체를 전달하고 있다.
										//따라서 이 두 객체의 멤버 별 덧셈결과로 새로운 Point객체가 만들어지고 이것이 반환되어 pos3를 초기화 (복사 생성자가 호출됨)

	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	return 0;
}