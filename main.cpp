#include <iostream>
#include <cmath>

using namespace std;

//TODO: Бинарный поиск
//TODO: Сравнить скорости линейного и бинарного поиска
//TODO: Сравнить 3 любые сортировки и реализовать их

int main() {
    int n, index_min, index_max;
    double sum = 0, x_max, x_min, result = 1;
    cout<<"INPUT: n -> A[n]"<<endl;
    cin>>n;
    double A[n];
    for (int i = 0; i < n; i++) {
        cin>>A[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            if (A[j] < A[j + 1]) {
                double temp = A[j];
                A[j] = A[j + 1];
                A[j + 1]  = temp;
            }
        }
    }

    x_max = abs(A[0]);
    x_min = abs(A[0]);

    for (int i = 0; i < n; i++) {
        if (A[i] < 0) sum+=A[i];
        if (abs(A[i]) > x_max) {
            x_max = A[i];
            index_max = i;
        }
        if (abs(A[i]) < x_min) {
            x_min = A[i];
            index_min = i;
        }
    }

    for (int i = index_min; i < index_max; i++) {
        result *= A[i];
    }

    cout<<"SUM: "<<sum<<"; MULTIPLY: "<<result<<endl;
}