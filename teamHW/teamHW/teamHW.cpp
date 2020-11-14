// teamHW3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
enum class Size { TALL, GRANDE, VENTI };
class Beverage {
public:
    char description[255];
    Size beverageSize;
public:
    Beverage();
    virtual char* getDescription();
    virtual double cost();
    virtual Size getSize();
    virtual void displayDescription();
};

class Espresso : public Beverage {
public:
    Espresso(Size size);
    Size getSize();
    double cost();
    void displayDescription();
};

class HouseBlend : public Beverage {
public:
    HouseBlend(Size size);
    Size getSize();
    double cost();
    void displayDescription();
};

class DarkRoast : public Beverage {
public:
    DarkRoast(Size size);
    Size getSize();
    double cost();
    void displayDescription();
};

class DecafeCoffee : public Beverage {
public:
    DecafeCoffee(Size size);
    Size getSize();
    double cost();
    void displayDescription();
};

class CodimentDecorator : public Beverage {

};

class Mocha : public CodimentDecorator {
public:
    Beverage* beverage;

public:
    Mocha(Beverage* beverage);
    char* getDescription();
    Size getSize();
    double cost();
};

class Milk : public CodimentDecorator {
    Beverage* beverage;

public:
    Milk(Beverage* beverage);
    char* getDescription();
    Size getSize();
    double cost();
};

class Soy : public CodimentDecorator {
    Beverage* beverage;

public:
    Soy(Beverage* beverage);
    char* getDescription();
    Size getSize();
    double cost();
};

class Whip : public CodimentDecorator {
    Beverage* beverage;

public:
    Whip(Beverage* beverage);
    char* getDescription();
    Size getSize();
    double cost();
};

Beverage::Beverage() {
    memset(description, 0, 225);
    strcpy(description, "Unknown Beverage");
}

char* Beverage::getDescription() {
    return description;
}

double Beverage::cost() {
    return 0.0;
}

Size Beverage::getSize()
{
    return Size();
}

Espresso::Espresso(Size size) {
    this->beverageSize = size;
    strcpy(description, "Espresso");
}
double Espresso::cost() {
    return 1.99;
}
void Espresso::displayDescription()
{
}
Size Espresso::getSize() {
    return beverageSize;
}

HouseBlend::HouseBlend(Size size) {
    this->beverageSize = size;
    strcpy(description, "HouseBlend");
}
double HouseBlend::cost() {
    return 1.99;
}
void HouseBlend::displayDescription()
{
}
Size HouseBlend::getSize() {
    return beverageSize;
}

DarkRoast::DarkRoast(Size size) {
    this->beverageSize = size;
    strcpy(description, "Espresso");
}
double DarkRoast::cost() {
    return 0.99;
}
void DarkRoast::displayDescription()
{
}
Size DarkRoast::getSize() {
    return beverageSize;
}

DecafeCoffee::DecafeCoffee(Size size) {
    this->beverageSize = size;
    strcpy(description, "DecafeCoffee");
}
double DecafeCoffee::cost() {
    return 1.05;
}
void DecafeCoffee::displayDescription()
{
}
Size DecafeCoffee::getSize() {
    return beverageSize;
}

Mocha::Mocha(Beverage* beverage) {
    this->beverage = beverage;
    strcpy(description, this->beverage->getDescription());
}
char* Mocha::getDescription() {
    return strcat(description, ", Mocha");
}
Size Mocha::getSize() {
    return beverageSize;
}
double Mocha::cost() {
    if (getSize() == Size::TALL)
        return beverage->cost() + 0.20;
    else if (getSize() == Size::GRANDE)
        return beverage->cost() + 0.25;
    else
        return beverage->cost() + 0.30;
}
Milk::Milk(Beverage* beverage) {
    this->beverage = beverage;
    strcpy(description, this->beverage->getDescription());
}
char* Milk::getDescription() {
    return strcat(description, ", Milk");
}
Size Milk::getSize() {
    return beverageSize;
}
double Milk::cost() {
    if (getSize() == Size::TALL)
        return beverage->cost() + 0.20;
    else if (getSize() == Size::GRANDE)
        return beverage->cost() + 0.25;
    else
        return beverage->cost() + 0.30;
}
Soy::Soy(Beverage* beverage) {
    this->beverage = beverage;
    strcpy(description, this->beverage->getDescription());
}
char* Soy::getDescription() {
    return strcat(description, ", Soy");
}
Size Soy::getSize() {
    return beverageSize;
}
double Soy::cost() {
    if (getSize() == Size::TALL)
        return beverage->cost() + 0.20;
    else if (getSize() == Size::GRANDE)
        return beverage->cost() + 0.25;
    else
        return beverage->cost() + 0.30;
}
Whip::Whip(Beverage* beverage) {
    this->beverage = beverage;
    strcpy(description, this->beverage->getDescription());
}
char* Whip::getDescription() {
    return strcat(description, ", Whip");
}
Size Whip::getSize() {
    return beverageSize;
}
double Whip::cost() {
    if (getSize() == Size::TALL)
        return beverage->cost() + 0.20;
    else if (getSize() == Size::GRANDE)
        return beverage->cost() + 0.25;
    else
        return beverage->cost() + 0.30;
}
void Beverage::displayDescription() {
    printf("%s : %.2f \n", getDescription(), cost());
}
int main()
{
    Beverage* bever1 = new DarkRoast(Size::TALL);
    bever1 = new Milk(bever1);
    bever1 = new Mocha(bever1);
    bever1 = new Milk(bever1);
    bever1->displayDescription();

    Beverage* bever2 = new Espresso(Size::GRANDE);
    bever2 = new Milk(bever2);
    bever2 = new Milk(bever2);
    bever2 = new Milk(bever2);
    bever2->displayDescription();

    Beverage* bever3 = new Espresso(Size::VENTI);
    bever3 = new Whip(bever3);
    bever3 = new Milk(bever3);
    bever3 = new Soy(bever3);
    bever3 = new Mocha(bever3);
    bever3->displayDescription();

    return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
