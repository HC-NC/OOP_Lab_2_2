#include <iostream>
#include <Windows.h>

using namespace std;

class Complex
{
	int _actual;
	int _imaginaty;

public:

	Complex()
	{
		_actual = 0;
		_imaginaty = 0;
	};

	Complex(const int, const int);
	Complex(const Complex&);

	void Input();
	void Output();

	Complex operator=(int);

	friend istream& operator>>(istream&, Complex&);
	friend ostream& operator<<(ostream&, Complex&);

	bool operator==(const Complex&);

	Complex operator+(const Complex&);

	friend Complex operator-(Complex&, Complex&);
};

Complex::Complex(const int actual, const int imaginaty)
{
	_actual = actual;
	_imaginaty = imaginaty;
}

Complex::Complex(const Complex& complex)
{
	_actual = complex._actual;
	_imaginaty = complex._imaginaty;
}

void Complex::Input()
{
	cout << "Введите действительную часть: ";
	cin >> _actual;

	cout << "Введите мнимую часть: ";
	cin >> _imaginaty;
}

void Complex::Output()
{
	if (_actual == 0 && _imaginaty == 0)
	{
		cout << 0 << endl;
		return;
	}

	if (_actual != 0)
	{
		cout << _actual;

		if (_imaginaty > 0)
			cout << "+";
	}

	if (_imaginaty != 0)
		cout << _imaginaty << "i" << endl;
}

istream& operator>>(istream& stream, Complex& complex)
{
	cout << "Actual: "; stream >> complex._actual;
	cout << "Imaginaty: "; stream >> complex._imaginaty;
	return stream;
}

ostream& operator<<(ostream& stream, Complex& complex)
{
	if (complex._actual == 0 && complex._imaginaty == 0)
	{
		stream << 0;
		return stream;
	}

	if (complex._actual != 0)
	{
		stream << complex._actual;

		if (complex._imaginaty > 0)
			stream << "+";
	}

	if (complex._imaginaty != 0)
		stream << complex._imaginaty << "i";

	return stream;
}

Complex Complex::operator=(int n)
{
	_actual = n;
	_imaginaty = 0;
	return *this;
}

bool Complex::operator==(const Complex& complex)
{
	return _actual == complex._actual && _imaginaty == complex._imaginaty;
}

Complex Complex::operator+(const Complex& complex)
{
	return Complex(_actual + complex._actual, _imaginaty + complex._imaginaty);
}

Complex operator-(Complex& c1, Complex& c2)
{
	return Complex(c1._actual - c2._actual, c1._imaginaty - c2._imaginaty);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Complex a, b(1, -3), c(0, 5), d(b);

	a.Output();
	b.Output();
	c.Output();
	d.Output();

	a.Input();
	a.Output();

	cin >> a;
	cout << a << endl;

	a = 5;
	cout << a << endl;

	if (b == d)
		cout << "b == d" << endl;
	else
		cout << "b != d" << endl;

	if (a == c)
		cout << "a == c" << endl;
	else
		cout << "a != c" << endl;

	d = b + c;

	cout << "b + c = ";
	d.Output();

	d = b - c;

	cout << "b - c = " << d << endl;
}