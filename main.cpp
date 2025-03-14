#include <iostream>
using namespace std;


int main() {
    float arry[7];
    int i {0};
    while (i<7) {
        cout << "Enter a number "<< i+1 <<": ";
        cin >> arry[i];
        i++;
    }
    for (int i {0}; i < 7; i++) {
        cout << arry[i] << " ";
    }
    int povtor = 0;
    for (int i = 0; i < 7; i++) {
        for (int j = i + 1; j < 7; j++) {
            if (arry[i] == arry[j]) {
                povtor++;
                break;
            }
        }
    }
    cout << "" << endl;
    cout << "Povtor: " << povtor << endl;


    float *max=&arry[0];
    float *min=&arry[0];
    for (int i {1}; i < 7; i++) {
        if (*max < arry[i]) {
            max = &arry[i];
        }
    }

    cout << "Max: " << *max << endl;




    for (int i {1}; i < 7; i++) {
        if (*min > arry[i]) {
            min = &arry[i];
        }
    }
    cout << "Min: " << *min << endl;
    *max = 0;
    *min = 0;
    cout << "Magic......." <<endl;
    cout << "Max: " << *max << endl;
    cout << "Min: " << *min << endl;
    return 0;
}