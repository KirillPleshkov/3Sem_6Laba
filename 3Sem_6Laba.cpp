#include "Complex.h"
#include "Сalendar.h"
#include "IError.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	double num, a, b, c;
	vector<string> errorList;

	while (true)
	{
		try
		{
			cout << "Задание 1" << endl;
			Complex A(4, 5);
			cout << "Комплексное число A: " << A << endl;
			Complex B;
			cout << "Введите значение комплексного числа B(2,3+4,5i): ";


			cin >> B;

			cout << "Вы ввели: " << B << endl;

			cout << "Сумма A и B: " << A + B << endl;
			cout << "Разность A и B: " << A - B << endl;
			cout << "Произведение A и B: " << A * B << endl;
			cout << "Частное A и B: " << A / B << endl;

			cout << boolalpha << "A и B равны?: " << (A == B) << endl;

			cout << "Введите степень в которую возведем число A: ";
			try
			{
				cin >> num;
			}
			catch (exception)
			{
				throw IncorrectInput();
			}
			A.Pow(num);
			cout << "A в степени " << num << " = " << A << endl;

			cout << "Введите степень корень которого возьмем из числа A: ";
			try
			{
				cin >> num;
			}
			catch (exception)
			{
				throw IncorrectInput();
			}
			cout << "A в корне степени " << num << " = " << A.Sqrt(num)[0] << endl;

			cout << "Введите коэффициенты квадратного уравнения" << endl;

			cout << "a: ";
			try
			{
				cin >> a;
			}
			catch (exception)
			{
				throw IncorrectInput();
			}

			cout << "b: ";
			try
			{
				cin >> b;
			}
			catch (exception)
			{
				throw IncorrectInput();
			}

			cout << "c: ";
			try
			{
				cin >> c;
			}
			catch (exception)
			{
				throw IncorrectInput();
			}

			pair<Complex, Complex> rezult = Equation(a, b, c);
			cout << "Первый корень: " << rezult.first << endl;
			cout << "Второй корень: " << rezult.second << endl;

			cout << "Логгер обьекта A:" << endl;
			A.PrintLog();
			cout << endl << endl;

			cout << "Задание 2" << endl;

			Date date1;
			Date date2(1999, Jun, 22, 11, 34, 55);
			Date date3(1999, May, 22);
			Date date4(99, 34, 22);

			cout << "Текущее время: " << date1.toString() << endl;
			Date date5 = date1;
			date5 = date5.addHours(1);
			date5 = date5.addMinutes(30);
			cout << "Время от текущего времени + еще одна пара(полтора часа): " << date5.toString() << endl;

			DateInterval interval = date1.getInterval(date5);

			cout << "Интервал времени между двумя датами: " << interval.toString() << endl;

			cout << "Добавим этот интервад к другой дате: " << date2.addInterval(interval).toString() << endl;

			date1 = Date();


			string format = "Часов: hh, Минут: mm, Секунд: ss";
			cout << "Формат даты: " << format << endl;
			cout << "Строка с подставленными знаениями: " << date1.FormatDate(format);

			
			break;
		}
		catch (IError& error)
		{
			errorList.push_back(error.Print());
			system("cls");
		}
		
	}
	cout << endl << endl << "Errors:" << endl;

	for (auto error : errorList)
	{
		cout << error;
	}
	
	cout << endl << endl;
}
