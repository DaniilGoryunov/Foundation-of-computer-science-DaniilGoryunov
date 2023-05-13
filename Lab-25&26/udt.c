#include "udt.h"

void udtCreate(Udt *udt, const int size)                         
{
    if (size <= 1)                                                  
        return;

    udt->_data = (UDT_TYPE *)malloc(sizeof(UDT_TYPE) * size);  
    udt->_first = 0;                              
    udt->_size = 0;                                            
    udt->_capacity = size;                                       
}
int udtSize(const Udt *udt)                   
{
    return udt->_size;                                              
}

int udtCapacity(const Udt *udt)                               
{
    return udt->_capacity;                                   
}

int udtEmpty(const Udt *udt)                             
{
    return udt->_size == 0;                         
}

int udtPush(Udt *udt, const UDT_TYPE value)                        
{
    if (udt->_size == udt->_capacity)                               
        return 0;
    // В очередь помещается структура с номером и содержимым
    udt->_data[(udt->_first + udt->_size) % udt->_capacity] = value;
    udt->_size++;                                                 

    return 1;
}

UDT_TYPE udtFront(const Udt *udt)                                   
{
    return udt->_data[udt->_first];                                 // Возвращает содержимое структуры первого элемента
}

void udtPop(Udt *udt)                                               // Функция извлечения из очереди
{
    if (udt->_size == 0)                                            // Проверка на пустоту реальной очереди
        return;

    udt->_first = (udt->_first + 1) % udt->_capacity;               // Первый элемент становится следующим за ним с учетом % на длину очереди
    udt->_size--;                                                   // Число элементов в очереди уменьшается на 1
}

void udtPrint(Udt *udt)                                             // Функция печати очереди
{                                             
    UDT_TYPE tmp;                                                   // tmp - структура элемента очереди

    for (int i = 0; i < udtSize(udt); i++)                              // Цикл от 0 до реального размера очереди
    {
        tmp = udt->_data[(udt->_first + i) % udt->_capacity];       // tmp = 'номер + значение' всех элементов в очереди, начиная с 1
        // с учетом % на формальный размер
        printf("%d %s\n", tmp._key, tmp._val);                     // Вывод номера + значения
    }
}

void udtDestroy(Udt *udt)                                           // Функция удаления ВСЕЙ очереди
{
    if (udt->_data == NULL)                                         // Если очередь пуста, то ничего
        return;

    free(udt->_data);                                               // Освобождаем память для структуры - элемента очереди

    udt->_data = NULL;                                              // Обнуляем структуру - элемент очереди
}
