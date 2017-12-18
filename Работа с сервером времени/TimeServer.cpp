#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <exception>
#include <sstream>
#include <stdexcept>

using namespace std;

string AskTimeServer() {
	/* ƒл€ тестировани€ повставл€йте сюда код, реализующий различное поведение этой функии:
	* нормальный возврат строкового значени€
	* выброс исключени€ system_error
	* выброс другого исключени€ с сообщением.
	*/

	ifstream input("unit.txt");
	string line;

	while (getline(input, line)) {
		return line;
	}
}

class TimeServer {
public:
	string GetCurrentTime() {
		/* –еализуйте этот метод:
		* если AskTimeServer() вернула значение, запишите его в LastFetchedTime и верните
		* если AskTimeServer() бросила исключение system_error, верните текущее значение
		пол€ LastFetchedTime
		* если AskTimeServer() бросила другое исключение, пробросьте его дальше.
		*/
		try {
			LastFetchedTime = AskTimeServer();
			return LastFetchedTime;
		}
		catch (system_error&) {
			return LastFetchedTime;
		}
	}

private:
	string LastFetchedTime = "00:00:00";
};

int main() {
	// ћен€€ реализацию функции AskTimeServer, убедитесь, что это код работает корректно
	TimeServer ts;
	try {
		cout << ts.GetCurrentTime() << endl;
	}
	catch (exception& e) {
		cout << "Exception got: " << e.what() << endl;
	}
	return 0;
}