# Отчёт по лабораторной работе №4 по курсу “Фундаментальная информатика”

Студент группы: М80-108Б-22 Горюнов Даниил Владимирович, № по списку 4 

Контакты e-mail: dania.goryunow2013@yandex.ru

Работа выполнена: «1» октября 2022 г.

Преподаватель: асп. каф. 806 Сахарин Никита Александрович

Входной контроль знаний с оценкой _______________________

Отчет сдан «1» октября 2022 г., итоговая оценка ______

Подпись преподавателя ___________


## 1. Тема
Работа с диаграммером Тьюринга
## 2. Цель работы
Освоить построение диаграмм Тьюринга, разработав диаграмму решения задачи в среде интерпретатора jdt с использованием стандартных машин( r,l,R,L,K,a) и вспомогательных машин, определяемых поставленной задачей
## 3. Задание (вариант № —)
Вариант №28 (Деление двух неотрицательных десятичных чисел)
## 4. Оборудование:
Процессор: Apple M1
ОП: 8192 МБ
НМД: 512 ГБ  
Монитор: Retina c диагональю 13,3 дюйма разрешение 2560×1600 пикселей (227 пикселей)
## 5. Программное обеспечение:
Операционная система семейства: MacOS
Интерпретатор команд: bash 
Система программирования: не использовалась версия — 
Местонахождение и имена файлов программ и данных на домашнем компьютере: /home/admin
## 6. Идея, метод, алгоритм решения задачи (в формах: словесной, псевдокода, графической [блок-схема, диаграмма, рисунок, таблица] или формальные спецификации с пред- и постусловиями)
Идея решения задачи заключается в том, чтобы скопировать делимое и делитель (изначально рассмотрев случаи когда либо делимое, либо делитель 0), затем вычитать из делителя единицу, после чего из делимого до тех пор пока одно из чисел не стало равно нулю, если обнулился делитель, то мы стираем 0 и затем переходим к результату, где добавляем 1(то есть мы показали что 1 раз делитель содержится в делимом). После этого переходим опять к копированию делителя. Если же обнулилось делимое, то мы проверяем обнулился ли делитель.1 случай: если делитель 0, то это значит что два числа поделилось и мы просто проходим справа налево(стирая при этом нули) и останавливаем головку МТ за результатом.2 случай: если делитель не 0, то это значит, что два числа не разделились друг на друга, тогда мы стираем оставшийся делитель и возвращаемся к результату и оставляем его( что означает целая часть от деления).
## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию]. 
1.Программа проверяет не является ли одно из чисел нулем
•	Если делимое 0, то программа выводит в результате 0
•	Если делитель 0, то программа стирает результат и останавливается(т.к на 0 делить нельзя)
2.Копирует оба числа и начинает вычитать из делителя 1 (для этого была создана машина «вычитаниедел») 
3.Проверяет если копируемое делимое не 0, то из него также вычитает 1
4.Шаг 2-3 повторяется до тех пор, пока одно из чисел не становится 0
•	Если делитель 0, то его стирают, переходят к результату и с помощью машины «плюс» добавляет к нему 1 и переходят к копированию делителя заново (затем шаг 2-3)
•	Если делимое 0, то проверяет делитель и в зависимости от его значения(0 или не 0) выводят результат( что означает либо частное, либо целую часть от деления)





Основная прогграмма 
<img width="493" alt="image" src="https://user-images.githubusercontent.com/113765574/201468091-e0d1e5c1-5110-4fac-95d2-9a5c8842c888.png">



Программа для вычитания из числа единицы
<img width="468" alt="image" src="https://user-images.githubusercontent.com/113765574/201468096-891748e8-3a76-413c-abf1-7ba54e184c15.png">


Программа для прибавления к числу единицы
<img width="426" alt="image" src="https://user-images.githubusercontent.com/113765574/201468103-efcedc28-e33d-48d8-b5f8-491b2149098c.png">



## 8. Распечатка протокола 
```
81 9 9 
```
## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 01.10.22 | 13:00 | Выполнение лабораторной работы | - | - |
## 10. Замечания автора по существу работы — 
```

```
## 11. Выводы
В ходе выполнения данной лабораторной работы были приобретены основные навыки работы с диаграммами Тьюринга (копирование входных данных и их преобразование), освоены принципы работы с ней. Были изучены различные методы решения задач с помощью диаграммера Тьюринга

Недочёты при выполнении задания могут быть устранены следующим образом: —

Подпись студента _________________


