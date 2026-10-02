#include <iostream>
#include <vector>

using namespace std;

int SommaMassima1(vector<int> B){
    auto maxs = 0;
    auto n = B.size();
    for (auto i = 0; i < n; ++i){
        for (auto j = i; j < n; ++j){
            auto somma = 0;
            for (auto k=i; k<=j; ++k)
                somma += B[k];
            if (somma > maxs)
                maxs = somma;
        }
    }
    return maxs;
}

int random(int a, int b){
    // voglio un numero in [a,b]
    return a + rand() % (b-a+1);
}

vector<int> generaArrayCasuale(int n, int minVal = -10, int maxVal = 10 ){
    // se so a propri n del vettore, dillo subito, evito di muovere la memoria 
    // se non lo so a priori, per aggiungere pezzi devo usare A.push_back(value)
    vector<int> A(n);
    for (auto i=0; i<n; i++){
        A[i] = random(minVal, maxVal);
    }
    return A;
}

void printArray(vector<int> A){
    // for (auto i=0; i<A.size(); i++) cout << A[i] << " ";

    // can only do with vectors = for x in A
    for (auto x : A){
        cout << x << ' ';
    }
    cout << endl;

}

int main(){
    vector<int> A {generaArrayCasuale(11)};
    printArray(A);
    auto maxSegmentSum = SommaMassima1(A);
    cout << "Il segmento di somma massima di A è: " << maxSegmentSum << endl;
    return 0;
}