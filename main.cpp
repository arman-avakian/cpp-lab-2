#include <iostream>
#include <cmath>
#include <sstream>
#include <string>
#include <limits>
#include <cassert> // Добавлено для использования assert

// Функция для превращения строки в число
double stringToDouble(const std::wstring& str) {
    std::wstringstream wss(str);
    double num;
    wss >> num;
    if (wss.fail()) {
        throw std::invalid_argument("Неправильный ввод");
    }
    return num;
}

// Функция для вычисления двойного факториала
long long doubleFactorial(int n) {
    long long result = 1;
    for (int i = n; i > 0; i -= 2) {
        result *= i;
        // Проверяем, не переполнилось ли число
        if (result < 0) { // Простая проверка на переполнение
            throw std::overflow_error("Переполнение при вычислении двойного факториала");
        }
    }
    return result;
}

// Функция для вычисления t(x)
double calculateT(double x) {
    double num = 0, denom = 0;
    for (int k = 0; k <= 10; ++k) {
        double termNum = pow(x, 2 * k + 1) / doubleFactorial(2 * k + 1);
        double termDenom = pow(x, 2 * k) / doubleFactorial(2 * k);

        // Проверяем, нормальные ли числа
        if (!std::isfinite(termNum) || !std::isfinite(termDenom)) {
            throw std::overflow_error("Переполнение при вычислении t(x)");
        }

        num += termNum;
        denom += termDenom;
    }

    if (denom == 0) {
        throw std::domain_error("Деление на ноль в t(x)");
    }

    return num / denom;
}

// Функция для основной формулы
double calculateFormula(double y) {
    double t025 = calculateT(0.25);
    double tY = calculateT(pow(y, 2) - 1);

    if (!std::isfinite(tY)) {
        throw std::overflow_error("Переполнение в t(y^2 - 1)");
    }

    double top = 7 * t025 + 2 * tY * (1 + y);
    double bottom = 6 - tY;

    if (bottom == 0) {
        throw std::domain_error("Деление на ноль в основной формуле");
    }

    return top / bottom;
}

// Функция для тестов
void runTests() {
    // Тест двойного факториала
    assert(doubleFactorial(5) == 15); // 5!! = 5 * 3 * 1
    assert(doubleFactorial(6) == 48); // 6!! = 6 * 4 * 2

    // Тест функции t(x)
    assert(std::abs(calculateT(0) - 0) < 1e-6); // t(0) = 0
    // Приблизительное значение t(0.25)
    assert(std::abs(calculateT(0.25) - 0.255341) < 1e-3);

    // Тест основной формулы
    // При y = 1 ожидаем примерно 1.81542
    assert(std::abs(calculateFormula(1) - 1.81542) < 1e-3);

    std::wcout << L"Все тесты успешно пройдены!\n";
}

int main() {
    // Устанавливаем русскую локаль
    std::locale::global(std::locale("ru_RU.UTF-8"));
    std::wcin.imbue(std::locale());
    std::wcout.imbue(std::locale());

    // Запускаем тесты
    runTests();

    while (true) {
        std::wcout << L"Введите y (или 'q' для выхода): ";
        std::wstring input;
        std::wcin >> input;

        if (input == L"q" || input == L"Q") {
            std::wcout << L"Пока!\n";
            break;
        }

        try {
            double y = stringToDouble(input);
            double res = calculateFormula(y);
            std::wcout << L"Результат: " << res << L"\n";
        }
        catch (const std::invalid_argument&) {
            std::wcout << L"Неправильный ввод. Попробуйте снова.\n";
        }
        catch (const std::overflow_error& e) {
            std::wcout << L"Ошибка: " << e.what() << L"\n";
        }
        catch (const std::domain_error& e) {
            std::wcout << L"Ошибка: " << e.what() << L"\n";
        }

        // Очищаем поток ввода
        std::wcin.clear();
        std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return 0;
}
