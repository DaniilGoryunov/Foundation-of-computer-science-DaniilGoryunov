 # Отчёт по лабораторной работе №13 по курсу “Фундаментальная информатика”

Студент группы: М80-108Б-22 Горюнов Даниил Владимирович, № по списку 4 

Контакты e-mail: dania.goryunow2013@yandex.ru

Работа выполнена: «8» декабря 2022 г.

Преподаватель: асп. каф. 806 Сахарин Никита Александрович

Входной контроль знаний с оценкой _______________________

Отчет сдан «8» декабря 2022 г., итоговая оценка ______

Подпись преподавателя ___________


## 1. Тема
Множества
## 2. Цель работы
В соответствии с вариантом задания составить программу проверки характеристик введённых последовательностей слов и печати развёрнутого ответа.
## 3. Задание (вариант № 4)
Подсчитать количество полнотетрадных (со всеми необходимыми ведущими нулями) двоичнокодированных десятичных чисел (BCD - Binarv Coded Decimal).
## 4. Оборудование:
Процессор: Apple M1
ОП: 8192 МБ
НМД: 512 ГБ  
Монитор: Retina c диагональю 13,3 дюйма разрешение 2560×1600 пикселей (227 пикселей)
## 5. Программное обеспечение:
Операционная система семейства: MacOS 
Система программирования: XCode версия — 
## 6. Идея, метод, алгоритм решения задачи (в формах: словесной, псевдокода, графической [блок-схема, диаграмма, рисунок, таблица] или формальные спецификации с пред- и постусловиями)
• Изучить принципы работы с битовыми масками в С
• Разобраться с поставленной задачей
• Найти решение с помощью программы на языке С
•	Скомпилировать программу
•	Запустить программу
## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию]. 
```c:/Lab-13/main.c
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define CONSONANTS (1u << ('b' - 'a') | 1u << ('c' - 'a') | 1u << ('d' - 'a') | 1u << ('f' - 'a') | 1u << ('g' - 'a') | 1u << ('h' - 'a') | 1u << ('j' - 'a') | 1u << ('k' - 'a') | 1u << ('l' - 'a') | 1u << ('m' - 'a') | 1u << ('n' - 'a') | 1u << ('p' - 'a') | 1u << ('q' - 'a') | 1u << ('r' - 'a') | 1u << ('s' - 'a') | 1u << ('t' - 'a') | 1u << ('v' - 'a') | 1u << ('w' - 'a') | 1u << ('x' - 'a') | 1u << ('z' - 'a'))

typedef enum {
    INSIDE,
    OUTSIDE
} State;

State get_state(char s) {
    return (s == ' ') || (s == '\n') || (s == ',') || (s == EOF) ? OUTSIDE : INSIDE;
}

bool common_cons(void) {
    State state;
    unsigned int pool_un=0;
    for (char s = getchar(); s != EOF; s = getchar()) {
        state = get_state(s);
        switch (state) {
            case INSIDE:
                if (CONSONANTS & 1u << (s - 'a')) {
                    if (pool_un & 1u << (s - 'a')){
                        return true;
                    } else{
                        pool_un=pool_un|1u << (s-'a');
                    }
                }
                break;
            case OUTSIDE:
                pool_un=0;
                break;
        }
    }
    return false;
}


int main(void) {
    printf("%d\n", common_cons());
    return 0;
}
```
Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.  
Подпись преподавателя _____________________
## 8. Распечатка протокола 
```
Dfgkhlj;k

Ffffff
45678uhbgfdefyui
%tcfygvbh%

1
Program ended with exit code: 0
```

```
fgh 12345vbhj


@gf@

0
Program ended with exit code: 0
```
## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 08.12.22 | 18:00 | Выполнение лабораторной работы | - | - |
## 10. Замечания автора по существу работы — Написание команд для отработки навыков работы в ОС UNIX.
```

```
## 11. Выводы
Была написана программа на языке на Си, выполняющая указанное вариантом действие над значениями в целом типе данных. В результате выполнения работы, были приобретены навыки для работы с числами в целом типе данных.
Недочёты при выполнении задания могут быть устранены следующим образом: —

Подпись студента _________________




