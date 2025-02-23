#include <iostream>

int main() {
    int N, M, S, K, L, HC, start = 1, l, j, a = 1;
    int maxCoins = 1000; // Максимальное количество монет

    // Ввод данных
    while (1) {
        std::cout << "Enter number of coins with heads:" << std::endl;
        std::cin >> N;
        std::cout << "Enter number of coins with tails:" << std::endl;
        std::cin >> M;
        std::cout << "Enter position of coins to be turned over:" << std::endl;
        std::cin >> S;
        std::cout << "Enter number of steps:" << std::endl;
        std::cin >> K;
        std::cout << "Enter final number of coins with heads :" << std::endl;
        std::cin >> L;

        // Проверка корректности ввода
        if (N <= 0 || M <= 0 || S <= 0 || K <= 0 || L <= 0) {
            std::cout << "Incorrect input" << std::endl;
        }
        else break;
    }

    HC = M + N;             // Общее количество монет
    int coins[1000] = {};  // Массив для хранения начального состояния монет
    int coins2[1000] = {}; // Массив для хранения промежуточного состояния монет

    // Проверка на превышение максимального количества монет
    if (HC > maxCoins) {
        std::cout << "Too many coins" << std::endl;
        delete coins, coins2, N, M, S, K, L, HC, start, l, j, a, HC;
        return 0;
    }

    // Проверка возможности решения
    if (N + K < L || N - K > L) {
        std::cout << "There is no possible solution" << std::endl;
        delete coins, coins2, N, M, S, K, L, HC, start, l, j, a, HC;
        return 0;
    }

    // Заполнение начального состояния монет
    for (int i = 0; i < HC; i++) {
        if (i < N) {
            coins[i] = 1; // Гербы вверх
        }
        else {
            coins[i] = 0; // Решки вверх
        }
    }

    // Копирование начального состояния в coins2
    for (int i = 0; i < HC; i++) {
        coins2[i] = coins[i];
    }

    int p = 0;
    for (int i = 2; i < HC; i++) {
        a = 2 * a; // Вычисление количества возможных перестановок
    }

    // Перебор всех возможных перестановок
    for (int i = 0; i < a; i++) {
        // Генерация случайной перестановки
        int x = rand() % (HC - start + 1) + start;
        int m = rand() % (HC - start + 1) + start;
        l = coins[x];
        j = coins[m];
        coins2[x] = j;
        coins2[m] = l;

        // Выполнение K шагов переворачивания
        for (int q = (S - 1); q > -2; q = (q + S)) {
            if (q > (HC - 1)) {
                q = q - HC;             // Коррекция индекса для кругового массива
            }
            coins2[q] = 1 - coins2[q]; // Переворачивание монеты
            p++;
            if (p == K) break;         // Остановка после K шагов
        }

        p = 0;

        // Подсчет количества монет гербами вверх
        for (int q = 0; q < HC; q++) {
            if (coins2[q] == 1) p++;
        }

        // Проверка, совпадает ли количество гербов с L
        if (p == L) {
            p = 0;
            std::cout << "Combination after flip:" << std::endl;
            for (int i = 0; i < HC; i++) {
                if (coins2[i] == 1) std::cout << "head ";
                else std::cout << "tail ";
            }

            // Восстановление начального состояния
            for (int b = 0; b < HC; b++) {
                coins[b] = coins2[b];
            }

            // Повторное выполнение K шагов для вывода начального состояния
            for (int q = (S - 1); q > -2; q = (q + S)) {
                if (q > (HC - 1)) {
                    q = q - HC;
                }
                coins[q] = 1 - coins[q];
                p++;
                if (p == K) break;
            }

            p = 0;
            std::cout << std::endl;
            std::cout << "Combination before flip:" << std::endl;
            for (int i = 0; i < HC; i++) {
                if (coins[i] == 1) std::cout << "head ";
                else std::cout << "tail ";
            }
            return 0;
        }

        // Восстановление coins из coins2 для следующей итерации
        for (int b = 0; b < HC; b++) {
            coins[b] = coins2[b];
        }
        p = 0;
    }
    delete coins, coins2, N, M, S, K, L, HC, start, l, j, a, p, HC;
    return 0;
}