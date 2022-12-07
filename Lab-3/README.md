# Отчёт по лабораторной работе №2 по курсу “Фундаментальная информатика”

Студент группы: М80-108Б-22 Горюнов Даниил Владимирович, № по списку 4 

Контакты e-mail: dania.goryunow2013@yandex.ru

Работа выполнена: «6» октября 2022 г.

Преподаватель: асп. каф. 806 Сахарин Никита Александрович

Входной контроль знаний с оценкой _______________________

Отчет сдан «6» октября 2022 г., итоговая оценка ______

Подпись преподавателя ___________


## 1. Тема
Сети и телекоммуникации в ОС UNIX
## 2. Цель работы
Изучение и освоение удалённых команд UNIX и приобретение навыков, необходимых для выполнения курсовых и лабораторных работ в среде UNIX.
## 3. Задание (вариант № —)
Изучение удалённых команд
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
Утилиты операционной системы: ssh, scp, ls, cd, hostname, cat, mrdir, rm, rmdir, tar
Прикладные системы и программы: -
Местонахождение и имена файлов программ и данных на домашнем компьютере: /home/admin
## 6. Идея, метод, алгоритм решения задачи (в формах: словесной, псевдокода, графической [блок-схема, диаграмма, рисунок, таблица] или формальные спецификации с пред- и постусловиями)
Изучить основы программного обеспечения ОС UNIX
Ввод команд:
1. ls -l/-A/-lAF – ознакомление с содержимым директории 

## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию]. 
- Изучить литературу по OC UNIX
- Просмотреть демонстрационный материал в лабораторной аудитории
- Освоить удалённые команды OC UNIX
- Научиться удалённо манипулировать с файлами 
- Запротоколировать сеанс

Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.  
Подпись преподавателя _____________________
## 8. Распечатка протокола 
```
daniil@daniil-VirtualBox:~$ hostname -I
192.168.56.101
daniil@daniil-VirtualBox:~$ ls
 snap   Видео   Документы   Загрузки   Изображения   Музыка   Общедоступные  'Рабочий стол'   Шаблоны
daniil@daniil-VirtualBox:~$ cat > file.txt
test file
daniil@daniil-VirtualBox:~$ ls
 file.txt   Видео       Загрузки      Музыка         'Рабочий стол'
 snap       Документы   Изображения   Общедоступные   Шаблоны
daniil@daniil-VirtualBox:~$ mkdir kk
daniil@daniil-VirtualBox:~$ ls
 file.txt   snap    Документы   Изображения   Общедоступные   Шаблоны
 kk         Видео   Загрузки    Музыка       'Рабочий стол'
daniil@daniil-VirtualBox:~$ cp file.txt kk
daniil@daniil-VirtualBox:~$ ls
 file.txt   snap    Документы   Изображения   Общедоступные   Шаблоны
 kk         Видео   Загрузки    Музыка       'Рабочий стол'
daniil@daniil-VirtualBox:~$ cd kk
daniil@daniil-VirtualBox:~/kk$ ls
file.txt
daniil@daniil-VirtualBox:~/kk$ cd .. 
daniil@daniil-VirtualBox:~$ ssh daniil2@192.168.56.102
daniil2@192.168.56.102's password: 
Welcome to Ubuntu 22.04.1 LTS (GNU/Linux 5.15.0-48-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage

131 обновление может быть применено немедленно.
38 из этих обновлений, являются стандартными обновлениями безопасности.
Чтобы просмотреть дополнительные обновления выполните: apt list --upgradable

Last login: Tue Sep 27 15:29:15 2022 from 127.0.0.1
daniil2@daniil2-VirtualBox:~$ ls
 snap    Документы   Изображения   Общедоступные   Шаблоны
 Видео   Загрузки    Музыка       'Рабочий стол'
daniil2@daniil2-VirtualBox:~$ cat > test.txt
Hello, world!
daniil2@daniil2-VirtualBox:~$ ls
 snap       Видео       Загрузки      Музыка         'Рабочий стол'
 test.txt   Документы   Изображения   Общедоступные   Шаблоны
daniil2@daniil2-VirtualBox:~$ scp /home/daniil2/test.txt daniil@192.168.56.101:/home/daniil
daniil@192.168.56.101's password: 
test.txt                                         100%   14     5.9KB/s   00:00    
daniil2@daniil2-VirtualBox:~$ mkdir testdir
daniil2@daniil2-VirtualBox:~$ cat > lol.txt
lol
daniil2@daniil2-VirtualBox:~$ ls
 lol.txt   testdir    Видео       Загрузки      Музыка         'Рабочий стол'
 snap      test.txt   Документы   Изображения   Общедоступные   Шаблоны

daniil2@daniil2-VirtualBox:~/testdir$ cd ..
daniil2@daniil2-VirtualBox:~$ scp -r /home/daniil2/testdir daniil@192.168.56.101:/home/daniil
daniil@192.168.56.101's password: 
lol.txt                                          100%    4     2.0KB/s   00:00
daniil2@daniil2-VirtualBox:~$ ssh daniil@192.168.56.101 "ls -1 ~"
daniil@192.168.56.101's password: 
file.txt
test.txt
kk
snap
testdir
Видео
Документы
Загрузки
Изображения
Музыка
Общедоступные
Рабочий стол
Шаблоны
daniil2@daniil2-VirtualBox:~$ ssh daniil@192.168.56.101 "ls -1 ~/testdir"
daniil@192.168.56.101's password: 
lol.txt
daniil2@daniil2-VirtualBox:~$ mkdir arch
daniil2@daniil2-VirtualBox:~$ tar -cf archive.tar arch
daniil2@daniil2-VirtualBox:~$ ls
 arch          snap       Видео       Изображения    'Рабочий стол'
 archive.tar   testdir    Документы   Музыка          Шаблоны
 lol.txt       test.txt   Загрузки    Общедоступные
daniil2@daniil2-VirtualBox:~$ tar -tvf archive.tar
drwxrwxr-x daniil2/daniil2 0 2022-09-27 17:56 arch/
daniil2@daniil2-VirtualBox:~$ scp /home/daniil2/archive.tar daniil@192.168.56.101:/home/daniil
daniil@192.168.56.101's password: 
archive.tar                                      100%   10KB   3.4MB/s   00:00 
daniil2@daniil2-VirtualBox:~$ exit
выход
Connection to 192.168.56.102 closed.
daniil@daniil-VirtualBox:~$ ls
 archive.tar  test.txt  kk     testdir   Документы   Изображения   Общедоступные   Шаблоны
 file.txt      snap    Видео     Загрузки    Музыка       'Рабочий стол'
daniil@daniil-VirtualBox:~$ cat test.txt
Hello, world!
daniil@daniil-VirtualBox:~$ cd testdir
daniil@daniil-VirtualBox:~/testdir$ ls
lol.txt
daniil@daniil-VirtualBox:~/testdir$ cat lol.txt
lol
daniil@daniil-VirtualBox:~/testdir$ cd ..
daniil@daniil-VirtualBox:~$ tar -xf archive.tar
daniil@daniil-VirtualBox:~$ ls
 arch          test.txt    kk        Видео       Изображения    'Рабочий стол'
 archive.tar   snap      Документы   Музыка          Шаблоны
 file.txt      testdir   Загрузки    Общедоступные
daniil@daniil-VirtualBox:~$ rmdir arch
daniil@daniil-VirtualBox:~$ rm archive.tar
daniil@daniil-VirtualBox:~$ rm test.txt
daniil@daniil-VirtualBox:~$ ls
 file.txt   test.txt    snap      Видео       Загрузки      Музыка         'Рабочий стол'
 kk         testdir   Документы   Изображения   Общедоступные   Шаблоны
daniil@daniil-VirtualBox:~$ cd testdir
daniil@daniil-VirtualBox:~/testdir$ ls
lol.txt
daniil@daniil-VirtualBox:~/testdir$ rm lol.txt
daniil@daniil-VirtualBox:~/testdir$ cd ..
daniil@daniil-VirtualBox:~$ rmdir testdir
daniil@daniil-VirtualBox:~$ ls
 file.txt   snap    Документы   Изображения   Общедоступные   Шаблоны
 kk         Видео   Загрузки    Музыка       'Рабочий стол'
daniil@daniil-VirtualBox:~$ ssh daniil2@192.168.56.102
daniil2@192.168.56.102's password: 
Welcome to Ubuntu 22.04.1 LTS (GNU/Linux 5.15.0-48-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage

131 обновление может быть применено немедленно.
38 из этих обновлений, являются стандартными обновлениями безопасности.
Чтобы просмотреть дополнительные обновления выполните: apt list --upgradable

Last login: Tue Sep 27 17:32:33 2022 from 192.168.56.101
daniil2@daniil2-VirtualBox:~$ ls
 arch          snap       Видео       Изображения    'Рабочий стол'
 archive.tar   testdir    Документы   Музыка          Шаблоны
 lol.txt       test.txt   Загрузки    Общедоступные
daniil2@daniil2-VirtualBox:~$ scp daniil@192.168.56.101:~/file.txt ~
daniil@192.168.56.101's password: 
file.txt                                         100%   10     5.6KB/s   00:00    
daniil2@daniil2-VirtualBox:~$ ls
 arch          lol.txt   test.txt    Загрузки      Общедоступные
 archive.tar   snap      Видео       Изображения  'Рабочий стол'
 file.txt      testdir   Документы   Музыка        Шаблоны
daniil2@daniil2-VirtualBox:~$ cat test.txt
Hello, world!
daniil2@daniil2-VirtualBox:~$ scp -r daniil@192.168.56.101:~/kk ~
daniil@192.168.56.101's password: 
file.txt                                         100%   10     7.0KB/s   00:00  
daniil2@daniil2-VirtualBox:~$ ls
 arch          kk        testdir    Документы     Музыка          Шаблоны
 archive.tar   lol.txt   test.txt   Загрузки      Общедоступные
 file.txt      snap      Видео      Изображения  'Рабочий стол'
daniil2@daniil2-VirtualBox:~$ cd kk
daniil2@daniil2-VirtualBox:~/kk$ ls
file.txt
daniil2@daniil2-VirtualBox:~/kk$ cat file.txt
test file
daniil2@daniil2-VirtualBox:~/kk$ cd ..
daniil2@daniil2-VirtualBox:~$ exit
выход
Connection to 192.168.56.102 closed.
daniil@daniil-VirtualBox:~$ exit
```
## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 01.10.22 | 13:00 | Выполнение лабораторной работы | - | - |
## 10. Замечания автора по существу работы — Написание команд для отработки навыков работы в ОС UNIX.
```

```
## 11. Выводы
В ходе выполнения данной лабораторной работы были приобретены навыки работы с возможностью удаленного подключения, освоены команды, необходимые для установления соединения и удаленных манипуляций с файлами, а также приобретены навыки работы, которые помогут выполнять другие лабораторные работы

Недочёты при выполнении задания могут быть устранены следующим образом: —

Подпись студента _________________
