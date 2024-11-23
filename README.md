Федеральное государственное автономное образовательной учреждение

высшего образования

**НАЦИОНАЛЬНЫЙ ИССЛЕДОВАТЕЛЬСКИЙ УНИВЕРСИТЕТ**

**«ВЫСШАЯ ШКОЛА ЭКОНОМИКИ»**

**Московский институт электроники и математики имени А. Н. Тихонова**

## Лабораторная работа №2  
**Урок информатики в 9А**  
по дисциплине "Языки программирования"  

**Студент группы СКБ241**: Колчевская Мария Александровна  
**Преподаватель**: Рогачёва Ольга Алексеевна  

---

### Описание программы

Данная лабораторная работа реализует решение математической задачи, связанной с вычислением сложной формулы, включающей суммы, факториалы, двойные факториалы и дробные выражения. Программа предназначена для расчета результата по заданному числу \( y \), используя указанные формулы. Она демонстрирует навыки работы с языком программирования C++, включая обработку исключений, вычисления с использованием рекурсивных алгоритмов и тестирование функциональности.

### Формулировка задачи

Необходимо вычислить значение следующей формулы:  

\[
\frac{7t(0.25) + 2t(1 + y)}{6 - t(y^2 - 1)}
\]

где  
\[
t(x) = \frac{\sum_{k=0}^{10} \frac{x^{2k+1}}{(2k+1)!!}}{\sum_{k=0}^{10} \frac{x^{2k}}{(2k)!!}}
\]

Программа принимает на вход число \( y \) и выводит результат вычислений.

---

### Структура программы

Программа состоит из следующих компонентов:

- **Ввод/вывод**: 
  Пользователь вводит значение \( y \), программа выводит результат или сообщение об ошибке в случае некорректного ввода.
- **Функция двойного факториала**: 
  Реализована функция для вычисления двойного факториала \( n!! \), с проверкой на переполнение.
- **Функция вычисления t(x)**: 
  Рассчитывает значение \( t(x) \) с использованием указанных сумм.
- **Основная формула**: 
  Вычисление значения основной формулы на основе заданного \( y \).
- **Обработка ошибок**: 
  Учтены ситуации деления на ноль, переполнения и другие ошибки при вычислениях.
- **Тесты**: 
  Программа содержит встроенные тесты для проверки правильности основных функций.

---

### Используемые функции

1. **`doubleFactorial`**  
   Функция вычисляет двойной факториал числа.  
   Пример: \( 5!! = 5 \times 3 \times 1 = 15 \).  

2. **`calculateT`**  
   Функция вычисляет значение \( t(x) \), используя суммы в числителе и знаменателе.  

3. **`calculateFormula`**  
   Функция вычисляет основную формулу на основе введенного значения \( y \).  

4. **`runTests`**  
   Набор тестов для проверки корректности функций. Использует библиотеку `assert`.  

---

### Пример работы программы

Программа предлагает пользователю ввести значение \( y \) и вычисляет результат:

Введите y (или 'q' для выхода): 1
Результат: 1.81542

Введите y (или 'q' для выхода): -2
Результат: -0.73157

Введите y (или 'q' для выхода): q
Пока!

При некорректном вводе или переполнении программа выдает соответствующие сообщения об ошибках.

---

### Возможности программы

- Вычисление значений сложных формул с использованием C++.
- Обработка исключений, таких как переполнение, деление на ноль, некорректный ввод.
- Тестирование функций с использованием `assert`.
- Поддержка локали для русского языка.

---

### Заключение

Лабораторная работа демонстрирует навыки работы с языком C++, включая написание математических функций, обработку исключений, работу с вводом/выводом и тестирование. Программа способна решать поставленную задачу с учетом всех возможных ошибок и ограничений.

Работа выполнена в рамках курса "Языки программирования" и соответствует требованиям для разработки лабораторных заданий.
