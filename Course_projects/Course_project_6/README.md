 # Отчёт по курсовой работе №6 по курсу “Фундаментальная информатика”

Студент группы: М80-108Б-22 Горюнов Даниил Владимирович, № по списку 4 

Контакты e-mail: dania.goryunow2013@yandex.ru

Работа выполнена: «2» июня 2023г.

Преподаватель: асп. каф. 806 Сахарин Никита Александрович

Входной контроль знаний с оценкой _______________________

Отчет сдан «2» июня 2023 г., итоговая оценка ______

Подпись преподавателя ___________


## 1. Тема
Обработка последовательной файловой структуры на языке Си
## 2. Цель работы
Разработать последовательную структуру данных для представления простейшей базы данных на файлах в СП Си в соответствии с заданным вариантом.
## 3. Задание (вариант № 4)
Составить программу генерации внешнего
нетекстового файла заданной структуры, содержащего представительный набор записей.
Распечатать содержимое сгенерированного файла в виде таблицы и выполнить над ним заданное действие для
запроса `p` и распечатать результат.

Действие по выборке данных из файла оформить в виде отдельной программы с параметрами запроса,
вводимыми из стандартного входного текстового файла, или получаемыми из командной строки UNIX.
Второй способ задания параметров обязателен для работ, оцениваемых на хорошо и отлично. Параметры
задаются с помощью ключей `–f [name]` (имя обрабатываемого файла) или `–p [parameter]` (параметры конкретного варианта
задания). Получение параметров из командной строки производится с помощью стандартных библиотечных
функций `argс` и `argv`.

Cтруктуры данных и константы, совместно используемые программами, следует вынести в отдельный
заголовочный файл.

В процессе отладки и тестирования рекомендуется использовать команды обработки текстовых файлов
ОС UNIX и переадресацию ввода-вывода. Сгенерированные и отформатированные тестовые данные
необходимо заранее поместить в текстовые файлы и распечатывать при протоколировании. Рекомендуется
подобрать реальные или правдоподобные тестовые данные. Число наборов тестовых данных должно быть не
менее трёх. Имя файла с бинарными данными является обязательным параметром второй программы.

**Содержимое и структура файла:**

Сведения о составе комплектующих личных ПЭВМ в студенческой группе: фамилия владельца, число и тип процессоров, объём памяти, тип видеоконтроллера (встроенный, внешний, видео-шина) и объём видеопамяти, тип (SAS/SATA), число и ёмкость винчестеров, количество интегрированных контроллеров и внешних (периферийных) устройств, операционная система.

**Действие**

Отпечатать список студентов, компьютеры которых нуждаются в апгрейде.


## 4. Оборудование:
Процессор: Apple M1

ОП: 8192 МБ

НМД: 512 ГБ  

Монитор: Retina c диагональю 13,3 дюйма разрешение 2560×1600 пикселей (227 пикселей)
## 5. Программное обеспечение:
Операционная система семейства: MacOS 

Система программирования: XCode версия — 
## 6. Идея, метод, алгоритм решения задачи (в формах: словесной, псевдокода, графической [блок-схема, диаграмма, рисунок, таблица] или формальные спецификации с пред- и постусловиями)
Для работы с бинарным файлом требуется два исполняемых файла: `pdump` и `pselect`. Первый принимает имя файла, в который будет дописано бинарное представление структуры из Си, а далее запрашивается пользовательский ввод полей структуры. Если хотя бы одно поле введено некоректно, то программа завершается аварийно и ничего не сохраняет в файл. Вторая программа требует два ключа с параметрами: `-f [filename]` и `-p [parameter]` и соовершает запрос к бинарнорму файлу `filename` (созданного прошлой утилитой) c параметром `parameter`.
## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию]. 
```c:/Course_projects/Course_project_6/kp6_1.c
#include <stdio.h>
#include "fields.h"
#include <stdbool.h>
#include <string.h>

char string_to_int(char* str){
    int intic = 0;
    for (int i = 0; i < (strlen(str)/sizeof(char)); ++i){
        intic = str[i] - '0' + intic * 10;
    }
    return intic;
}

int comps_powerful(comp c){
    int n = 0;
    if (c.cores > 4) n++;
    if (c.memory_size > 256) n++;
    if (c.memory > 4) n++;
    if (c.vinchesters > 4) n++;
    return n;
}


int main(int argc, char* argv[]){
    if (argc!=4){
        fprintf(stderr, "Wrong number of args!\n");
        return 1;
    }
    int n1;
    FILE* file = fopen(argv[1], "rb");
    if (file == NULL){
        fprintf(stderr, "Can't open file!\n");
        return 1;
    }
    if (strcmp("-p", argv[2]) == 0){
        n1 = string_to_int(argv[3]);
    } else{ 
        fprintf(stderr, "Write -p parameter!\n");
        return 3;
    }
    int n;
    if (fread(&n, sizeof(int), 1, file) != 1) {
        fprintf(stderr, "Read number of elems error!\n");
        return 1;
    }
    comp c;
    int power[n], min = __INT_MAX__;
    fseek(file, sizeof(int), SEEK_SET);
    for (int i = 0; i < n; i++) {
        if (fread(&c, sizeof(comp), 1, file) != 1) {
            fprintf(stderr, "Read elem error!\n");
            return 1;
        }
        power[i] = comps_powerful(c);
        if (power[i] < min)
            min = comps_powerful(c);
    }
    int cnt = 0;
    while (n1 > cnt){
        fseek(file, sizeof(int), SEEK_SET);
        for (int i = 0; i < n; i++) {
            fread(&c, sizeof(comp), 1, file);
            if (power[i] == min) {
                cnt++;
                printf("%s ", c.surname);
            }
        }
        min++;
    }
    return 0;
}
```
Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.  
Подпись преподавателя _____________________
## 8. Распечатка протокола 
```
admin@MacBook-Pro-2 Course_project_6 % clang -std=c99 -Wall -pedantic kp6_2.c
admin@MacBook-Pro-2 Course_project_6 % ./a.out bin.bin -p 1                  
Larin %                                     
admin@MacBook-Pro-2 Course_project_6 % ./a.out bin.bin -p 4                  
Larin Boglaev Volkov Dautov Zhdanov Zhuravlyov Ivanov Kolomytseva Medvedev Nosov Saraykin Sviridov Filatov %       
```
## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 02.06.23 | 18:00 | Башня | - | - |
## 10. Замечания автора по существу работы — Написание команд для отработки навыков работы в ОС UNIX.
[Контест](https://codeforces.com/contest/1811/submission/200738109)

[Дорешка](https://codeforces.com/contest/1811/submission/208261647)
## 11. Выводы
После выполнения работы, были получены навыки обработки бинарных файлов в Си, а так же строгой обработки ползовательского ввода.
Недочёты при выполнении задания могут быть устранены следующим образом: —

Подпись студента _________________