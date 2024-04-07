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
