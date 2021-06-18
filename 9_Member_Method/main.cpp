//
//  main.cpp
//  9_Member_Method
//
//  Created by 세광 on 2021/06/18.
//

/*
 const의 쓰임
 - 매개변수의 상수화
 - 메서드의 상수화(어떤 메서드에 대해서, 그 메서드 안에서 자기가 속한 class 안의 다른 멤버 변수를 건드릴 수 없도록 막아버리는 것)
   (멤버 변수에 읽기 접근은 가능하지만 쓰기 접근은 허용되지 않음)
 */

#include <iostream>

using namespace std;

class Vector2 {
public:
    Vector2();
    Vector2(float x, float y);
    
    float GetX() const;
    float GetY() const;
    
    static Vector2 Sum(Vector2 a, Vector2 b) {
        return Vector2(a.x + b.x, a.y + b.y);
    }
    
    Vector2 Add(Vector2 rhs) { // 동적으로 선언하는 방법(연산자 오버로딩과 관련이 있음)
        return Vector2(x + rhs.x, y + rhs.y);
    }
    
private:
    float x;
    float y;
};

int main() {
    Vector2 a(2, 3);
    Vector2 b(-1, 4);
    
    Vector2 c1 = Vector2::Sum(a, b);
    Vector2 c2 = a.Add(b);
    
    cout << a.GetX() << ", " << a.GetY() << endl;
    cout << b.GetX() << ", " << b.GetY() << endl;
    
    cout << c1.GetX() << ", " << c1.GetY() << endl;
    cout << c2.GetX() << ", " << c2.GetY() << endl;
    
}

Vector2::Vector2() : x(0), y(0) { }
Vector2::Vector2(float x, float y) : x(x), y(y) { }

float Vector2::GetX() const { return x; }
float Vector2::GetY() const { return y; }
