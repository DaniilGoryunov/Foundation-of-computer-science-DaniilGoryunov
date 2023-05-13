#include <stdio.h>
#include "sort.h"

void getLine(char *str, const int size)         // Функция добавления ЗНАЧЕНИЯ элемента в очередь
{
    int cnt = 0, ch;                            // Переменная, определяющая число элементов во введенной строке

    while ((ch = getchar()) != '\n' && cnt < size - 1)  
        str[cnt++] = ch;                           

    str[cnt] = '\0';
}

void print_menu(void) {
    printf("\nВыберите действие: \n");
    printf("1) Добавить элемент\n");
    printf("2) Удалить элемент\n");
    printf("3) Размер очереди\n");
    printf("4) Сортировка\n");
    printf("5) Печать\n");
    printf("0) Выход\n");
}

int main(void)
{
    const int N = 10;                            // Размер очереди (число элементов)
    int action;                                  // Аргумент конечного автомата
    char tmpCh;                                  // Используется для добавления элемента в очередь
    Udt udt;                                     // Структура очереди
    Item item;                                   // Структура элемента очереди

    udtCreate(&udt, N);                          // Функция создания очереди

    print_menu();

    while ((action = getchar()) != EOF) {        
        if (action == '\n') continue;
        switch (action) {
            case '1':                               
                printf("Введите ключ: ");
                scanf("%d", &item._key);           // Считывание ключа элемента очереди
                scanf("%c", &tmpCh);          
                printf("Введите Строку: ");
                getLine(item._val, sizeof(item._val));  // Считывание значение элемента (строки) очереди

                if (udtPush(&udt, item))              // Если постановка элемента в очередь прошло успешно, то вывод
                    printf("Элемент с ключом %d и строкой '%s' добавлен успешно\n", item.
                    _key, item._val);
                else
                    printf("Очередь заполнена\n");
                break;
            case '2':                    
                if (udtSize(&udt) > 0)          // Проверка, что очередь не пуста
                {
                    item = udtFront(&udt);      // Приравниваем item первый элемент очереди

                    udtPop(&udt);  

                    printf("Элемент с ключом %d и строкой '%s' удален успешно\n", item._key, item._val);   // Вывод
                }
                else
                    printf("Очередь пуста\n");
            case '3':                              
                printf("Размер очереди: %d\n", udtSize(&udt));  
                break;
            case '4':                            
                if (udtSize(&udt) > 1) {            // Проверка, что очередь не пуста
                    udtSort(&udt);
                }
                else
                    printf("В очереди недостаточно элементов для сортировки\n");
                break;
            case '5':                            
                if (udtSize(&udt) > 0)          // Проверка, что очередь не пуста
                {
                    printf("Очередь:\n");

                    udtPrint(&udt); 
                }
                else
                    printf("Очередь пуста\n");
                break;
            case '0':
                return 0;
            default:
                printf("Некоректный номер операции\n");
                break;
        }
        print_menu();
    }
    udtDestroy(&udt);                           // Функция уничтожения ВСЕЙ очереди
    return 0;
}
