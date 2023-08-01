#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

const int ROWS = 30;
const int COLS = 60;

 // вывод дисплея
void display(int arr[ROWS][COLS])
{
    system("clear"); // очистка экрана
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (arr[i][j] == 1) cout << "#";
            else cout << ".";
        }
        cout << endl;
    }
}

int countNeighbors(int arr[ROWS][COLS], int row, int col)
{
    int count = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int r = row + i;
            int c = col + j;
            if ((r >= 0 && r < ROWS) && (c >= 0 && c < COLS) && !(i == 0 && j == 0)) {
                count += arr[r][c];
            }
        }
    }
    return count;
}
 // генерация там чего то там хз чего вернуться проверить
void nextGeneration(int arr[ROWS][COLS])
{
    int new_arr[ROWS][COLS];

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            int count = countNeighbors(arr, i, j);
            if (count < 2 || count > 3) {
                new_arr[i][j] = 0;
            } else if (count == 3) {
                new_arr[i][j] = 1;
            } else {
                new_arr[i][j] = arr[i][j];
            }
        }
    }

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            arr[i][j] = new_arr[i][j];
        }
    }
}

int main()
{
    int arr[ROWS][COLS] = {0};

    // типо база  для начала
    arr[10][10] = 1;
    arr[10][11] = 1;
    arr[11][11] = 1;
    arr[11][12] = 1;
    arr[12][11] = 1;

    while (true) {
        display(arr);
        nextGeneration(arr);

        // Пауза в 0.2 секунды для обновления экрана взята со стаковерфлоу
        this_thread::sleep_for(std::chrono::milliseconds(200));
    }
  
    return 0;
}

