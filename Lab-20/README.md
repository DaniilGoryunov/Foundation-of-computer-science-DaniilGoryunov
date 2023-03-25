# Отчёт по лабораторной работе №20 по курсу “Языки и методы программирования”

<b>Студент группы:</b> <ins>М80-108Б-22 Горюнов Даниил Владимирович, № по списку: 4</ins>

<b>Контакты e-mail:</b> <ins>dania.goryunow2013@yandex.ru</ins>

<b>Работа выполнена:</b> «17» <ins>марта</ins> <ins>2023</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins> </ins>

<b>Отчет сдан</b> «17» <ins>марта</ins> <ins>2023</ins> г., <b>итоговая оценка</b> <ins> </ins>

<b>Подпись преподавателя:</b> ___________


## 1. Тема
Стандартные утилиты UNIX для обработки файлов
## 2. Цель работы
Изучить основные команды обработки текстовых файлов ОС UNIX.
## 3. Задание (вариант № 4)
Подготовить нетривиальные текстовые файлы для иллюстрации работы 3-х утилит (xargs, tee, comm). Запротоколировать подготовленные примеры и иллюстрации работы для 20-ти утилит пакетного режима с распечаткой используемых текстовых файлов.
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

| Команда |  Базовый синтакис | Флаги | Описание |
| ------ | ------ | ------ | ------ |
| xargs | [команда-источник данных] xargs [опции xargs] [команда-аргумент]| ***-0, --null*** - использовать в качестве разделителя нулевой символ. Обычно он находится в конце строки. По умолчанию, в качестве разделителя используется пробел, перевод строки или табуляция; ***-a, --arg-file*** - прочитать аргументы, которые надо передать команде из файла; ***-d, --delimiter*** - использовать нестандартный разделитель строк; ***-E, -e, --eof*** - индикатор конца файла, все символы после вхождения этой строки игнорируются; ***-l, --max-lines*** - количество строк, передающихся в одну команду по умолчанию все; ***-n, --max-args*** - количество параметров, которые передаются в одну команду, по умолчанию все; ***-o, --open-tty*** - открывать новый терминал для дочерних процессов; ***-p, --interactive*** - спрашивать пользователя о запуске каждой следующей команды; ***-r, --no-run-if-empty*** - если входной поток данных пустой, команда не будет выполнена; ***--show-limits*** - посмотреть ограничения на длину параметров в командной строке; ***-t, --verbos*** - максимально подробный вывод утилиты. | Утилита для формирования списка аргументов и выполнения команды в UNIX-подобных операционных системах. Команда xargs объединяет зафиксированный набор заданных в командной строке начальных аргументов с аргументами, прочитанными со стандартного ввода, и выполняет указанную команду один или несколько раз|
| tee | tee [OPTIONS] [FILE] | ***-a или -append*** - Используется для записи вывода в конец существующего файла. ***-i или -ignore-interrupts*** - Используется, чтобы игнорировать прерывающие сигналы. ***help*** - Используется для показа всех возможных операций. ***version*** - Используется для показа текущей версии этой команды. | Команда tee в Linux считывает стандартный ввод и записывает его одновременно в стандартный вывод и в один или несколько подготовленных файлов. При обычном перенаправлении потока вывода строки команды будут записаны в файл, но мы не сможем увидеть вывод одновременно. С помощью команды tee мы можем это сделать!  |
| comm | comm [параметры] <файл 1> <файл 2> | ***-1*** Подавить вывод первой колонки. ***-2*** Подавить вывод второй колонки. ***-3*** Подавить вывод третьей колонки. ***-i*** Нечувствительное к регистру сравнение строк. | Команда comm позволяет использовать одноименную утилиту для сравнения двух текстовых файлов с отсортированными по алфавиту строками |


## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию].

1. ```cmp``` – сравнение двух файлов байт за байтом
2. ```wc``` – обработка входного потока или файла
3. ```diff``` – определеяет изменения в файлах, которые необходимо сделать, чтобы они стали идентичными
4. ```grep``` – позволяет фильтровать и сортировать содержимое текстовых файлов 
5. ```sort``` – сортировка текста
6. ```tail``` – выводит последние N строк файла (по умолчанию - последние 10 строк)
7. ```tee``` – запись вывода любой команды в один или несколько файлов
8. ```od``` – печать файла в восьмеричном формате (по умолчанию)
9. ```sum``` – подсчет контрольной суммы и блоков в файлеы
10. ```cut``` – позволяет вырезать части строк из указанных файлов
11. ```tar``` – распаковка архива tar Linux с выводом файлов на экран
12. ```gzip``` – архивирование файлов
13. ```ed``` – текстовый редактор
14. ```bzip2``` – архивирование файлов, более эффективная, но работает медленнее
15. ```head``` – выводит первые N строк файла (по умолчанию - первые 10 строк)
16. ```iconv``` – преобразование текстового файла из одной кодировки в другую
17. ```uniq``` – создание пустого файла, изменение модификации и времени доступа для любого файла
18. ```df``` – получение полной сводной информации об использовании доступного и используемого дискового пространства файловой системы
19. ```comm``` – объединение соответствующих строк файлов по горизонтали
20. ```mktemp``` – создание временных файлов или каталогов

Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя:</b> _____________________

## 8. Распечатка протокола 

```
Last login: Fri Mar 17 15:18:27 on ttys000
Last login: Fri Mar 24 16:14:57 on ttys001
admin@MacBook-Pro-Admin ~ % xargs -t
^Z
zsh: suspended  xargs -t
admin@MacBook-Pro-Admin ~ % cd Desktop
admin@MacBook-Pro-Admin Desktop % ls ~/Изображения | xargs -t -L1 echo
ls: /Users/admin/Изображения: No such file or directory
admin@MacBook-Pro-Admin Desktop % cd ..
admin@MacBook-Pro-Admin ~ % ls ~/Desktop | xargs -t -L1 echo
echo KBH
KBH
echo Microsoft Excel
Microsoft Excel
echo Microsoft Word
Microsoft Word
echo PyCharm CE
PyCharm CE
echo Python 3.10
Python 3.10
echo pythonProject
pythonProject
echo МАИ
МАИ
echo ФИЛЬМЫ
ФИЛЬМЫ
echo проект ркт
проект ркт
echo Снимок экрана 2022-10-23 в 19.40.53.png
Снимок экрана 2022-10-23 в 19.40.53.png
echo Снимок экрана 2022-10-23 в 20.32.19.png
Снимок экрана 2022-10-23 в 20.32.19.png
admin@MacBook-Pro-Admin ~ % ls ~/Desktop | xargs -t  echo   
echo KBH Microsoft Excel Microsoft Word PyCharm CE Python 3.10 pythonProject МАИ ФИЛЬМЫ проект ркт Снимок экрана 2022-10-23 в 19.40.53.png Снимок экрана 2022-10-23 в 20.32.19.png
KBH Microsoft Excel Microsoft Word PyCharm CE Python 3.10 pythonProject МАИ ФИЛЬМЫ проект ркт Снимок экрана 2022-10-23 в 19.40.53.png Снимок экрана 2022-10-23 в 20.32.19.png
admin@MacBook-Pro-Admin ~ % ls ~/Desktop | xargs -t -L1 echo
echo KBH
KBH
echo Microsoft Excel
Microsoft Excel
echo Microsoft Word
Microsoft Word
echo PyCharm CE
PyCharm CE
echo Python 3.10
Python 3.10
echo pythonProject
pythonProject
echo МАИ
МАИ
echo ФИЛЬМЫ
ФИЛЬМЫ
echo проект ркт
проект ркт
echo Снимок экрана 2022-10-23 в 19.40.53.png
Снимок экрана 2022-10-23 в 19.40.53.png
echo Снимок экрана 2022-10-23 в 20.32.19.png
Снимок экрана 2022-10-23 в 20.32.19.png
admin@MacBook-Pro-Admin ~ % cd desktop/МАИ/первый/IT-разработка/mai_future_xr  
admin@MacBook-Pro-Admin mai_future_xr % cd ..
admin@MacBook-Pro-Admin IT-разработка % cd ..
admin@MacBook-Pro-Admin первый % cd лабы
admin@MacBook-Pro-Admin лабы % ды 
zsh: command not found: ды
admin@MacBook-Pro-Admin лабы % ls
Foundation-of-computer-science-DaniilGoryunov
KP3
KP4
Prikols
laba 13
laba11
laba12
laba14
laba15
laba8
laba9
labalaba11
labalaba14
musorka
~$звитие исторической науки в России.docx
admin@MacBook-Pro-Admin лабы % date | tee вывод1.txt вывод2.txt
суббота, 25 марта 2023 г. 18:50:13 (MSK)
admin@MacBook-Pro-Admin лабы % cat вывод1.txt
суббота, 25 марта 2023 г. 18:50:13 (MSK)
admin@MacBook-Pro-Admin лабы % 
admin@MacBook-Pro-Admin лабы % cd Foundation-of-computer-science-DaniilGoryunov
admin@MacBook-Pro-Admin Foundation-of-computer-science-DaniilGoryunov % cd lab-20
admin@MacBook-Pro-Admin lab-20 % touch README.md
admin@MacBook-Pro-Admin lab-20 % cat comm1
cat: comm1: No such file or directory
admin@MacBook-Pro-Admin lab-20 % cat >> com1
001
002
003
004
005
^Z
zsh: suspended  cat >> com1
admin@MacBook-Pro-Admin lab-20 % cat >> comm2
000
001
003
005
007
^Z
zsh: suspended  cat >> comm2
admin@MacBook-Pro-Admin lab-20 % comm comm1 comm2
	000
		001
002
		003
004
		005
	007
admin@MacBook-Pro-Admin lab-20 % comm -23 comm1 comm2
002
004
admin@MacBook-Pro-Admin lab-20 % comm -13 comm1 com2
comm: com2: No such file or directory
admin@MacBook-Pro-Admin lab-20 % comm -13 comm1 comm2
000
007
admin@MacBook-Pro-Admin lab-20 % comm -12 comm1 comm2
001
003
005
admin@MacBook-Pro-Admin lab-20 % cat |& tee file.txt
123
123
345
345
^Z
zsh: suspended  cat 2>&1 | tee file.txt
admin@MacBook-Pro-Admin lab-20 % cat file.txt
123
345
admin@MacBook-Pro-Admin lab-20 % cat |& tee file.txt
123
123
543
543
^Z
zsh: suspended  cat 2>&1 | tee file.txt
admin@MacBook-Pro-Admin lab-20 % cat |& tee file1.txt
123
123
345
345
^Z
zsh: suspended  cat 2>&1 | tee file1.txt
admin@MacBook-Pro-Admin lab-20 % cmp file.txt file1.txt
file.txt file1.txt differ: char 5, line 2
admin@MacBook-Pro-Admin lab-20 % cmp -l file.txt file1.txt
     5  65  63
     7  63  65
admin@MacBook-Pro-Admin lab-20 % wc file.txt
       2       2       8 file.txt
admin@MacBook-Pro-Admin lab-20 % wc -c file.txt
       8 file.txt
admin@MacBook-Pro-Admin lab-20 % wc -m file.txt
       8 file.txt
admin@MacBook-Pro-Admin lab-20 % wc -l file.txt
       2 file.txt
admin@MacBook-Pro-Admin lab-20 % wc -w file.txt
       2 file.txt
admin@MacBook-Pro-Admin lab-20 % diff file.txt file1.txt
2c2
< 543
---
> 345
admin@MacBook-Pro-Admin lab-20 % ls | grep Documents
admin@MacBook-Pro-Admin lab-20 % ls | grep comm1    
comm1
admin@MacBook-Pro-Admin lab-20 % grep '123' file.txt
123
admin@MacBook-Pro-Admin lab-20 % grep 'fg' file.txt
admin@MacBook-Pro-Admin lab-20 % sort file.txt
123
543
admin@MacBook-Pro-Admin lab-20 % sort -r file.txt
543
123
admin@MacBook-Pro-Admin lab-20 % tail file.txt
123
543
admin@MacBook-Pro-Admin lab-20 % tail -n 1 file.txt
543
admin@MacBook-Pro-Admin lab-20 % od -b file.txt
0000000   061 062 063 012 065 064 063 012                                
0000010
admin@MacBook-Pro-Admin lab-20 % od file.txt
0000000    031061  005063  032065  005063                                
0000010
admin@MacBook-Pro-Admin lab-20 % od -c file.txt
0000000    1   2   3  \n   5   4   3  \n                                
0000010
admin@MacBook-Pro-Admin lab-20 % sum file.txt
33338 1 file.txt
admin@MacBook-Pro-Admin lab-20 % cat tee cut.txt
cat: tee: No such file or directory
cat: cut.txt: No such file or directory
admin@MacBook-Pro-Admin lab-20 % cat |& tee cut.txt
Winter
Winter
Summer
Summer
Autumn
Autumn
Spring
Spring
^Z
zsh: suspended  cat 2>&1 | tee cut.txt
admin@MacBook-Pro-Admin lab-20 % cut -b 5,8,17 cut.txt
e
e
m
n
admin@MacBook-Pro-Admin lab-20 % cut -b 5-8 cut.txt   
er
er
mn
ng
admin@MacBook-Pro-Admin lab-20 % tar -cf file.tar file.txt
admin@MacBook-Pro-Admin lab-20 % tar -xvf file.tar
x file.txt
admin@MacBook-Pro-Admin lab-20 % gzip file1.txt
admin@MacBook-Pro-Admin lab-20 % ed
P
*a
Первая строка
Вторая строка.
.
*W ed.txt
53
*q
admin@MacBook-Pro-Admin lab-20 % cat ed.txt
Первая строка
Вторая строка.
admin@MacBook-Pro-Admin lab-20 % bzip2 -k  ed.txt
admin@MacBook-Pro-Admin lab-20 % ls
README.md	comm2		ed.txt		file.tar	file1.txt.gz
comm1		cut.txt		ed.txt.bz2	file.txt
admin@MacBook-Pro-Admin lab-20 % bzip2 -d  ed.txt.bz2
bzip2: Output file ed.txt already exists.
admin@MacBook-Pro-Admin lab-20 % rm ed.txt
admin@MacBook-Pro-Admin lab-20 % bzip2 -d  ed.txt.bz2
admin@MacBook-Pro-Admin lab-20 % ls
README.md	comm2		ed.txt		file.txt
comm1		cut.txt		file.tar	file1.txt.gz
Last login: Fri Mar 17 15:18:27 on ttys000
admin@MacBook-Pro-Admin ~ % cd desktop/МАИ/первый/IT-разработка/mai_future_xr  
admin@MacBook-Pro-Admin mai_future_xr % cd ..
admin@MacBook-Pro-Admin IT-разработка % cd ..
admin@MacBook-Pro-Admin первый % cd лабы
admin@MacBook-Pro-Admin лабы % ды 
zsh: command not found: ды
admin@MacBook-Pro-Admin лабы % ls
Foundation-of-computer-science-DaniilGoryunov
KP3
KP4
Prikols
laba 13
laba11
laba12
laba14
laba15
laba8
laba9
labalaba11
labalaba14
musorka
~$звитие исторической науки в России.docx
admin@MacBook-Pro-Admin лабы % cd Foundation-of-computer-science-DaniilGoryunov
admin@MacBook-Pro-Admin Foundation-of-computer-science-DaniilGoryunov % cd lab-20
admin@MacBook-Pro-Admin lab-20 % touch README.md
admin@MacBook-Pro-Admin lab-20 % cat comm1
cat: comm1: No such file or directory
admin@MacBook-Pro-Admin lab-20 % cat >> com1
001
002
003
004
005
^Z
zsh: suspended  cat >> com1
admin@MacBook-Pro-Admin lab-20 % cat >> comm2
000
001
003
005
007
^Z
zsh: suspended  cat >> comm2
admin@MacBook-Pro-Admin lab-20 % comm comm1 comm2
	000
		001
002
		003
004
		005
	007
admin@MacBook-Pro-Admin lab-20 % comm -23 comm1 comm2
002
004
admin@MacBook-Pro-Admin lab-20 % comm -13 comm1 com2
comm: com2: No such file or directory
admin@MacBook-Pro-Admin lab-20 % comm -13 comm1 comm2
000
007
admin@MacBook-Pro-Admin lab-20 % comm -12 comm1 comm2
001
003
005
admin@MacBook-Pro-Admin lab-20 % cat |& tee file.txt
123
123
345
345
^Z
zsh: suspended  cat 2>&1 | tee file.txt
admin@MacBook-Pro-Admin lab-20 % cat file.txt
123
345
admin@MacBook-Pro-Admin lab-20 % cat |& tee file.txt
123
123
543
543
^Z
zsh: suspended  cat 2>&1 | tee file.txt
admin@MacBook-Pro-Admin lab-20 % cat |& tee file1.txt
123
123
345
345
^Z
zsh: suspended  cat 2>&1 | tee file1.txt
admin@MacBook-Pro-Admin lab-20 % cmp file.txt file1.txt
file.txt file1.txt differ: char 5, line 2
admin@MacBook-Pro-Admin lab-20 % cmp -l file.txt file1.txt
     5  65  63
     7  63  65
admin@MacBook-Pro-Admin lab-20 % wc file.txt
       2       2       8 file.txt
admin@MacBook-Pro-Admin lab-20 % wc -c file.txt
       8 file.txt
admin@MacBook-Pro-Admin lab-20 % wc -m file.txt
       8 file.txt
admin@MacBook-Pro-Admin lab-20 % wc -l file.txt
       2 file.txt
admin@MacBook-Pro-Admin lab-20 % wc -w file.txt
       2 file.txt
admin@MacBook-Pro-Admin lab-20 % diff file.txt file1.txt
2c2
< 543
---
> 345
admin@MacBook-Pro-Admin lab-20 % ls | grep Documents
admin@MacBook-Pro-Admin lab-20 % ls | grep comm1    
comm1
admin@MacBook-Pro-Admin lab-20 % grep '123' file.txt
123
admin@MacBook-Pro-Admin lab-20 % grep 'fg' file.txt
admin@MacBook-Pro-Admin lab-20 % sort file.txt
123
543
admin@MacBook-Pro-Admin lab-20 % sort -r file.txt
543
123
admin@MacBook-Pro-Admin lab-20 % tail file.txt
123
543
admin@MacBook-Pro-Admin lab-20 % tail -n 1 file.txt
543
admin@MacBook-Pro-Admin lab-20 % od -b file.txt
0000000   061 062 063 012 065 064 063 012                                
0000010
admin@MacBook-Pro-Admin lab-20 % od file.txt
0000000    031061  005063  032065  005063                                
0000010
admin@MacBook-Pro-Admin lab-20 % od -c file.txt
0000000    1   2   3  \n   5   4   3  \n                                
0000010
admin@MacBook-Pro-Admin lab-20 % sum file.txt
33338 1 file.txt
admin@MacBook-Pro-Admin lab-20 % cat tee cut.txt
cat: tee: No such file or directory
cat: cut.txt: No such file or directory
admin@MacBook-Pro-Admin lab-20 % cat |& tee cut.txt
Winter
Winter
Summer
Summer
Autumn
Autumn
Spring
Spring
^Z
zsh: suspended  cat 2>&1 | tee cut.txt
admin@MacBook-Pro-Admin lab-20 % cut -b 5,8,17 cut.txt
e
e
m
n
admin@MacBook-Pro-Admin lab-20 % cut -b 5-8 cut.txt   
er
er
mn
ng
admin@MacBook-Pro-Admin lab-20 % tar -cf file.tar file.txt
admin@MacBook-Pro-Admin lab-20 % tar -xvf file.tar
x file.txt
admin@MacBook-Pro-Admin lab-20 % gzip file1.txt
admin@MacBook-Pro-Admin lab-20 % ed
P
*a
Первая строка
Вторая строка.
.
*W ed.txt
53
*q
admin@MacBook-Pro-Admin lab-20 % cat ed.txt
Первая строка
Вторая строка.
admin@MacBook-Pro-Admin lab-20 % bzip2 -k  ed.txt
admin@MacBook-Pro-Admin lab-20 % ls
README.md	comm2		ed.txt		file.tar	file1.txt.gz
comm1		cut.txt		ed.txt.bz2	file.txt
admin@MacBook-Pro-Admin lab-20 % bzip2 -d  ed.txt.bz2
bzip2: Output file ed.txt already exists.
admin@MacBook-Pro-Admin lab-20 % rm ed.txt
admin@MacBook-Pro-Admin lab-20 % bzip2 -d  ed.txt.bz2
admin@MacBook-Pro-Admin lab-20 % ls
README.md	comm2		ed.txt		file.txt
comm1		cut.txt		file.tar	file1.txt.gz
admin@MacBook-Pro-Admin lab-20 % clear

admin@MacBook-Pro-Admin lab-20 % head man
head: man: No such file or directory
admin@MacBook-Pro-Admin lab-20 % man head
admin@MacBook-Pro-Admin lab-20 % head -n 1 ed.txt
Первая строка
admin@MacBook-Pro-Admin lab-20 % head  ed.txt    
Первая строка
Вторая строка.
admin@MacBook-Pro-Admin lab-20 % file ed.txt  
ed.txt: Unicode text, UTF-8 text
admin@MacBook-Pro-Admin lab-20 % iconv -f UTF-8 -t ASCII ed.txt
iconv: ed.txt:1:0: cannot convert
admin@MacBook-Pro-Admin lab-20 % iconv -x ASCII  ed.txt        
Usage: iconv [-c] [-s] [-f fromcode] [-t tocode] [file ...]
or:    iconv -l
Try `iconv --help' for more information.
admin@MacBook-Pro-Admin lab-20 % uniq ed.txt           
Первая строка
Вторая строка.
admin@MacBook-Pro-Admin lab-20 % uniq -c file.txt
   1 123
   1 543
admin@MacBook-Pro-Admin lab-20 % df
Filesystem     512-blocks      Used Available Capacity iused      ifree %iused  Mounted on
/dev/disk3s1s1  965595304  23022512 611386632     4%  348574 3056933160    0%   /
devfs                 408       408         0   100%     706          0  100%   /dev
/dev/disk3s6    965595304   6291496 611386632     2%       3 3056933160    0%   /System/Volumes/VM
/dev/disk3s2    965595304  18400232 611386632     3%    1124 3056933160    0%   /System/Volumes/Preboot
/dev/disk3s4    965595304   1229752 611386632     1%     276 3056933160    0%   /System/Volumes/Update
/dev/disk1s2      1024000     12328    988232     2%       1    4941160    0%   /System/Volumes/xarts
/dev/disk1s1      1024000     12664    988232     2%      48    4941160    0%   /System/Volumes/iSCPreboot
/dev/disk1s3      1024000      1056    988232     1%      52    4941160    0%   /System/Volumes/Hardware
/dev/disk3s5    965595304 301930384 611386632    34% 1560196 3056933160    0%   /System/Volumes/Data
map auto_home           0         0         0   100%       0          0  100%   /System/Volumes/Data/home
/dev/disk5s1      8069120   7585864    451256    95%  273178    2256280   11%   /Library/Developer/CoreSimulator/Volumes/watchOS_20S75
/dev/disk2s1     10485672   3282616   7164136    32%      60   35820680    0%   /System/Volumes/Update/SFR/mnt1
/dev/disk3s1    965595304  23022512 611386632     4%  349477 3056933160    0%   /System/Volumes/Update/mnt1
admin@MacBook-Pro-Admin lab-20 % fd -h
A program to find entries in your filesystem

Usage: fd [OPTIONS] [pattern] [path]...

Arguments:
  [pattern]  the search pattern (a regular expression, unless '--glob' is used;
             optional)
  [path]...  the root directories for the filesystem search (optional)

Options:
  -H, --hidden
          Search hidden files and directories
  -I, --no-ignore
          Do not respect .(git|fd)ignore files
  -s, --case-sensitive
          Case-sensitive search (default: smart case)
  -i, --ignore-case
          Case-insensitive search (default: smart case)
  -g, --glob
          Glob-based search (default: regular expression)
  -a, --absolute-path
          Show absolute instead of relative paths
  -l, --list-details
          Use a long listing format with file metadata
  -L, --follow
          Follow symbolic links
  -p, --full-path
          Search full abs. path (default: filename only)
  -d, --max-depth <depth>
          Set maximum search depth (default: none)
  -E, --exclude <pattern>
          Exclude entries that match the given glob pattern
  -t, --type <filetype>
          Filter by type: file (f), directory (d), symlink (l), executable (x),
          empty (e), socket (s), pipe (p)
  -e, --extension <ext>
          Filter by file extension
  -S, --size <size>
          Limit results based on the size of files
      --changed-within <date|dur>
          Filter by file modification time (newer than)
      --changed-before <date|dur>
          Filter by file modification time (older than)
  -o, --owner <user:group>
          Filter by owning user and/or group
  -x, --exec <cmd>...
          Execute a command for each search result
  -X, --exec-batch <cmd>...
          Execute a command with all search results at once
  -c, --color <when>
          When to use colors [default: auto] [possible values: auto, always,
          never]
  -h, --help
          Print help information (use `--help` for more detail)
  -V, --version
          Print version information
admin@MacBook-Pro-Admin lab-20 % df -h
Filesystem       Size   Used  Avail Capacity iused      ifree %iused  Mounted on
/dev/disk3s1s1  460Gi   11Gi  292Gi     4%  348574 3056926720    0%   /
devfs           204Ki  204Ki    0Bi   100%     706          0  100%   /dev
/dev/disk3s6    460Gi  3.0Gi  292Gi     2%       3 3056926720    0%   /System/Volumes/VM
/dev/disk3s2    460Gi  8.8Gi  292Gi     3%    1124 3056926720    0%   /System/Volumes/Preboot
/dev/disk3s4    460Gi  600Mi  292Gi     1%     276 3056926720    0%   /System/Volumes/Update
/dev/disk1s2    500Mi  6.0Mi  483Mi     2%       1    4941160    0%   /System/Volumes/xarts
/dev/disk1s1    500Mi  6.2Mi  483Mi     2%      48    4941160    0%   /System/Volumes/iSCPreboot
/dev/disk1s3    500Mi  528Ki  483Mi     1%      52    4941160    0%   /System/Volumes/Hardware
/dev/disk3s5    460Gi  144Gi  292Gi    34% 1560204 3056926720    0%   /System/Volumes/Data
map auto_home     0Bi    0Bi    0Bi   100%       0          0  100%   /System/Volumes/Data/home
/dev/disk5s1    3.8Gi  3.6Gi  220Mi    95%  273178    2256280   11%   /Library/Developer/CoreSimulator/Volumes/watchOS_20S75
/dev/disk2s1    5.0Gi  1.6Gi  3.4Gi    32%      60   35820680    0%   /System/Volumes/Update/SFR/mnt1
/dev/disk3s1    460Gi   11Gi  292Gi     4%  349477 3056926720    0%   /System/Volumes/Update/mnt1
admin@MacBook-Pro-Admin lab-20 % df -x 
df: illegal option -- x
usage: df [-b | -H | -h | -k | -m | -g | -P] [-ailn] [-T type] [-t] [filesystem ...]
admin@MacBook-Pro-Admin lab-20 % df -x tmpfs
df: illegal option -- x
usage: df [-b | -H | -h | -k | -m | -g | -P] [-ailn] [-T type] [-t] [filesystem ...]
admin@MacBook-Pro-Admin lab-20 % mktemp
/var/folders/6z/cgq_7n215yg5gpdx3dwnwwzc0000gn/T/tmp.ZQDR4YCi
admin@MacBook-Pro-Admin lab-20 % rm /var/folders/6z/cgq_7n215yg5gpdx3dwnwwzc0000gn/T/tmp.ZQDR4YCi
admin@MacBook-Pro-Admin lab-20 % 

```

## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 18.03.23 | 8:00 | Выполнение лабораторной работы | - | - |
## 10. Замечания автора по существу работы

<b>Защита</b> 

## 11. Выводы
Было выяснено, что OC UNIX не только имеет прекрасные средства программирования, но и обладает массой простых утилит, позволяющих выполнять многие сложные работы с файлами без программирования путем последовательного и конвейерного выполнения этих программ. Были изучены некоторые из них. В результате выполнения работы, были приобретены навыки, которые будут полезны для выполнения других лабораторных работ и курсовых проектов.

Недочёты при выполнении задания могут быть устранены следующим образом: —

<b>Подпись студента:</b> _________________
