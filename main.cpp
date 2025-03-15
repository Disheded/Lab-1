#include <iostream>
using namespace std;

void chet_nechet_dynamic_array (int *array, int size, int chet, int nechet) {
    int j{0};
    int g{0};
    int **matrix = new int*[2];
    matrix[0] = new int[chet];
    matrix[1] = new int[nechet];
    for (int i = 0; i < size; i++) {
        if (array[i]%2 == 0) {
            matrix[0][j] = array[i];
            j+=1;
        } else {
            matrix[1][g] = array[i];
            g+=1;
        }

    }
    cout << "Chet numbers: ";
    for (int i = 0; i < chet; i++) {
        cout << matrix[0][i] << " ";
    }
    cout << endl << "Nechet numbers: ";
    for (int i = 0; i < nechet; i++) {
        cout << matrix[1][i] << " ";
    }

};
void change (int &a, int &b) {
    a = a + b;
    b = 0;
}


int main() {
    int task;
    cout << "Enter the task number: ";
    cin >> task;
    if (task == 1 or task == 2 or task == 4) {
        float arry[7];
        int i {0};

        cout << "Task 1-2" << endl;
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

        cout << endl << "Well task four is coming..." <<endl;


        int size_of_arry = size(arry);
        int the_middle_element_number = size_of_arry / 2;
        float &middle_element = arry[the_middle_element_number];
        float &first_element = arry[0];
        float &last_element = arry[size_of_arry - 1];
        cout << "Middle element: " << middle_element << endl;
        cout << "First element: " << first_element << endl;
        cout << "Last element: " << last_element << endl;

        float srednee_of_first_and_last = (last_element + first_element)/2;
        cout << "Srednee: " << srednee_of_first_and_last << endl;

        middle_element = srednee_of_first_and_last;
        cout << "Middle element: " << middle_element << endl;







    } else if (task == 3) {
        cout <<  "Task 3" << endl;
        cout << "Dynamic arry length: ";
        int x{};
        int chet{0};
        int nechet{0};

        cin >> x;
        int *dynamic_arry = new int[x];
        for (int i {0}; i < x; i++) {
            cout << "Enter a number "<< i+1 <<": ";
            cin >> dynamic_arry[i];
            if (dynamic_arry[i]%2 == 0) {
                chet +=1;
            } else {
                nechet +=1;
            }
        }
        chet_nechet_dynamic_array(dynamic_arry, x, chet, nechet);
    } else if (task == 5) {
        cout <<  "Task 5" << endl;
        int first{0};
        int second{0};
        cout << "First number: ";
        cin >> first;
        cout << "Second number: ";
        cin >> second;
        cout << "Magic....... ";
        change(first, second);
        cout << endl << "First number: " << first << endl;
        cout << "Second number: " << second << endl;






    }


    return 0;
}