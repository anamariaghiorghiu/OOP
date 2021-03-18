class Number
{
	char* numar;
	int baza{ 10 };
public:
	Number(const char* value, int base); // where base is between 2 and 16
	~Number();
	bool operator< (Number obiect);
	bool operator<= (Number obiect);
	bool operator> (Number obiect);
	bool operator>= (Number obiect);
	void operator-- ();
	void operator-- (int valoare);
	Number& operator+(Number obiect);
	Number& operator-(Number obiect);
	Number& operator=(Number obiect);
	Number& operator=(int valoare);
	Number& operator=(const char* valoare);
	Number& operator+=(Number obiect);
	Number& operator-=(Number obiect);
	bool operator == (Number obiect);
	char operator[](int pozitie);
	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};