# Отчёт по лабораторной работе №1 по курсу “Фундаментальная информатика”

Студент группы: М80-108Б-22 Горюнов Даниил Владимирович, № по списку 4 

Контакты e-mail: dania.goryunow2013@yandex.ru

Работа выполнена: «1» октября 2022 г.

Преподаватель: асп. каф. 806 Сахарин Никита Александрович

Входной контроль знаний с оценкой _______________________

Отчет сдан «1» октября 2022 г., итоговая оценка ______

Подпись преподавателя ___________


## 1. Тема
Операционная среда OC UNIX
## 2. Цель работы
Изучение и освоение программного обеспечения ОС UNIX и приобретение навыков, необходимых для выполнения курсовых и лабораторных работ в среде UNIX.
## 3. Задание (вариант № —)
## 4. Оборудование:
Процессор: Apple M1
ОП: 8192 МБ
НМД: 512 ГБ  
Монитор: Retina c диагональю 13,3 дюйма разрешение 2560×1600 пикселей (227 пикселей)
## 5. Программное обеспечение:
Операционная система семейства: MacOS
Интерпретатор команд: bash 
Система программирования: не использовалась версия — 
Редактор текстов: emacs, nano
Утилиты операционной системы: who, uptime, man, tty, hostname, uname, whoami, finger, mkdir, rmdir, date, cal, ps, ls, pwd, cd, rm, mv, cp, cat, chmod.
Прикладные системы и программы: -
Местонахождение и имена файлов программ и данных на домашнем компьютере: /home/admin
## 6. Идея, метод, алгоритм решения задачи (в формах: словесной, псевдокода, графической [блок-схема, диаграмма, рисунок, таблица] или формальные спецификации с пред- и постусловиями)
Изучить основы программного обеспечения ОС UNIX
Команды:
who – информация о текущем вошедшем в систему пользователе
uptime – отображает время работы системы, количество вошедших в систему пользователей, среднюю загрузку системы
man – справка по команде
tty – отображает информацию, связанную с терминалом (имя файла терминала, подключенного к стандартному входу)
hostname – сетевое имя машины
uname –  информация об операционной системе
whoami – имя текущего пользователя
finger –  подробная информация о пользователе
mkdir – создать директорию
rmdir – удалить пустую директорию
date – показывает текущую дату и время
cal – календарь
ps – информация об активных процессах
ls – список содержимого каталога
pwd – полный путь к текущему каталогу
cd – перемещение по директориям
rm – удалить файлы или директории
mv – переместить или переименовать файлы или директории
cp – скопировать файлы или директории
cat – считывает данные из файла и выдает их содержимое в качестве выходных данных
chmod – права доступа
## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию]. 
1) Изучить литературу по OC UNIX
2) Открыть терминал в OC UNIX
3) Приобрести основные навыки работы в OC UNIX 
4) Освоить навигацию в иерархической файловой системе OC UNIX
5) Произвести манипуляции с файлами
6) Применить сервисные функции
7) Оформить отчёт установленной формы
Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.  
Подпись преподавателя _____________________
## 8. Распечатка протокола 
```
Last login: Thu Sep 29 20:16:06 on ttys000
admin@MacBook-Pro-Admin ~ % who
admin    console  Sep 27 21:08 
admin    ttys000  Sep 29 20:23 
admin@MacBook-Pro-Admin ~ % uptime
20:24  up 1 day, 23:16, 2 users, load averages: 1,31 1,39 1,42
admin@MacBook-Pro-Admin ~ % tty
/dev/ttys000
admin@MacBook-Pro-Admin ~ % hostname
MacBook-Pro-Admin.local
admin@MacBook-Pro-Admin ~ % uname
Darwin
admin@MacBook-Pro-Admin ~ % uname -a
Darwin MacBook-Pro-Admin.local 21.6.0 Darwin Kernel Version 21.6.0: Mon Aug 22 20:20:05 PDT 2022; root:xnu-8020.140.49~2/RELEASE_ARM64_T8101 arm64
admin@MacBook-Pro-Admin ~ % whoami
admin
admin@MacBook-Pro-Admin ~ % finger
Login    Name                 TTY  Idle  Login  Time   Office  Phone
admin    Admin               *con    1d  вт   21:08
admin    Admin                s00        чт   20:23
admin@MacBook-Pro-Admin ~ % ps
  PID TTY           TIME CMD
 6336 ttys000    0:00.04 -zsh
admin@MacBook-Pro-Admin ~ % 
admin@MacBook-Pro-Admin ~ % ls
Applications	Library		Public		set
Desktop		Movies		PycharmProjects	test.sh
Documents	Music		f1.txt		text.txt
Downloads	Pictures	f2.txt		text.txt.save
admin@MacBook-Pro-Admin ~ % ls /
Applications	Volumes		etc		sbin
Library		bin		home		tmp
System		cores		opt		usr
Users		dev		private		var
admin@MacBook-Pro-Admin ~ % pwd
/Users/admin
admin@MacBook-Pro-Admin ~ % mkdir testscd
admin@MacBook-Pro-Admin ~ % cd testscd
admin@MacBook-Pro-Admin testscd % ls
admin@MacBook-Pro-Admin testscd % cd ..
admin@MacBook-Pro-Admin ~ % ls
Applications	Library		Public		set		text.txt.save
Desktop		Movies		PycharmProjects	test.sh
Documents	Music		f1.txt		testscd
Downloads	Pictures	f2.txt		text.txt
admin@MacBook-Pro-Admin ~ % ls -1
Applications
Desktop
Documents
Downloads
Library
Movies
Music
Pictures
Public
PycharmProjects
f1.txt
f2.txt
set
test.sh
testscd
text.txt
text.txt.save
admin@MacBook-Pro-Admin ~ % cd testscd
admin@MacBook-Pro-Admin testscd % cat >>f1
123
456789
admin@MacBook-Pro-Admin testscd % cat f1
123
456789
admin@MacBook-Pro-Admin testscd % cat <f1
123
456789
admin@MacBook-Pro-Admin testscd % cat >f1
qwerty
admin@MacBook-Pro-Admin testscd % cat f1
qwerty
admin@MacBook-Pro-Admin testscd % cat <<f1
heredoc> 12345
heredoc> f1
12345
admin@MacBook-Pro-Admin testscd % cat f1 f2
qwerty
admin@MacBook-Pro-Admin testscd % cat f1
qwerty
admin@MacBook-Pro-Admin testscd % cp f1 f2
admin@MacBook-Pro-Admin testscd % cat f2
qwerty
admin@MacBook-Pro-Admin testscd % cat f1
qwerty
admin@MacBook-Pro-Admin testscd % cat f1 f2 > f3
admin@MacBook-Pro-Admin testscd % cat f3
qwerty
qwerty
admin@MacBook-Pro-Admin testscd % mv f3 f4
admin@MacBook-Pro-Admin testscd % ls
f1	f2	f4
admin@MacBook-Pro-Admin testscd % mkdir A
admin@MacBook-Pro-Admin testscd % ls
A	f1	f2	f4
admin@MacBook-Pro-Admin testscd % mv f10 A
mv: rename f10 to A/f10: No such file or directory
admin@MacBook-Pro-Admin testscd % mv f4 A
admin@MacBook-Pro-Admin testscd % ls
A	f1	f2
admin@MacBook-Pro-Admin testscd % ls a
f4
admin@MacBook-Pro-Admin testscd % rm code
rm: code: No such file or directory
admin@MacBook-Pro-Admin testscd % rm f2
admin@MacBook-Pro-Admin testscd % ls
A	f1
admin@MacBook-Pro-Admin testscd % ls -l
total 8
drwxr-xr-x  3 admin  staff  96 29 сен 20:39 A
-rw-r--r--  1 admin  staff   7 29 сен 20:31 f1
admin@MacBook-Pro-Admin testscd % chmod 777 f1
admin@MacBook-Pro-Admin testscd % ls -l
total 8
drwxr-xr-x  3 admin  staff  96 29 сен 20:39 A
-rwxrwxrwx  1 admin  staff   7 29 сен 20:31 f1
admin@MacBook-Pro-Admin testscd % gnuplot
zsh: command not found: gnuplot
admin@MacBook-Pro-Admin testscd % bc
bc 1.06
Copyright 1991-1994, 1997, 1998, 2000 Free Software Foundation, Inc.
This is free software with ABSOLUTELY NO WARRANTY.
For details type `warranty'. 
warranty

bc 1.06
Copyright 1991-1994, 1997, 1998, 2000 Free Software Foundation, Inc.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License , or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, write to

       The Free Software Foundation, Inc.
       59 Temple Place, Suite 330
       Boston, MA 02111, USA.

admin@MacBook-Pro-Admin gnuplot

	G N U P L O T
	Version 5.4 patchlevel 1    last modified 2020-12-01

	Copyright (C) 1986-1993, 1998, 2004, 2007-2020
	Thomas Williams, Colin Kelley and many others

	gnuplot home:     http://www.gnuplot.info
	faq, bugs, etc:   type "help FAQ"
	immediate help:   type "help"  (plot window: hit 'h')

Terminal type is now 'qt'

gnuplot> set parametric

	dummy variable is t for curves, u/v for surfaces
gnuplot> set trange [0 to 2*pi]
gnuplot> set xrange [-1 to 1]
gnuplot> set yrange [-1 to 1]
gnuplot> plot sin(t),cos(t)

![Aspose Words 749064b9-5b3f-4fd3-825a-38a36ed9b199 002](https://user-images.githubusercontent.com/113765574/194692264-4f6f293c-0dc3-4a1e-ac3d-6024dd91f781.png)


gnuplot> set zrange [-1 to 1]
gnuplot> set urange [0 to 2*pi]
gnuplot> set vrange [0 to 2*pi]
gnuplot> set nohidden3d
             ^
         warning: deprecated syntax, use "unset"
gnuplot> splot sin(u)*sin(v),sin(u)*cos(v),cos(u)

![](assets/16652089675510.jpg)

admin@MacBook-Pro-Admin bc
bc 1.07.1
Copyright 1991-1994, 1997, 1998, 2000, 2004, 2006, 2008, 2012-2017 Free Software Foundation, Inc.
This is free software with ABSOLUTELY NO WARRANTY.
For details type `warranty'.
ibase=10
obase=2
20
10100
obase=4
20
110
obase=8
20
24
obase=16
20
14
obase=16
28
1C
ibase=2
101010
2A
obase=1010
101010
42
obase=1000
101010
52
obase=100
101010
222
ibase=100
obase=2
123
11011
obase=20
123
33
obase=100
123
1B
ibase=20
120
50
obase=4
120
1100
obase=2
120
1010000
ibase=20
obase=2
A1
10100001
obase=4
A1
2201
obase=8
A1
241
admin@MacBook-Pro-Admin ~ % cal
   Сентябрь 2022      
вс пн вт ср чт пт сб  
             1  2  3  
 4  5  6  7  8  9 10  
11 12 13 14 15 16 17  
18 19 20 21 22 23 24  
25 26 27 28 29 30     
                      
admin@MacBook-Pro-Admin ~ % date
четверг, 29 сентября 2022 г. 20:54:08 (MSK)



```
## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 01.10.22 | 13:00 | Выполнение лабораторной работы | - | - |
## 10. Замечания автора по существу работы — Написание команд для отработки навыков работы в ОС UNIX.
```

```
## 11. Выводы
В ходе выполнения данной лабораторной работы были изучены основы работы в OC unix: перемещение в директориях, создание файла и работа с ним и т.д.
Недочёты при выполнении задания могут быть устранены следующим образом: —

Подпись студента _________________


