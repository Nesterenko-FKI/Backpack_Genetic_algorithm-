#include "Parser.cpp"
#include <iostream>
#include <vector>

using namespace std;

class Solver{
    Parser* parser;
    vector <vector <int>> P_old;
    vector <vector <int>> P_new;
        
    int fitness(Parser* parser, vector <int> q) {
        int cost = 0;
        int weight = 0;
        for (int i = 0; i < parser->N; i++) {
            weight = weight + parser->w[i]*q[i];
        }
        if (weight <= parser->m_w) {
            for (int i = 0; i < parser->N; i++){
                cost = cost + parser->c[i]*q[i];
            }
            return cost;
        }
        return 0;
    }
    
    int selection(Parser* parser, int x, int y) {
        if (P_old[x][parser->N] > P_old[y][parser->N]) {
            return x;
        }
        return y;
    }
    
    void mutate (Parser* parser,vector <int> i) {
        int a = rand()%parser->N;
        i[a] = 0;
        return;
    }
    
    void crossover (Parser* parser, int x, int y) {
        vector <int> i1, i2;
        int n = parser->N/2;
        for (int i = 0; i < n; i++) {
            i1.push_back(P_old[x][i]);
            i2.push_back(P_old[y][i]);
        }
        for (int i = n; i < parser->N; i++) {
            i1.push_back(P_old[x][i]);
            i2.push_back(P_old[y][i]);
        }
        mutate (parser, i1);
        mutate (parser, i2);
        i1.push_back(fitness(parser, i1));
        i2.push_back(fitness(parser, i2));
        P_new.push_back(i1);
        P_new.push_back(i2);
    }
    
    void copy (Parser* parser, int quantity) {
        for (int i = 0; i < quantity; i++){
            for (int j = 0; j <= parser->N; j++){
                P_old[i][j] = P_new[i][j];
            }
        }
    }
    
public:
    Solver (Parser* parser, int quantity = 250) {
        for (int r = 0; r < 20000; r++) {
            srand(time(0));
            for (int i = 0; i < quantity; i++) {
                vector <int> individual;
                int g = 0;
                for (int j = 0; j < parser->N; j++) {
                    g = rand()%100; //для файлов с кодичеством элементов >= 100 нужно писать g = rand()%1000
                    if (g > 25) {
                        individual.push_back(0);
                    }
                    else individual.push_back(1);
                }
                individual.push_back(fitness(parser, individual));
                P_old.push_back(individual);
            }
            for (int i = 0; i < quantity/2; i++) {
                int x = 0;
                int y = 0;
                int z1, z2;
                while(x==y) {
                    x = rand()%quantity;
                    y = rand()%quantity;
                }
                z1 = selection(parser, x, y);
                x = y = 0;
                while(x==y) {
                    x = rand()%quantity;
                    y = rand()%quantity;
                }
                z2 = selection(parser, x, y);
                crossover(parser, z1, z2);
            }
            copy (parser, quantity);
        }
        int max = 0;
        for (int i = 1; i < quantity; i++){
            if(P_old[max][parser->N] < P_old[i][parser->N]) {
                max = i;
            }
        }
        int R = 0;
        for (int i = 0; i < parser->N; i++){
            R = R + P_old[max][i]*parser->w[i];
        }
        cout<<P_old[max][parser->N]<<" "<<parser->m_w - R<<endl;
        for (int i = 0; i < parser->N; i++){
            cout<<P_old[max][i]<<" ";
        }
        cout<<endl;
    };
};