#include <iostream>
#include <string>
#include <vector>
#include <getopt.h>
#include <cmath>

using namespace std;

double arcsin(double operand, int mode) {
	double result = 0;
	result = asin(operand);
	if (mode == 1) {
		result = result*180.0/M_PI; 
	}
	return result;
}

double arccos(double operand, int mode) {
	double result = 0;
	result = acos(operand);
	if (mode == 1) {
		result = result*180.0/M_PI; 
	}
	return result;
}

void printHelp() {
   cout << "Использование: calculator -o [операция] [режим работы] [операнды]" << endl;
   cout << "Опции:" << endl;
   cout << " -o операция задает операцию (arcsin или arccos)" << endl;
   cout << " -h Вывести справку" << endl;
   cout << "Операнды:" << endl;
   cout << " Один операнд для вычисления арксинуса или арккосинуса" << endl;
   cout << " Режим работы: 0 - радианы, 1 - градусы" << endl;
   }

int main(int argc, char* argv[]) {
	string operation;
    int mode = stoi(argv[3]); 
    int option;
    while ((option = getopt(argc, argv, "o:h")) != -1) {
	 switch (option) {
	 	case 'o':
	 		operation = optarg;
	 		break;
	 	case 'h':
	 		printHelp();
	 		return 0;
	 	default:
	 		cout << "Неизвестная опция" << endl;
	 		return 1;
	 } 
    } 
    
    double operand = stod(argv[4]);
    if (operation.empty()) {
		cout << "Не указана операция" << endl;
		return 1;
	}
    double result;
    if (operation == "arcsin") {
		result = arcsin(operand, mode);
    } else if (operation == "arccos") {
		result = arccos(operand, mode);
    } else {
		cout <<"Неизвестная операция" <<endl;
		return 1;
    }
    cout << "Результат: " << result << endl;
	return 0;
}
