#include <iostream>
#include <cstdlib>
#include <ctime>
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
void moveCell(int& x, int& y, int& newX, int& newY, int **pole){
    pole[newX][newY] = pole[x][y];
    pole[x][y] = 0;
    x = newX;
    y = newY;
}


int main() {
    char chek;
    do{
        int task;

        cout << "Enter the task number: ";
        cin >> task;
        if (task == 1 or task == 2 or task == 4) {
            float arry[7];
            int i {0};

            cout << "Task 1, 2, 4" << endl;
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

        } else if (task == 6) {
            cout <<  "Task 6" << endl;
            int n;
            cout << "Enter number of rows and columns: ";
            cin >> n;

            if (n%2 == 0 or n == 1 or n < 0 ) {
                while (n%2 == 0 or n == 1 or n < 0) {
                    cout << "Error..."<< endl << "Number of rows and colums mus be odd or you wrote 1, please put the n > 1" << endl << "Enter number of rows and columns: " << endl;
                    cin >> n;
                }

            }
            int **pole = new int*[n];
            for (int i {0}; i < n; i++) {
                pole[i] = new int[n];
            }

            for (int i {0}; i < n; i++) {
                for (int j {0}; j < n; j++) {
                    pole[i][j] = 0;
                }
            }
            int counter{0};
            srand(time(NULL));
            while (counter < n) {
                int x = 0 + rand() % (n-1);
                int y = 0 + rand() % (n-1);
                if (pole[x][y] == 0) {
                    pole[x][y] = 1;
                    counter++;
                }
            }

            for (int i {0}; i < n; i++) {
                for (int j {0}; j < n; j++) {
                    cout << pole[i][j] << " ";
                    if (j == n-1) cout<< endl;
                }
            }
            cout << "PS. You will be the '8' on the map ^_~"<< endl;

            cout << "Choose the cell: ";

            int choosen_x, choosen_y, choosen_x_2, choosen_y_2;
            cin >> choosen_x;
            cin >> choosen_y;

            while (choosen_x >= n or choosen_y >= n) {
                cout << "Error out of range..."<< endl << "Choose another cell: ";
                cin >> choosen_x;
                cin >> choosen_y;
            }

            while (pole[choosen_x][choosen_y] == 0) {
                cout << "You choose the empty cell..."<< endl << "Choose another cell: ";
                cin >> choosen_x;
                cin >> choosen_y;
            }

            if (pole[choosen_x][choosen_y] == 1) {
                pole[choosen_x][choosen_y] = 8;
                while (true) {
                    cout << "One more cell: ";
                    cin >> choosen_x_2;
                    cin >> choosen_y_2;

                    while (choosen_x_2 >= n or choosen_y_2 >= n) {
                        cout << "Error out of range..."<< endl << "Choose another cell: ";
                        cin >> choosen_x_2;
                        cin >> choosen_y_2;
                    }


                    while (((choosen_x == choosen_x_2 and choosen_y != choosen_y_2) or (choosen_x != choosen_x_2 and choosen_y == choosen_y_2)) == 0) {
                        cout << "Error diagonalnoe peremeschenie or you wrote the same cell..."<< endl << "Choose another cell: ";
                        cin >> choosen_x_2;
                        cin >> choosen_y_2;
                    }
                    if (pole[choosen_x_2][choosen_y_2] == 1) {
                        cout << "Congratulations! You win!" << endl;
                        break;
                    }
                    if (pole[choosen_x_2][choosen_y_2] == 0) {
                        moveCell(choosen_x, choosen_y, choosen_x_2, choosen_y_2, pole);
                        for (int i {0}; i < n; i++) {
                            for (int j {0}; j < n; j++) {
                                cout << pole[i][j] << " ";
                                if (j == n-1) cout<< endl;
                            }
                        }
                    }
                }
            }





        } else {
            cout << endl << "Error..." << endl << "Incorrect number of task" <<endl;
        }
    cout << endl  << "Start new task y/n?" << endl;
    cin >> chek;
    while (chek != 'y' and chek != 'n' and chek != 'Y' and chek != 'N') {
        cout << "What are you wrote???" << endl << "Only y/n!!!" << endl;
        cout << "Start new task y/n?" << endl;
        cin >> chek;
    }
    } while (chek == 'y' or chek == 'Y');
    return 0;
}