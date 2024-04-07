#include <iostream>
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Parser {
    
private:
    string filename;
    ifstream fin;
    
public:
    vector <int> c, w;
    int N;
    int m_w;
    Parser(const string& path) {
        fin.open(path);
        if (!fin.is_open()) {
            cout << "error!" << endl;
        }
        else {
            string str;
            fin >> str;
            N = stoi(str);
            fin >> str;
            m_w = stoi(str);
            int i = 0;
            while (i < N) {
                str = "";
                fin >> str;
                c.push_back(stoi(str));
                fin >> str;
                w.push_back(stoi(str));
                i++;
            }
        }
        fin.close();
    };
};



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
