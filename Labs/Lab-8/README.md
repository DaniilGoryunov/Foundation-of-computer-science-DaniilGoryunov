# Отчёт по лабораторной работе №8 по курсу “Фундаментальная информатика”

Студент группы: М80-108Б-22 Горюнов Даниил Владимирович, № по списку 4 

Контакты e-mail: dania.goryunow2013@yandex.ru

Работа выполнена: «7» ноября 2022 г.

Преподаватель: асп. каф. 806 Сахарин Никита Александрович

Входной контроль знаний с оценкой _______________________

Отчет сдан «8» ноября 2022 г., итоговая оценка ______

Подпись преподавателя ___________


## 1. Тема
Системы програмирования на языке С
## 2. Цель работы
Изучить конкретную систему программирования на Си и получить навыки подготовки текстов и отладки программ
## 3. Задание (вариант № —)
## 4. Оборудование:
Процессор: Apple M1
ОП: 8192 МБ
НМД: 512 ГБ  
Монитор: Retina c диагональю 13,3 дюйма разрешение 2560×1600 пикселей (227 пикселей)
## 5. Программное обеспечение:
Операционная система семейства: MacOS 
Система программирования: Xcode версия — 
## 6. Идея, метод, алгоритм решения задачи (в формах: словесной, псевдокода, графической [блок-схема, диаграмма, рисунок, таблица] или формальные спецификации с пред- и постусловиями)
•	Установить и настроить xcode
•	Разобраться с опрделенными механикамти языка С 
•	Скомпилировать программу
•	Запустить программу
## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию]. 
```c:/Lab-8/main.c
#include <stdio.h>
int main() {
    int x , y, i;
    printf("Введите первое число: ");
    scanf("%d",&x);
    printf("Введите второе число: ");
    scanf("%d",&y);
    printf("Выберите операцию сложения (1), вычитания (2), умножения (3) или деления (4): ");
    scanf("%d",&i);
    if(i==1)
        printf("%d + %d = %d \n",x,y,x+y);
    if(i==2)
        printf("%d - %d = %d \n",x,y,x-y);
    if(i==3){
        long int res;
        res=x*y;
        printf("%d * %d = %d \n",x,y,res);
    }
    if(i==4){
        float x1,y1,res;
        x1=x;
        y1=y;
        res=x1/y1;
        printf("%f./%f. = %f \n",x1,y1,res);
    }
    return 0;
}
``` 
Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.  
Подпись преподавателя _____________________
## 8. Распечатка протокола 
``` 
Введите первое число: 34567
Введите второе число: 45678
Выберите операцию сложения (1), вычитания (2), умножения (3) или деления (4): 3
34567 * 45678 = 1578951426 
Program ended with exit code: 0
```
## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 08.10.22 | 13:00 | Выполнение лабораторной работы | - | - |
## 10. Замечания автора по существу работы — Написание команд для отработки навыков работы в ОС UNIX.
```

```
## 11. Выводы
Были изучены основы работы с компилятором Xcode: установка, компиляция, выполнение программ. Было выяснено, что Emacs — наиболее подходящий текстовый редактор для работы со сторонними компиляторами: установка и обозначение проходят быстро, а интегрированная командная строка значительно упрощает работу с программой.

Недочёты при выполнении задания могут быть устранены следующим образом: —

Подпись студента _________________


