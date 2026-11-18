#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <locale.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Очистка буфера ввода при ошибочном вводе символов
void clearInputBuffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}

// Задание 1 (Вариант 1): проверка деления m на n нацело
void task1(void) {
    int m, n;
    printf("\n--- Задание 1 (Вариант 1) ---\n");
    printf("Введите два целых числа m и n через пробел: ");
    if (scanf("%d %d", &m, &n) != 2) {
        printf("Ошибка: введены некорректные данные.\n");
        clearInputBuffer();
        return;
    }

    if (n == 0) {
        printf("Ошибка: деление на ноль невозможно.\n");
    }
    else if (m % n == 0) {
        printf("Число %d делится на %d нацело. Частное от деления: %d\n", m, n, m / n);
    }
    else {
        printf("Число %d на %d нацело не делится.\n", m, n);
    }
}

// Задание 2 (Вариант 8): взаимное размещение круга и квадрата по их площадям
void task2(void) {
    double sCircle, sSquare;
    printf("\n--- Задание 2 (Вариант 8) ---\n");
    printf("Введите площадь круга и площадь квадрата через пробел: ");
    if (scanf("%lf %lf", &sCircle, &sSquare) != 2) {
        printf("Ошибка: введены некорректные данные.\n");
        clearInputBuffer();
        return;
    }

    if (sCircle <= 0.0 || sSquare <= 0.0) {
        printf("Ошибка: площади фигур должны быть положительными числами.\n");
        return;
    }

    // Диаметр круга d = 2 * sqrt(S_круга / pi)
    double diameter = 2.0 * sqrt(sCircle / M_PI);
    // Сторона квадрата a = sqrt(S_квадрата), диагональ D = a * sqrt(2)
    double side = sqrt(sSquare);
    double diagonal = side * sqrt(2.0);
    const double eps = 1e-9;

    printf("Диаметр круга: %.10g, сторона квадрата: %.10g, диагональ квадрата: %.10g\n",
        diameter, side, diagonal);

    // а) Круг уместится в квадрате, если его диаметр <= стороны квадрата
    if (diameter <= side + eps) {
        printf("а) Да, круг уместится в квадрате.\n");
    }
    else {
        printf("а) Нет, круг не уместится в квадрате.\n");
    }

    // б) Квадрат уместится в круге, если его диагональ <= диаметра круга
    if (diagonal <= diameter + eps) {
        printf("б) Да, квадрат уместится в круге.\n");
    }
    else {
        printf("б) Нет, квадрат не уместится в круге.\n");
    }
}

// Задание 3 (Вариант 27): замена меньшего и большего из двух неравных чисел
void task3(void) {
    double a, b;
    printf("\n--- Задание 3 (Вариант 27) ---\n");
    printf("Введите два неравных вещественных числа a и b через пробел: ");
    if (scanf("%lf %lf", &a, &b) != 2) {
        printf("Ошибка: введены некорректные данные.\n");
        clearInputBuffer();
        return;
    }

    if (fabs(a - b) < 1e-9) {
        printf("Ошибка: по условию числа a и b не должны быть равны друг другу.\n");
        return;
    }

    double halfSum = (a + b) / 2.0;
    double doubleProd = 2.0 * a * b;

    if (a < b) {
        a = halfSum;
        b = doubleProd;
    }
    else {
        b = halfSum;
        a = doubleProd;
    }

    printf("Результат после замены: a = %.10g, b = %.10g\n", a, b);
}

// Задание 4 (Вариант 64): вычисление значения выражения u
void task4(void) {
    double x, y, z;
    printf("\n--- Задание 4 (Вариант 64) ---\n");
    printf("Введите три вещественных числа x, y, z через пробел: ");
    if (scanf("%lf %lf %lf", &x, &y, &z) != 3) {
        printf("Ошибка: введены некорректные данные.\n");
        clearInputBuffer();
        return;
    }

    // Поиск максимума и минимума среди x, y, z
    double mx = x;
    if (y > mx) mx = y;
    if (z > mx) mx = z;

    double mn = x;
    if (y < mn) mn = y;
    if (z < mn) mn = z;

    if (fabs(mn) < 1e-12) {
        printf("Ошибка: min(x, y, z) = 0, деление на ноль в знаменателе невозможно.\n");
        return;
    }

    double denom = sin(2.0 * x) + (mx / mn);
    if (fabs(denom) < 1e-12) {
        printf("Ошибка: знаменатель выражения равен нулю, деление невозможно.\n");
        return;
    }

    double numer = mx * mx - pow(2.0, x) * mn;
    double u = numer / denom;

    printf("max(x, y, z) = %.10g, min(x, y, z) = %.10g\n", mx, mn);
    printf("Значение выражения u = %.10g\n", u);
}

// Задание 5 (Вариант 12): квадрат двузначного числа и учетверённая сумма кубов его цифр
void task5(void) {
    int n;
    printf("\n--- Задание 5 (Вариант 12) ---\n");
    printf("Введите двузначное целое число: ");
    if (scanf("%d", &n) != 1) {
        printf("Ошибка: введены некорректные данные.\n");
        clearInputBuffer();
        return;
    }

    int absN = abs(n);
    if (absN < 10 || absN > 99) {
        printf("Ошибка: число %d не является двузначным.\n", n);
        return;
    }

    int d1 = absN / 10; // Первая цифра (десятки)
    int d2 = absN % 10; // Вторая цифра (единицы)

    int square = n * n;
    int quadCubes = 4 * (d1 * d1 * d1 + d2 * d2 * d2);

    printf("Квадрат числа: %d^2 = %d\n", n, square);
    printf("Учетверённая сумма кубов цифр: 4 * (%d^3 + %d^3) = %d\n", d1, d2, quadCubes);

    if (square == quadCubes) {
        printf("Ответ положительный: значения равны.\n");
    }
    else {
        printf("Ответ отрицательный: значения не равны.\n");
    }
}

// Задание 6 (Вариант 103): преобразование трёх попарно различных чисел X, Y, Z
void task6(void) {
    double x, y, z;
    printf("\n--- Задание 6 (Вариант 103) ---\n");
    printf("Введите три попарно различных вещественных числа X, Y, Z через пробел: ");
    if (scanf("%lf %lf %lf", &x, &y, &z) != 3) {
        printf("Ошибка: введены некорректные данные.\n");
        clearInputBuffer();
        return;
    }

    const double eps = 1e-9;
    if (fabs(x - y) < eps || fabs(x - z) < eps || fabs(y - z) < eps) {
        printf("Ошибка: по условию числа X, Y, Z должны быть попарно различными.\n");
        return;
    }

    if (x + y + z < 1.0) {
        // Сумма меньше 1: наименьшее из трёх заменяем полусуммой двух других
        if (x < y && x < z) {
            x = (y + z) / 2.0;
        }
        else if (y < x && y < z) {
            y = (x + z) / 2.0;
        }
        else {
            z = (x + y) / 2.0;
        }
    }
    else {
        // Иначе: меньшее из X и Y заменяем полусуммой двух оставшихся
        if (x < y) {
            x = (y + z) / 2.0;
        }
        else {
            y = (x + z) / 2.0;
        }
    }

    printf("Новые значения: X = %.10g, Y = %.10g, Z = %.10g\n", x, y, z);
}

// Задание 7 (Вариант 4): определение возраста человека (полных лет)
void task7(void) {
    int birthYear, birthMonth, currYear, currMonth;
    printf("\n--- Задание 7 (Вариант 4) ---\n");
    printf("Введите год и номер месяца рождения (1-12) через пробел: ");
    if (scanf("%d %d", &birthYear, &birthMonth) != 2) {
        printf("Ошибка: введены некорректные данные.\n");
        clearInputBuffer();
        return;
    }

    printf("Введите текущий год и номер текущего месяца (1-12) через пробел: ");
    if (scanf("%d %d", &currYear, &currMonth) != 2) {
        printf("Ошибка: введены некорректные данные.\n");
        clearInputBuffer();
        return;
    }

    if (birthMonth < 1 || birthMonth > 12 || currMonth < 1 || currMonth > 12) {
        printf("Ошибка: номер месяца должен быть в диапазоне от 1 до 12.\n");
        return;
    }

    if (birthYear > currYear || (birthYear == currYear && birthMonth > currMonth)) {
        printf("Ошибка: дата рождения не может быть позже текущей даты.\n");
        return;
    }

    int age = currYear - birthYear;
    // При совпадении месяцев (currMonth == birthMonth) считаем, что прошёл полный год
    if (currMonth < birthMonth) {
        age--;
    }

    const char* word = "лет";
    if (age % 100 < 11 || age % 100 > 14) {
        if (age % 10 == 1) word = "год";
        else if (age % 10 >= 2 && age % 10 <= 4) word = "года";
    }

    printf("Возраст человека: %d %s.\n", age, word);
}

// Задание 8 (Вариант 60): ближайшая точка к a на оси OX
void task8(void) {
    double a, b, c;
    printf("\n--- Задание 8 (Вариант 60) ---\n");
    printf("Введите координаты трёх точек a, b, c на оси OX через пробел: ");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        printf("Ошибка: введены некорректные данные.\n");
        clearInputBuffer();
        return;
    }

    double distB = fabs(b - a);
    double distC = fabs(c - a);
    const double eps = 1e-9;

    if (fabs(distB - distC) < eps) {
        printf("Точки b и c находятся на одинаковом расстоянии от точки a (расстояние = %.10g).\n", distB);
    }
    else if (distB < distC) {
        printf("Точка b (%.10g) расположена ближе к точке a (%.10g), расстояние = %.10g.\n", b, a, distB);
    }
    else {
        printf("Точка c (%.10g) расположена ближе к точке a (%.10g), расстояние = %.10g.\n", c, a, distC);
    }
}

// Задание 9 (Вариант 51): проверка чётности двух целых чисел
void task9(void) {
    int a, b;
    printf("\n--- Задание 9 (Вариант 51) ---\n");
    printf("Введите два целых числа через пробел: ");
    if (scanf("%d %d", &a, &b) != 2) {
        printf("Ошибка: введены некорректные данные.\n");
        clearInputBuffer();
        return;
    }

    bool evenA = (a % 2 == 0);
    bool evenB = (b % 2 == 0);

    if (evenA && evenB) {
        printf("Оба числа (%d и %d) являются чётными.\n", a, b);
    }
    else if (!evenA && !evenB) {
        printf("Оба числа (%d и %d) являются нечётными.\n", a, b);
    }
    else if (evenA) {
        printf("Первое число (%d) — чётное, второе число (%d) — нечётное.\n", a, b);
    }
    else {
        printf("Первое число (%d) — нечётное, второе число (%d) — чётное.\n", a, b);
    }
}

// Задание 10 (Вариант 96): взаимное расположение двух прямоугольников
void task10(void) {
    double x1, y1, w1, h1;
    double x2, y2, w2, h2;

    printf("\n--- Задание 10 (Вариант 96) ---\n");
    printf("Введите x1, y1 (левый нижний угол) и ширину, высоту первого прямоугольника: ");
    if (scanf("%lf %lf %lf %lf", &x1, &y1, &w1, &h1) != 4) {
        printf("Ошибка: введены некорректные данные.\n");
        clearInputBuffer();
        return;
    }

    printf("Введите x2, y2 (левый нижний угол) и ширину, высоту второго прямоугольника: ");
    if (scanf("%lf %lf %lf %lf", &x2, &y2, &w2, &h2) != 4) {
        printf("Ошибка: введены некорректные данные.\n");
        clearInputBuffer();
        return;
    }

    if (w1 <= 0.0 || h1 <= 0.0 || w2 <= 0.0 || h2 <= 0.0) {
        printf("Ошибка: длины сторон прямоугольников должны быть положительными.\n");
        return;
    }

    double x1Max = x1 + w1, y1Max = y1 + h1;
    double x2Max = x2 + w2, y2Max = y2 + h2;
    const double eps = 1e-9;

    // а) Все точки первого прямоугольника принадлежат второму
    bool firstInSecond = (x1 >= x2 - eps) && (x1Max <= x2Max + eps) &&
        (y1 >= y2 - eps) && (y1Max <= y2Max + eps);

    // Проверка обратного включения: второй в первом
    bool secondInFirst = (x2 >= x1 - eps) && (x2Max <= x1Max + eps) &&
        (y2 >= y1 - eps) && (y2Max <= y1Max + eps);

    // б) Все точки одного из прямоугольников принадлежат другому
    bool oneInAnother = firstInSecond || secondInFirst;

    // в) Прямоугольники пересекаются (имеют хотя бы одну общую точку)
    bool intersect = (x1 <= x2Max + eps) && (x2 <= x1Max + eps) &&
        (y1 <= y2Max + eps) && (y2 <= y1Max + eps);

    printf("а) Все точки первого прямоугольника принадлежат второму: %s.\n",
        firstInSecond ? "Да" : "Нет");
    printf("б) Все точки одного из прямоугольников принадлежат другому: %s.\n",
        oneInAnother ? "Да" : "Нет");
    printf("в) Прямоугольники пересекаются: %s.\n",
        intersect ? "Да" : "Нет");
}

int main(void) {
    setlocale(LC_ALL, "ru");

    int choice;
    do {
        printf("\n====================================================\n");
        printf(" Лабораторная работа: Разветвляющиеся алгоритмы\n");
        printf(" Номер в списке: K = 15\n");
        printf("====================================================\n");
        printf("  1. Задание 1  (Вариант 1)   — Делимость m на n\n");
        printf("  2. Задание 2  (Вариант 8)   — Круг и квадрат\n");
        printf("  3. Задание 3  (Вариант 27)  — Замена чисел a и b\n");
        printf("  4. Задание 4  (Вариант 64)  — Вычисление выражения u\n");
        printf("  5. Задание 5  (Вариант 12)  — Двузначное число и кубы цифр\n");
        printf("  6. Задание 6  (Вариант 103) — Преобразование X, Y, Z\n");
        printf("  7. Задание 7  (Вариант 4)   — Возраст человека\n");
        printf("  8. Задание 8  (Вариант 60)  — Ближайшая точка на оси OX\n");
        printf("  9. Задание 9  (Вариант 51)  — Чётность двух чисел\n");
        printf(" 10. Задание 10 (Вариант 96)  — Два прямоугольника\n");
        printf(" 11. Выполнить все 10 заданий последовательно\n");
        printf("  0. Выход\n");
        printf("----------------------------------------------------\n");
        printf("Выберите пункт меню: ");

        if (scanf("%d", &choice) != 1) {
            printf("Ошибка ввода! Введите номер пункта меню от 0 до 11.\n");
            clearInputBuffer();
            choice = -1;
            continue;
        }

        switch (choice) {
        case 1:  task1();  break;
        case 2:  task2();  break;
        case 3:  task3();  break;
        case 4:  task4();  break;
        case 5:  task5();  break;
        case 6:  task6();  break;
        case 7:  task7();  break;
        case 8:  task8();  break;
        case 9:  task9();  break;
        case 10: task10(); break;
        case 11:
            task1();
            task2();
            task3();
            task4();
            task5();
            task6();
            task7();
            task8();
            task9();
            task10();
            break;
        case 0:
            printf("Завершение работы программы.\n");
            break;
        default:
            printf("Неверный пункт меню. Выберите число от 0 до 11.\n");
            break;
        }
    } while (choice != 0);

    return 0;
}