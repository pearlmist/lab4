#include <iostream>
#include <memory>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    int N;
    int M;
    cout << "Введите количество столбиков матрицы: ";
    cin >> M;
    if ((std::cin.fail()) or (M < 1)) {
        std::cout << "Неверное число M\n";
        return 0;
    }
    cout << "Введите количество строк матрицы: ";
    cin >> N;
    if ((std::cin.fail()) or (N < 1)) {
        std::cout << "Неверное число N\n";
        return 0;
    }

    //создание матрицы
    unique_ptr<char* []> arr(new char* [N]);
    for (int i = 0; i < N; i++) {
        arr[i] = new char[M];
    }

    //заполнение матрицы и вывод
    cout << "Заполненная матрица:" << "\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            arr[i][j] = rand()%10 + 710;
            //arr[N - 1][M - 1] = 'З';
            cout << arr[i][j] << ' ';
            if (j + 1 == M) cout << "\n";
        }
    }

    //подсчет уникальных элементов
    int temp = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            bool unique = true;
            for (int k = i; k < N; k++) {
                for (int l = j; l < M; l++) {
                    if (not((k == i) && (l == j))) {
                        unique = unique && (arr[i][j] != arr[k][l]);
                    }
                }
            }
            if (unique == true)
                    temp++;
        }
    }
    cout << "Количество уникальных символов: "<<temp;
    //удаление строк
    for (int i = 0; i < N; i++) {
        delete arr[i];
    }
}
