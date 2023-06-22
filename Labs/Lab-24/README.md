 # Отчёт по лабораторной работе 24 по курсу “Фундаментальная информатика”

Студент группы: М80-108Б-22 Горюнов Даниил Владимирович, № по списку 4 

Контакты e-mail: dania.goryunow2013@yandex.ru

Работа выполнена: «16» июня 2023г.

Преподаватель: асп. каф. 806 Сахарин Никита Александрович

Входной контроль знаний с оценкой _______________________

Отчет сдан «16» июня 2023 г., итоговая оценка ______

Подпись преподавателя ___________


## 1. Тема
Динамические структуры данных. Обработка деревьев
## 2. Цель работы
Составить программу на Си выполнения заданных преобразований арифметическиз выражений с применением деревьев.
## 3. Задание
 Подсчитать количество переменных, используемых в данном выражении.

## 4. Оборудование:
Процессор: Apple M1

ОП: 8192 МБ

НМД: 512 ГБ  

Монитор: Retina c диагональю 13,3 дюйма разрешение 2560×1600 пикселей (227 пикселей)
## 5. Программное обеспечение:
Операционная система семейства: MacOS

Система программирования: VS code
## 6. Идея, метод, алгоритм решения задачи (в формах: словесной, псевдокода, графической [блок-схема, диаграмма, рисунок, таблица] или формальные спецификации с пред- и постусловиями)

## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию]. 
```c:/Course_projects/Lab-24/sources/main.c
#include "headers/tree.h"
#include "headers/expression.h"
#include "headers/token_vec.h"
#include "headers/tree_stack.h"
#include <stdio.h>
#include <string.h>

bool is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

token_read_result read_token(token_type prev_type, token* out) {
    int c = getchar();
    while (c == ' ') {
        c = getchar();
    }
    if (c >= '0' && c <= '9') {
        ungetc(c, stdin);
        double num;
        scanf("%lf", &num);
        out->type = TOKEN_CONST;
        out->cnst = num;
        return TOKEN_READ_OK;
    }
    else if (c == '(') {
        out->type = TOKEN_BR_L;
        out->oper_assoc = RIGHT;
        out->oper_priority = BR;
        return TOKEN_READ_OK;
    }
    else if (c == ')') {   
        out->type = TOKEN_BR_R;
        out->oper_assoc = RIGHT;
        out->oper_priority = BR;
        return TOKEN_READ_OK;
    }
    else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_') {
        ungetc(c, stdin);
        scanf("%[A-Za-z0-9_]", out->var_name);
        out->type = TOKEN_VAR_NAME;
        return TOKEN_READ_OK;
    }
    else if(is_operator(c)) {
        if (c == '-') {
            if(prev_type == TOKEN_NONE || prev_type == TOKEN_BR_L || prev_type == TOKEN_OPER) {
                out->oper = '~';
                out->oper_priority = HIGH;
                out->oper_assoc = RIGHT;
            }
            else {
                out->oper = '-';
                out->oper_priority = LOW;
                out->oper_assoc = LEFT;
            }
        }
        else {
            out->oper = c;
            if(c == '+') {
                out->oper_priority = LOW;
                out->oper_assoc = LEFT;
            }
            else if(c == '*' || c == '/') {
                out->oper_priority = MIDDLE;
                out->oper_assoc = LEFT;
            }
            else if(c == '^') {
                out->oper_priority = HIGH;
                out->oper_assoc = RIGHT;
            }
        }
        out->type = TOKEN_OPER;
        return TOKEN_READ_OK;
    }
    else if (c == '\n' || c == EOF) {
        out->type = TOKEN_NONE;
        return TOKEN_READ_END;
    }
    else {
        out->type = TOKEN_NONE;
        return TOKEN_READ_ERROR;
    }
}

expr_read_result read_expr(token_vec* out) {
    token cur_token;
    token_type prev_token_type = TOKEN_NONE;
    token_read_result read_res = read_token(prev_token_type, &cur_token);
    while (read_res == TOKEN_READ_OK) {
        tkn_push_back(out, cur_token);
        prev_token_type = cur_token.type;
        read_res = read_token(prev_token_type, &cur_token);
    }
    if (read_res == TOKEN_READ_ERROR) {
        return EXPR_READ_ERROR;
    }
    else {
        return EXPR_READ_OK;
    }
}

void print_vec(token_vec* v) {
    for (int i = 0; i < tkn_get_size(v); i++) {
        token el = tkn_get_el(v, i);
        if (el.type == TOKEN_VAR_NAME) {
            printf("%s ", el.var_name);
        } else if (el.type == TOKEN_CONST) {
            printf("%lf ", el.cnst);
        } else if (el.type == TOKEN_OPER) {
            printf("%c ", el.oper);
        } else if (el.type == TOKEN_BR_L) {
            printf("( ");
        } else if (el.type == TOKEN_BR_R) {
            printf(") ");
        }
    }
    putchar('\n');
}

token_vec make_postfix(token_vec* v) {
    token_vec opstack = tkn_init();
    token_vec list = tkn_init();
    for (int i = 0; i < tkn_get_size(v); i++) {
        token t = tkn_get_el(v, i);
        if (t.type == TOKEN_BR_L) {
            tkn_push_back(&opstack, t);
        } else if (t.type == TOKEN_BR_R) {
            token buf = tkn_pop_back(&opstack);
            while (buf.type != TOKEN_BR_L) {
                tkn_push_back(&list, buf);
                buf = tkn_pop_back(&opstack);
            }
        } else if (t.type == TOKEN_OPER) {
            if (tkn_is_empty(&opstack)) {
                tkn_push_back(&opstack, t);
            } else if (t.oper_assoc == RIGHT) {
                tkn_push_back(&opstack, t);
            } else {
                token buf = tkn_pop_back(&opstack);
                while (t.oper_priority <= buf.oper_priority && !tkn_is_empty(&opstack)) {
                    tkn_push_back(&list, buf);
                    buf = tkn_pop_back(&opstack);
                }
                if (t.oper_priority <= buf.oper_priority) {
                    tkn_push_back(&list, buf);
                } else {
                    tkn_push_back(&opstack, buf);
                }
                tkn_push_back(&opstack, t);
            }
        } else {
            tkn_push_back(&list, t);
        }
    }
    while (!tkn_is_empty(&opstack)) {
        tkn_push_back(&list, tkn_pop_back(&opstack));
    }
    tkn_destroy(&opstack);
    return list;
}

tree postfix_to_tree(token_vec* list) {
    if (tkn_is_empty(list)) {
        return empty_tree();
    }
    tree_stack valstack;
    ts_init(&valstack);
    for (int i = 0; i < tkn_get_size(list); i++) {
        token t = tkn_get_el(list, i);
        if (t.type == TOKEN_OPER) {
            tree r = ts_pop(&valstack);
            tree l = ts_pop(&valstack);
            ts_push(&valstack, build_tree(t, l, r));
        } else {
            tree tr = build_tree(t, empty_tree(), empty_tree());
            ts_push(&valstack, tr);
        }
    }
    tree t = ts_pop(&valstack);
    ts_destroy(&valstack);
    return t;
}

int _num_of_vars(tree expr, token_vec* v) {
    int vars = 0;
    if (is_empty_tree(expr)) {
        return vars;
    }
    if (root_val(expr).type == TOKEN_VAR_NAME) {
        bool is_repeat = false;
        for (int i = 0; i < tkn_get_size(v); i++) {
            token t = tkn_get_el(v, i);
            if (strcmp(root_val(expr).var_name, t.var_name) == 0) {
                is_repeat = true;
            }
        }
        if (!is_repeat) {
            vars++;
            tkn_push_back(v, root_val(expr));
        }
    }
    vars += _num_of_vars(left(expr), v);
    vars += _num_of_vars(right(expr), v);
    return vars;
}

int num_of_vars(tree expr) {
    token_vec v = tkn_init();
    int n = _num_of_vars(expr, &v);
    tkn_destroy(&v);
    return n;
}

int main() {
    token_vec input = tkn_init();
    if (read_expr(&input) == EXPR_READ_ERROR) {
        fprintf(stderr, "Wrong expression!\n");
        return 1;
    }
    print_vec(&input);
    token_vec list = make_postfix(&input);
    print_vec(&list);
    tree expr_t = postfix_to_tree(&list);
    print_tree(expr_t);
    printf("Number of vars: %d\n", num_of_vars(expr_t));
    return 0;
}
```
Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.  
Подпись преподавателя _____________________
## 8. Распечатка протокола 
```
admin@MacBook-Pro-2 build % ./lab24    
7*a+6*b^3^4
7.000000 * a + 6.000000 * b ^ 3.000000 ^ 4.000000 
7.000000 a * 6.000000 b 3.000000 4.000000 ^ ^ * + 
                                        4.000000
                                ^
                                        3.000000
                        ^
                                b
                *
                        6.000000
        +
                        a
                *
                        7.000000
Number of vars: 2
```
## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 10.06.23 | 18:00 | Родимый дом | - | - |
## 10. Замечания автора по существу работы — Написание команд для отработки навыков работы в ОС UNIX.
[Контест](https://codeforces.com/contest/1838/submission/208484614)

[Дорешка](https://codeforces.com/contest/1839/submission/209167788)
## 11. Выводы
Была составлена программа на языке Си для обработки линейного списка заданной организации с отображением на динамические структуры и написана процедура для выполнения нестандартного действия по номеру варианта. Была изучена навигация по списку с применением итераторов. Были приобретены навыки, которые будут полезны для выполнения других лабораторных работ и курсовых проектов.
Недочёты при выполнении задания могут быть устранены следующим образом: —

Подпись студента _________________