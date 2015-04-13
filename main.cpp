#include <iostream>
#include <limits>
#include <sstream>
#include <bits/stream_iterator.h>
#include <stdlib.h>
#include "Graph.h"

vector<string> split(const string &s, char delim) ;
bool isNumber(const string& s);

using namespace std;

int main() {
    int numberOfNodes;
    while (true) {
    cout << "Podaj ilosc wezlow w grafie" << endl;
    cout << "Ilosc wezlow: ";
    cin >> numberOfNodes;
    if(numberOfNodes > 0);
        break;
    }
    Graph* graph = new Graph(numberOfNodes);
    for (int i = 0; i < numberOfNodes; ++i) {
        int nodeValue;
        cin.clear();
        cout << "Podaj wartosc " << i+1 << "-ego wezla" << endl;
        cout << "Wartosc wezla: ";
        if(cin >> nodeValue){
            graph->createNodeWithValue(i,nodeValue);
        }
        else
        {
            i--;
            cout << "Niepoprawna wartosc" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    }
    cout << "Podaj krawedzie wedlug wzoru 'index index', jesli chcesz zakonczyc wpisz 'exit' (pamietaj ze numeruje sie od 0)" << endl;
    while(true){
        string temp;
        cout << "Wprowadz relacje:";
        getline (cin,temp);
        if(temp == "exit")
            break;
        cout << temp << endl;
        vector<string> tokens = split(temp, ' ');
        if(tokens.size() != 2 || !isNumber(tokens.at(0)) || !isNumber(tokens.at(1))) {
            cout << "Bledna relacja" << endl;
            continue;
        }
        int node = atoi(tokens.at(0).c_str());
        int neighbour = atoi(tokens.at(1).c_str());
        if(node < 0 || neighbour < 0 || node >= numberOfNodes || neighbour >= numberOfNodes){
            cout << "Bledne dane" << endl;
            continue;
        }
        graph->getNode(node)->pushNeighbor(graph->getNode(neighbour));
    }
    graph->neighbourhoodList();
    while(true) {
        int tempNodeIndex, nextFunctionArgument, vertexFunctionArgument;
        cout << "Podaj index wezla dla ktorego uruchomic funkcje first, next i vertex (pamietaj ze numeruje sie od 0)" << endl;
        cout << "Wezel nr: ";
        cin >> tempNodeIndex;
        cout << "Podaj drugi argument funkji next (pamietaj ze numeruje sie od 0)" << endl;
        cout << "Argument: ";
        cin >> nextFunctionArgument;
        cout << "Podaj drugi argument funkcji vertex (pamietaj ze numeruje sie od 0)" << endl;
        cout << "Argument: ";
        cin >> vertexFunctionArgument;
        if(tempNodeIndex > numberOfNodes || tempNodeIndex < 0){
            cout << "Bledne dane" << endl;
            continue;
        }
        if(graph->first(tempNodeIndex) == -1){
            cout << "Blad funkcji 'first'" << endl;
            continue;
        }
        cout << "Rezultat funkcji 'first': " << graph->first(tempNodeIndex) << endl;
        if(graph->next(tempNodeIndex,nextFunctionArgument) == -1){
            cout << "Blad funkcji 'next'" << endl;
            continue;
        }
        cout << "Rezultat funkcji 'next': " << graph->next(tempNodeIndex,nextFunctionArgument) << endl;
        if(graph->vertex(tempNodeIndex,vertexFunctionArgument) == nullptr){
            cout << "Blad funkcji 'vertex' lub wezel nie jest sasiadem" << endl;
            continue;
        }
        cout << "Rezultat funkcji 'vertex': " << graph->vertex(tempNodeIndex,vertexFunctionArgument) << endl;
        break;
    }
    delete graph;

}

vector<string> &split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

bool isNumber(const string& s)
{
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}