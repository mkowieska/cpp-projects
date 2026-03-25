#include <iostream>
using namespace std;

//Polimorfizm
//Klasa z metoda bez ciala jest klasa abstrakcyjna (nie mozna z niej stworzyc obiektu)
//Metoda wirtualna w klasach pochodnych zostaje wirtualna, gdy zachowuje taka sama sygnature.
//Typ obiektu cechuje sie jego zachowaniem

class Figure {
public:
	virtual void display() = 0;
};
class Point : public Figure {
	int x, y;
public:
	Point(int a, int b) :x(a), y(b) {}
	virtual void display() {
		cout << x << "\t" << y << endl;
	}
};
class Circle : public Point {
	int radius;
public:
	Circle(int a, int b, int c) : Point(a, b), radius(c) {}
	virtual void display() {
		Point::display(); cout << radius << endl;
	}
};
class Cilinder : public Circle {
	int height;
public:
	Cilinder(int a, int b, int c, int d) : Circle(a, b, c), height(d) {}
	virtual void display() {
		Circle::display(); cout << height << endl;
	}
};

//typ I
class A {
public:
	A(int aa) :a(aa) {}
	virtual void display() { 
		cout << a << endl; 
	}
private:
	int a;
};

class B : public A {
public:
	B(int aa, int bb) :A(aa), b(bb) {}
	virtual void display() { 
		A::display(); cout << b << endl; 
	}
private:
	int b;
};
void f(A* x) { x -> display(); }
void f(A& x) { x.display(); }

//typ II
// Konwersja do klasy bazowej odbywa się w argumentach formalnych na rzecz tak wskaznika, jak i referencji.


//Dziedziczenie
//Zapobieganie dziedziczeniu klasy
struct A2 {
	A2() = default;
	virtual ~A2() { cout << "destruktor A2" << endl; }
protected:
	int i{ 7 };
};
struct B2 final : A2 { // domyslnie dzedziczenie publiczne
	B2() = default;
	~B2() { cout << "destruktor B2" << endl; }
};
//class D2 : B2 {
	// domyslnie dzedziczenie prywatne - nie mozna dziedziczac po klasie final
//};

//Rozbudowa polimorfizmu
struct A3 {
	virtual ~A3() { cout << "destruktor A3" << endl; }
	virtual void show() { cout << "show A3" << endl; }
};
struct B3 : public A3 {
	~B3() { cout << "destruktor B3" << endl; }
	virtual void show(int i) { cout << "show int B3" << endl; }
	void show() override { cout << "show B3" << endl; }
};
struct C3 : public B3{
	~C3() { cout << "destruktor C3" << endl; }
	void show() override { cout << "show C3" << endl; } //override oznacza,ze metoda dokladnie przeladowuje funkcje wirtualna
	void show(int i) override { cout << "show int C3" << endl; }
	//void show() override final {cout << "show B3" << endl ;} //Zapobieganie dziedziczeniu metody wirtualnej umieszcza się kluczowego słowa final jako ostatnie w naglowku metody
};


int main() {
	Figure* fig[3];
	fig[0] = new Point(33, 44); //tablica fig
	fig[1] = new Circle(33, 44, 10);
	fig[2] = new Cilinder(33, 44, 10, 13);
	for (int i = 0; i < 3; i++)
		fig[i] -> display();

	A a1(33), a2(44);
	B b1(1, 2);
	f(&a1);
	f(a1);
	f(b1);

	A3* a[3]; a[0] = new A3; a[1] = new B3; a[2] = new C3;
	for (short i = 0; i < 3; i++) {
		a[i] -> show();
		// if(i>0)a[i]->show(i);
	}
}