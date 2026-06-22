# Лабораторная работа: Основы интерфейса взаимодействия пользователя с системой Unix на уровне командной строки

## Студент
- **ФИО:** Хайдаров Олим Фирдавcович
- **Группа:** НБИбд-02-25
- **Студ.билет:** 1032242468
- **Дата выполнения:** 21 марта 2026

---

## Цель работы

Приобретение практических навыков взаимодействия пользователя с системой по-
средством командной строки.

## Указания к работе

В операционной системе типа Linux взаимодействие пользователя с системой обычно
осуществляется с помощью командной строки посредством построчного ввода ко-
манд. 

При этом обычно используется командные интерпретаторы языка shell: 
/bin/sh; /bin/csh; /bin/ksh.

# Формат команды. 

Командой в операционной системе называется записанный по специальным правилам текст (возможно с аргументами), представляющий собой указание на выполнение какой-либо функций (или действий) в операционной системе.
Обычно первым словом идёт имя команды, остальной текст — аргументы или опции, конкретизирующие действие.

Общий формат команд можно представить следующим образом:
<имя_команды><разделитель><аргументы>

Команда man. Команда man используется для просмотра (оперативная помощь) в диалоговом режиме руководства (manual) по основным командам операционной системы типа Linux.

Формат команды:

man <команда>
Пример (вывод информации о команде man):
1 man man

Для управления просмотром результата выполнения команды man можно использовать следующие клавиши:
– Space — перемещение по документу на одну страницу вперёд;
– Enter — перемещение по документу на одну строку вперёд;
– q — выход из режима просмотра описания.
Команда cd. Команда cd используется для перемещения по файловой системе операционной системы типа Linux.

# Замечание 1. Файловая система ОС типа Linux — иерархическая система каталогов, подкаталогов и файлов, которые обычно организованы и сгруппированы по функциональному признаку. Самый верхний каталог в иерархии называется корневым и обозначается символом /. Корневой каталог содержит системные файлы и другие каталоги.
# Формат команды:
cd [путь_к_каталогу]
Кулябов Д. С. и др. Операционные системы 39
Для перехода в домашний каталог пользователя следует использовать команду cd без параметров или cd ~.
Например, команда

1 cd /afs/dk.sci.pfu.edu.ru/home - позволяет перейти в каталог /afs/dk.sci.pfu.edu.ru/home (если такой существует), а для того, чтобы подняться выше на одну директорию, следует использовать:

1 cd ..
Подробнее об опциях команды cd смотри в справке с помощью команды man:
1 man cd
Команда pwd. Для определения абсолютного пути к текущему каталогу используется команда pwd (print working directory). Пример (абсолютное имя текущего каталога пользователя dharma):
1 pwd
результат:
1 /afs/dk.sci.pfu.edu.ru/home/d/h/dharma

# Замечание 2
Сокращения имён файлов. В работе с командами, в качестве аргументов которых выступает путь к какому-либо каталогу или файлу, можно использовать сокращённую запись пути. Символы сокращения приведены в табл. 4.1.

# Таблица 4.1
Символы сокращения имён файлов

Символ Значение
~ Домашний каталог
. Текущий каталог
.. Родительский каталог

Например, в команде cd для перемещения по файловой системе сокращённую запись пути можно использовать следующим образом (команды чередуются с выводом результата выполнения команды pwd):

1 pwd
2
3 /afs/dk.sci.pfu.edu.ru/home/d/h/dharma
4
40 Лабораторная работа № 4. Основы интерфейса взаимодействия пользователя с системой …
5 cd ..
6 pwd
7
8 /afs/dk.sci.pfu.edu.ru/home/d/h
9
10 cd ../..
11 pwd
12
13 /afs/dk.sci.pfu.edu.ru/home
14
15 cd ~/work
16 pwd
17
18 /afs/dk.sci.pfu.edu.ru/home/d/h/dharma/work

Команда ls. Команда ls используется для просмотра содержимого каталога.
Формат команды:
ls [-опции] [путь]
Пример:
1 cd
2 cd ..
3 pwd
4
5 /afs/dk.sci.pfu.edu.ru/home/d/h
6
7 ls
8
9 dharma

Некоторые файлы в операционной системе скрыты от просмотра и обычно используются для настройки рабочей среды. Имена таких файлов начинаются с точки. Для того, чтобы отобразить имена скрытых файлов, необходимо использовать команду ls с опцией a:
1 ls -a

Можно также получить информацию о типах файлов (каталог, исполняемый файл, ссылка), для чего используется опция F. При использовании этой опции в поле имени выводится символ, который определяет тип файла (см. табл. 4.2)

#Таблица 4.2
Символ, который определяет тип файла
Тип файла Символ
Каталог /
Исполняемый файл *
Ссылка @

Чтобы вывести на экран подробную информацию о файлах и каталогах, необходимо использовать опцию l. При этом о каждом файле и каталоге будет выведена следующая информация:
– тип файла,
– право доступа,
– число ссылок,
– владелец,
– размер,
– дата последней ревизии,
– имя файла или каталога.

Пример:
1 cd /
2 ls
Результат:
1 bin boot dev etc home lib media mnt
2 opt proc root sbin sys tmp usr var
В этом же каталоге команда
1 ls -alF - даст примерно следующий результат:
1 drwxr-xr-x 21 root root 4096 Jan. 17 09:00 ./
2 drwxr-xr-x 21 root root 4096 Jan. 17 09:00 ../
3 drwxr-xr-x 2 root root 4096 Jan. 18 15:57 bin/
4 drwxr-xr-x 2 root root 4096 Apr. 14 2008 boot/
5 drwxr-xr-x 20 root root 14120 Feb. 17 10:48 dev/
6 drwxr-xr-x 170 root root 12288 Feb. 17 09:19 etc/
7 drwxr-xr-x 6 root root 4096 Aug. 5 2009 home/
8 lrwxrwxrwx 1 root root 5 Jan. 12 22:01 lib -> lib64/
9 drwxr-xr-x 8 root root 4096 Jan. 30 21:41 media/
10 drwxr-xr-x 5 root root 4096 Jan. 17 2010 mnt/
11 drwxr-xr-x 25 root root 4096 Jan. 16 09:55 opt/
12 dr-xr-xr-x 163 root root 0 Feb. 17 13:17 proc/
13 drwxr-xr-x 31 root root 4096 Feb. 15 23:57 root/
14 drwxr-xr-x 2 root root 12288 Jan. 18 15:57 sbin/
15 drwxr-xr-x 12 root root 0 Feb. 17 13:17 sys/
16 drwxrwxrwt 12 root root 500 Feb. 17 16:35 tmp/
17 drwxr-xr-x 22 root root 4096 Jan. 18 09:26 usr/
18 drwxr-xr-x 17 root root 4096 Jan. 14 17:38 var/

## Команда mkdir. Команда mkdir используется для создания каталогов.

Формат команды:
mkdir имя_каталога1 [имя_каталога2...]

# Пример создания каталога в текущем каталоге:

1 cd
2 pwd
3
4 /afs/dk.sci.pfu.edu.ru/home/d/h/dharma
5
6 ls
7
8 Desktop public tmp
9 GNUstep public_html work
10
11 mkdir abc
12 ls
13
14 abc GNUstep public_html work
15 Desktop public tmp

# Замечание 2. 
Для того чтобы создать каталог в определённом месте файловой системы, должны быть правильно установлены права доступа. Можно создать также подкаталог в существующем подкаталоге:

1 mkdir parentdir
2 mkdir parentdir/dir

При задании нескольких аргументов создаётся несколько каталогов:
1 cd parentdir
2 mkdir dir1 dir2 dir3

Можно использовать группировку:
1 mkdir parentdir/{dir1,dir2,dir3}

Если же требуется создать подкаталог в каталоге, отличном от текущего, то путь к нему требуется указать в явном виде:
1 mkdir ../dir1/dir2

или

1 mkdir ~/dir1/dir2

Интересны следующие опции:
--mode (или -m) — установка атрибутов доступа;
--parents (или -p) — создание каталога вместе с родительскими по отношению к нему каталогами.

Атрибуты задаются в численной или символьной нотации:
1 mkdir --mode=777 dir

или

1 mkdir -m a+rwx dir
Опция --parents (краткая форма -p) позволяет создавать иерархическую цепочку подкаталогов, создавая все промежуточные каталоги:

1 mkdir -p ~/dir1/dir2/dir3


# Команда rm. 

Команда rm используется для удаления файлов и/или каталогов.
Формат команды:
rm [-опции] [файл]

Если требуется, чтобы выдавался запрос подтверждения на удаление файла, то необхо-
димо использовать опцию i.

Чтобы удалить каталог, содержащий файлы, нужно использовать опцию r. Без указания
этой опции команда не будет выполняться.

Пример:
1 cd
2 mkdir abs
3 rm abc
4
5 rm: abc is a directory
6
7 rm -r abc

Если каталог пуст, то можно воспользоваться командой rmdir. Если удаляемый каталог содержит файлы, то команда не будет выполнена — нужно использовать rm -r имя_каталога.

# Команда history. 

Для вывода на экран списка ранее выполненных команд используется команда history. Выводимые на экран команды в списке нумеруются. К любой команде из выведенного на экран списка можно обратиться по её номеру в списке, воспользовавшись конструкцией !<номер_команды>.

Пример:
1 history
2 1 pwd
3 2 ls
4 3 ls -a
5 4 ls -l
6 5 cd /
7 6 history
8
9 !5
10 cd /

Можно модифицировать команду из выведенного на экран списка при помощи следу-
ющей конструкции:

!<номер_команды>:s/<что_меняем>/<на_что_меняем>

Пример:
1 !3:s/a/F
2 ls -F

# Замечание 3. 

Если в заданном контексте встречаются специальные символы (типа «.», «/», «*» и т.д.), надо перед ними поставить символ экранирования \ (обратный слэш).
Использование символа «;». Если требуется выполнить последовательно несколько
команд, записанный в одной строке, то для этого используется символ точка с запятой
Пример:
1 cd; ls


### Выполнение лабораторной работы


**Команда:**
```bash
pwd

Результат:

/home/ofkhayjdarovdk5n18/Desktop


## Задание 2. Работа с каталогами и командой ls
# 2.1. Переход в каталог /tmp

fkhayjdarovdk5n18@fedora:~$ cd
ofkhayjdarovdk5n18@fedora:~$ cd /tmp
ofkhayjdarovdk5n18@fedora:/tmp$ pwd
/tmp

# 2.2. Вывод содержимого с различными опциями

Команда
	
ls

ofkhayjdarovdk5n18@fedora:/tmp$ ls
systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-abrtd.service-fyGS2w               systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-passim.service-kdrmkU
systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-chronyd.service-KmTBbS             systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-pcscd.service-UVsw0G
systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-colord.service-DyeIFB              systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-polkit.service-6BQVNx
systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-dbus-broker.service-nf4EyN         systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-rtkit-daemon.service-KJVwl4
systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-fwupd.service-5NL98H               systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-switcheroo-control.service-7Nlp8z
systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-geoclue.service-iMyk9H             systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-systemd-logind.service-ebsz8w
systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-irqbalance.service-6fozTr          systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-systemd-resolved.service-2NiRv7
systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-low-memory-monitor.service-GWXeSj  systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-upower.service-Fllc9u
systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-ModemManager.service-IXaoTy
	
Простой список файлов



ls -a

ofkhayjdarovdk5n18@fedora:/tmp$ ls -a
.                                                                                   systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-ModemManager.service-IXaoTy
..                                                                                  systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-passim.service-kdrmkU
.font-unix                                                                          systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-pcscd.service-UVsw0G
.ICE-unix                                                                           systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-polkit.service-6BQVNx
.iprt-localipc-DRMIpcServer                                                         systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-rtkit-daemon.service-KJVwl4
systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-abrtd.service-fyGS2w               systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-switcheroo-control.service-7Nlp8z
systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-chronyd.service-KmTBbS             systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-systemd-logind.service-ebsz8w
systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-colord.service-DyeIFB              systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-systemd-resolved.service-2NiRv7
systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-dbus-broker.service-nf4EyN         systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-upower.service-Fllc9u
systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-fwupd.service-5NL98H               .X0-lock
systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-geoclue.service-iMyk9H             .X11-unix
systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-irqbalance.service-6fozTr          .X1-lock
systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-low-memory-monitor.service-GWXeSj  .XIM-unix

Показывает скрытые файлы (начинающиеся с .)


ls -l

ofkhayjdarovdk5n18@fedora:/tmp$ ls -l
total 0
drwx------. 3 root root 60 Mar 21 13:05 systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-abrtd.service-fyGS2w
drwx------. 3 root root 60 Mar 21 13:05 systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-chronyd.service-KmTBbS
drwx------. 3 root root 60 Mar 21 13:06 systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-colord.service-DyeIFB
drwx------. 3 root root 60 Mar 21 13:05 systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-dbus-broker.service-nf4EyN
drwx------. 3 root root 60 Mar 21 13:06 systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-fwupd.service-5NL98H
drwx------. 3 root root 60 Mar 21 13:06 systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-geoclue.service-iMyk9H
drwx------. 3 root root 60 Mar 21 13:05 systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-irqbalance.service-6fozTr
drwx------. 3 root root 60 Mar 21 13:05 systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-low-memory-monitor.service-GWXeSj
drwx------. 3 root root 60 Mar 21 13:05 systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-ModemManager.service-IXaoTy
drwx------. 3 root root 60 Mar 21 13:07 systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-passim.service-kdrmkU
drwx------. 3 root root 60 Mar 21 13:06 systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-pcscd.service-UVsw0G
drwx------. 3 root root 60 Mar 21 13:05 systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-polkit.service-6BQVNx
drwx------. 3 root root 60 Mar 21 13:05 systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-rtkit-daemon.service-KJVwl4
drwx------. 3 root root 60 Mar 21 13:05 systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-switcheroo-control.service-7Nlp8z
drwx------. 3 root root 60 Mar 21 13:05 systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-systemd-logind.service-ebsz8w
drwx------. 3 root root 60 Mar 21 13:05 systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-systemd-resolved.service-2NiRv7
drwx------. 3 root root 60 Mar 21 13:05 systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-upower.service-Fllc9u

Подробный список (права, владелец, размер, дата)



ls -F

ofkhayjdarovdk5n18@fedora:/tmp$ ls -F
systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-abrtd.service-fyGS2w/               systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-passim.service-kdrmkU/
systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-chronyd.service-KmTBbS/             systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-pcscd.service-UVsw0G/
systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-colord.service-DyeIFB/              systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-polkit.service-6BQVNx/
systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-dbus-broker.service-nf4EyN/         systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-rtkit-daemon.service-KJVwl4/
systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-fwupd.service-5NL98H/               systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-switcheroo-control.service-7Nlp8z/
systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-geoclue.service-iMyk9H/             systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-systemd-logind.service-ebsz8w/
systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-irqbalance.service-6fozTr/          systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-systemd-resolved.service-2NiRv7/
systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-low-memory-monitor.service-GWXeSj/  systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-upower.service-Fllc9u/
systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-ModemManager.service-IXaoTy/

Добавляет символы типов файлов (/, *, @)


ls -alF

ofkhayjdarovdk5n18@fedora:/tmp$ ls -aIF
.                                                                                   systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-ModemManager.service-IXaoTy
..                                                                                  systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-passim.service-kdrmkU
.font-unix                                                                          systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-pcscd.service-UVsw0G
.ICE-unix                                                                           systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-polkit.service-6BQVNx
.iprt-localipc-DRMIpcServer                                                         systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-rtkit-daemon.service-KJVwl4
systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-abrtd.service-fyGS2w               systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-switcheroo-control.service-7Nlp8z
systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-chronyd.service-KmTBbS             systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-systemd-logind.service-ebsz8w
systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-colord.service-DyeIFB              systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-systemd-resolved.service-2NiRv7
systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-dbus-broker.service-nf4EyN         systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-upower.service-Fllc9u
systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-fwupd.service-5NL98H               .X0-lock
systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-geoclue.service-iMyk9H             .X11-unix
systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-irqbalance.service-6fozTr          .X1-lock
systemd-private-748dbe0c7a2c410ea1c54df8cc0dfff5-low-memory-monitor.service-GWXeSj  .XIM-unix

	
Комбинация всех опций


# 2.3. Проверка подкаталога cron в /var/spool

ofkhayjdarovdk5n18@fedora:/tmp$ ls /var/spool
abrt  abrt-upload  anacron  at  cron  cups  lpd  mail  plymouth


Ответ: Да, cron присутствует в подкаталоге 


# 2.4. Переход в домашний каталог и определение владельца

ofkhayjdarovdk5n18@fedora:~/Desktop$ cd ~
ofkhayjdarovdk5n18@fedora:~$ ls -l
total 32
drwxr-xr-x. 1 ofkhayjdarovdk5n18 ofkhayjdarovdk5n18   264 Mar 14 23:02 Desktop
drwxr-xr-x. 1 ofkhayjdarovdk5n18 ofkhayjdarovdk5n18     0 Mar  9 00:28 Documents
drwxr-xr-x. 1 ofkhayjdarovdk5n18 ofkhayjdarovdk5n18    34 Mar 15 00:03 Downloads
-rw-r--r--. 1 ofkhayjdarovdk5n18 ofkhayjdarovdk5n18 18657 Mar 14 21:53 LICENSE
-rw-r--r--. 1 ofkhayjdarovdk5n18 ofkhayjdarovdk5n18  9442 Mar 21 13:31 -lt
drwxr-xr-x. 1 ofkhayjdarovdk5n18 ofkhayjdarovdk5n18     0 Mar  9 00:28 Music
drwxr-xr-x. 1 ofkhayjdarovdk5n18 ofkhayjdarovdk5n18    22 Mar 14 23:14 Pictures
drwxr-xr-x. 1 ofkhayjdarovdk5n18 ofkhayjdarovdk5n18     0 Mar  9 00:28 Public
drwxr-xr-x. 1 ofkhayjdarovdk5n18 ofkhayjdarovdk5n18     0 Mar  9 00:28 Templates
drwxr-xr-x. 1 ofkhayjdarovdk5n18 ofkhayjdarovdk5n18     0 Mar  9 00:28 Videos
ofkhayjdarovdk5n18@fedora:~$ 


Владелец файлов: мой username - ofkhayjdarovdk5n18@fedora  (третий столбец в выводе ls -l)



## Задание 3. Создание и удаление каталогов
# 3.1. Создание каталога newdir

ofkhayjdarovdk5n18@fedora:~$ cd ~
ofkhayjdarovdk5n18@fedora:~$ mkdir newdir
ofkhayjdarovdk5n18@fedora:~$ ls
Desktop  Documents  Downloads  LICENSE  Music  newdir  Pictures  Public  Templates  Videos


# 3.2. Создание каталога morefun

ofkhayjdarovdk5n18@fedora:~$ mkdir ~/newdir/morefun
ofkhayjdarovdk5n18@fedora:~$ mkdir letters memos misk
ofkhayjdarovdk5n18@fedora:~$ ls
Desktop  Documents  Downloads  letters  LICENSE  memos  misk  Music  newdir  Pictures  Public  Templates  Videos



# 3.3. Создание и удаление трёх каталогов одной командой

ofkhayjdarovdk5n18@fedora:~$ rmdir letters memos misk
ofkhayjdarovdk5n18@fedora:~$ ls
Desktop  Documents  Downloads  LICENSE  Music  newdir  Pictures  Public  Templates  Videos


# 3.4. Попытка удаления каталога командой rm

ofkhayjdarovdk5n18@fedora:~$ rm ~/newdir
rm: cannot remove '/home/ofkhayjdarovdk5n18/newdir': Is a directory


Результат: Ошибка rm: cannot remove '/home/ofkhayjdarovdk5n18/newdir': Is a directory
Вывод: Для удаления каталога требуется опция -r: rm -r ~/newdir


# 3.5. Удаление каталога ~/newdir/morefun

ofkhayjdarovdk5n18@fedora:~$ rm -r ~/newdir
ofkhayjdarovdk5n18@fedora:~$ ls
Desktop  Documents  Downloads  LICENSE  Music  Pictures  Public  Templates  Videos


## Задание 4. Опция рекурсивного просмотра ls

Команда для поиска:

ofkhayjdarovdk5n18@fedora:~$ man ls

ofkhayjdarovdk5n18@fedora:~$


Опция -R (recursive) позволяет просматривать содержимое подкаталогов.

Пример:

ofkhayjdarovdk5n18@fedora:~$ ls -R
.:
Desktop  Documents  Downloads  LICENSE  -lt  Music  Pictures  Public  Templates  Videos

./Desktop:
bin  home  home.pub  lab05-report.docx  lab05-report.html  lab05-report.md  lab5-report.docx  lab5-report.html  lab5-report.md  missfont.log  Start.java

./Desktop/bin:
chezmoi  lab05-report.html.pdf

./Documents:

./Downloads:
004-lab_shell.pdf

./Music:

./Pictures:
Screenshots

./Pictures/Screenshots:
'Screenshot From 2026-03-14 23-14-11.png'  'Screenshot From 2026-03-21 14-59-48.png'

./Public:

./Templates:

./Videos:



# Задание 5. Сортировка по времени с подробным описанием

Найденные опции:

    -l — развёрнутое описание
    -t — сортировка по времени изменения

Итоговая команда:

ofkhayjdarovdk5n18@fedora:~$ ls -lt
total 32
-rw-r--r--. 1 ofkhayjdarovdk5n18 ofkhayjdarovdk5n18  9442 Mar 21 13:31 -lt
drwxr-xr-x. 1 ofkhayjdarovdk5n18 ofkhayjdarovdk5n18    34 Mar 15 00:03 Downloads
drwxr-xr-x. 1 ofkhayjdarovdk5n18 ofkhayjdarovdk5n18    22 Mar 14 23:14 Pictures
drwxr-xr-x. 1 ofkhayjdarovdk5n18 ofkhayjdarovdk5n18   264 Mar 14 23:02 Desktop
-rw-r--r--. 1 ofkhayjdarovdk5n18 ofkhayjdarovdk5n18 18657 Mar 14 21:53 LICENSE
drwxr-xr-x. 1 ofkhayjdarovdk5n18 ofkhayjdarovdk5n18     0 Mar  9 00:28 Documents
drwxr-xr-x. 1 ofkhayjdarovdk5n18 ofkhayjdarovdk5n18     0 Mar  9 00:28 Music
drwxr-xr-x. 1 ofkhayjdarovdk5n18 ofkhayjdarovdk5n18     0 Mar  9 00:28 Public
drwxr-xr-x. 1 ofkhayjdarovdk5n18 ofkhayjdarovdk5n18     0 Mar  9 00:28 Templates
drwxr-xr-x. 1 ofkhayjdarovdk5n18 ofkhayjdarovdk5n18     0 Mar  9 00:28 Videos


# Задание 6. Изучение команд через man

Команда 		Основные опции			Описание
cd			~, .., -			Переход в домашний/родительский/предыдущий каталог
pwd			-P, -L				Вывод абсолютного пути (физический/логический)
mkdir			-p, -m				Создание родительских каталогов/установка прав
rmdir			-p				Удаление пустых каталогов
rm			-i, -r, -f			Запрос подтверждения/рекурсивно/принудительно



# Задание 7. Работа с историей команд

Просмотр истории:

ofkhayjdarovdk5n18@fedora:~$ history
    1  sudo
    2  pwd
    3  ls
    4  cd Desctop
    5  cd Desktop
    6  touch [1..3].txt 
    7  pwd
    8  ls
    9  rm [1..3].txt
   10  ls
   11  cls
   12  clear
   13  cls
   14  clls
   15  mc
   16  dir
   17  rm -rf doc
   18  dir
   19  ls
   20  clear
   21  ls 
   22  quit
   23  exit
   24  bash 
   25  bash
   26  ls
   27  javac Start.java
   28  javac
   29  wich java
   30  java Start.java
   31  vim
   32  ls
   33  mkdir java
   34  ls
   35  rm -rf java
   36  ls
   37  dnf copr enable maximbaz/browserpass
   38  dnf install browserpass
   39  emerge www-plugins/browserpass
   40  sudo dnf copr enable maximbaz/browserpass
   41  sudo dnf install browserpass
   42  pass insert [OPTIONAL DIR]/[FILENAME]
   43  pass [OPTIONAL DIR]/[FILENAME]
   44  pass [--echo,-e | --multiline,-m] [--force,-f]
   45  [--echo,-e | --multiline,-m] [--force,-f]/[FILENAME]
   46  pass [OPTIONAL DIR]/[FILENAME]
   47  pass generate --in-place FILENAME
   48  pass [OPTIONAL DIR]/[FILENAME]
   49  pass insert email/gmail.com
   50  gpg --list-secret-list
   51  gpg --list-secret-keys
   52  gpg --full-generate-key
   53  gpg --list-secret-keys
   54  pass init 1032242468@rudn.ru
   55  pass insert github.com
   56  pass email/gmail.com
   57  pass github.com
   58  pass insert email/gmail.com
   59  pass
   60  pass generate --in-place FILENAME
   61  pass generate --in-place github.com
   62  chezmoi init https://github.com/<username>/dotfiles.git
   63  chezmoi init https://github.com/OlimKhai/dotfiles.git
   64  chezmoi diff
   65  chezmoi apply -v
   66  chezmoi init --apply https://github.com/OlimKhai/dotfiles.git
   67  chezmoi update
   68  git pull --autostash --rebase
   69  chezmoi git pull -- --autostash --rebase
   70  chezmoi apply
   71  chezmoi git pull -- --autostash --rebase && chezmoi diff
   72  chezmoi apply
   73  nano ~/.config/chezmoi/chezmoi.toml
   74  chezmoi add ~/.bashrc
   75  sudo dnf -y install dunst fontawesome-fonts powerline-fonts light /
   76  sudo dnf -y install dunst fontawesome-fonts powerline-fonts light fuzzel swaylock kitty waybar swaybg wl-clipboard mpv grim slurp
   77  sudo dnf copr enable peterwu/iosevka
   78  sudo dnf search iosevka
   79  sudo dnf install iosevka-fonts iosevka-aile-fonts iosevka-curly-fonts iosevka-slab-fonts iosevka-etoile-fonts iosevka-term-fonts
   80  sh -c "$(wget -qO- chezmoi.io/get)"
   81  gh repo create dotfiles --template="yamadharma/dotfiles-template" --private
   82  chezmoi init git@github.com:OlimKhai/dotfiles.git
   83  chezmoi init https://github.com/OlimKhai/dotfiles.git
   84  sudo dnf install gh
   85  gh auth login
   86  gh repo create dotfiles --private
   87  gh repo create dotfiles --template="yamadharma/dotfiles-template" --private
   88  gh repo delete OlimKhai/dotfiles --confirm
   89  gh auth refresh -h github.com -s delete_repo
   90  gh repo delete OlimKhai/dotfiles
   91  gh repo create dotfiles --template="yamadharma/dotfiles-template" --private
   92  chezmoi init git@github.com:<OlimKhai>/dotfiles.git
   93  chezmoi init git@github.com:OlimKhai/dotfiles.git
   94  chezmoi diff
   95  chezmoi apply -v
   96  chezmoi init --apply https://github.com/<username>/dotfiles.git
   97  chezmoi init --apply https://github.com/OlimKhai/dotfiles.git
   98  nano lab-report.md
   99  sudo dnf install pandoc
  100  pandoc lab5-report.md -o lab5-report.html
  101  pandoc lab5-report.md -o lab5-report.pdf
  102  sudo dnf install pdflatex
  103  pandoc lab5-report.md -o lab5-report.pdf
  104  pandoc lab5-report.md -o lab5-report.pdf --pdf-engine=pdfLatex
  105  sudo dnf install wkhtmltopdf
  106  pandoc lab5-report.md -o lab5-report.pdf
  107  pandoc lab5-report.md -o lab5-report.pdf --pdf-engine=pdflatex
  108  pandoc lab5-report.md -o lab5-report.docx
  109  ls -lh lab5-report.*
  110  firefox lab5-report.html
  111  cat lab5-report.md
  112  nano lab5-report.md
  113  firefox lab5-report.html
  114  nano lab5-report.md
  115  pandoc lab05-report.md -o lab05-report.docx
  116  pandoc lab05-report.md -o lab05-report.html
  117  firefox lab05-report.html
  118  history


Повторение команды по номеру:

ofkhayjdarovdk5n18@fedora:~/Desktop$ !3
ls
bin  home  home.pub  lab05-report.docx  lab05-report.html  lab05-report.md  lab5-report.docx  lab5-report.html  lab5-report.md  missfont.log  Start.java
ofkhayjdarovdk5n18@fedora:~/Desktop$ !3:s/ls/ls -la/
ls -la
total 152
drwxr-xr-x. 1 ofkhayjdarovdk5n18 ofkhayjdarovdk5n18   264 Mar 14 23:02 .
drwx------. 1 ofkhayjdarovdk5n18 ofkhayjdarovdk5n18   860 Mar 21 13:31 ..
drwxr-xr-x. 1 ofkhayjdarovdk5n18 ofkhayjdarovdk5n18    56 Mar 14 23:03 bin
-rw-------. 1 ofkhayjdarovdk5n18 ofkhayjdarovdk5n18   411 Mar 14 17:09 home
-rw-r--r--. 1 ofkhayjdarovdk5n18 ofkhayjdarovdk5n18   100 Mar 14 17:09 home.pub
-rw-r--r--. 1 ofkhayjdarovdk5n18 ofkhayjdarovdk5n18 18238 Mar 14 23:01 lab05-report.docx
-rw-r--r--. 1 ofkhayjdarovdk5n18 ofkhayjdarovdk5n18 22103 Mar 14 23:02 lab05-report.html
-rw-r--r--. 1 ofkhayjdarovdk5n18 ofkhayjdarovdk5n18 20898 Mar 14 23:01 lab05-report.md
-rw-r--r--. 1 ofkhayjdarovdk5n18 ofkhayjdarovdk5n18 18211 Mar 14 22:52 lab5-report.docx
-rw-r--r--. 1 ofkhayjdarovdk5n18 ofkhayjdarovdk5n18 22050 Mar 14 22:38 lab5-report.html
-rw-r--r--. 1 ofkhayjdarovdk5n18 ofkhayjdarovdk5n18 20898 Mar 14 22:59 lab5-report.md
-rw-r--r--. 1 ofkhayjdarovdk5n18 ofkhayjdarovdk5n18    54 Mar 14 22:51 missfont.log
-rw-r--r--. 1 ofkhayjdarovdk5n18 ofkhayjdarovdk5n18   101 Mar  9 00:48 Start.java
ofkhayjdarovdk5n18@fedora:~/Desktop$ 



Модификация команды

ofkhayjdarovdk5n18@fedora:~$ !3:s/ls/ls -aIF/
ls -aIF
.              .bash_profile  .config    .gitconfig  .local    .password-store  .ssh                                    .vboxclient-clipboard-tty2-service.pid    Videos
..             .bashrc        Desktop    .gnupg      -lt       Pictures         Templates                               .vboxclient-draganddrop-tty2-control.pid  .vimrc
.bash_history  .bashrc.d      Documents  .gtkrc-2.0  .mozilla  Public           .texlive2023                            .vboxclient-hostversion-tty2-control.pid  .XCompose
.bash_logout   .cache         Downloads  LICENSE     Music     .python_history  .vboxclient-clipboard-tty2-control.pid  .vboxclient-seamless-tty2-control.pid


## 4.5. Контрольные вопросы

1. Что такое командная строка?
Командная строка — это интерфейс взаимодействия пользователя с операционной системой, в котором команды вводятся в текстовом виде построчно.
2. При помощи какой команды можно определить абсолютный путь текущего каталога?
Команда pwd
3. При помощи какой команды и каких опций можно определить только тип файлов и их имена?
Команда ls -F. Символы: / — каталог, * — исполняемый, @ — ссылка.
4. Каким образом отобразить информацию о скрытых файлах?
Команда ls -a (показывает файлы, начинающиеся с точки).
5. При помощи каких команд можно удалить файл и каталог?

    Файл: rm file
    Каталог: rm -r dir или rmdir dir (если пуст)

6. Каким образом можно вывести информацию о последних выполненных командах?
Команда history.
7. Как воспользоваться историей команд для их модифицированного выполнения?

    !N — повторить команду №N
    !N:s/old/new/ — заменить и выполнить

8. Приведите примеры запуска нескольких команд в одной строке.
	cd /tmp; ls; pwd

9. Дайте определение и приведите примеры символов экранирования.
Экранирование — использование \ перед специальными символами. Пример: echo "Цена: \$100".
10. Охарактеризуйте вывод информации после выполнения команды ls с опцией -l.
Выводит: тип файла, права, число ссылок, владелец, группа, размер, дата, имя.
11. Что такое относительный путь к файлу?
Путь относительно текущего каталога. Пример: cd Documents (относительный), cd /home/user/Documents (абсолютный).
12. Как получить информацию об интересующей вас команде?
Команда man <имя_команды>.
13. Какая клавиша служит для автоматического дополнения команд?
Клавиша Tab.

### Выводы
В ходе выполнения лабораторной работы были приобретены практические навыки:

Навигация по файловой системе (cd, pwd)
Просмотр содержимого каталогов с различными опциями (ls)
Создание и удаление каталогов (mkdir, rmdir, rm)
Работа со справкой (man)
Использование истории команд (history, !N)

Полученные навыки являются базовыми для эффективной работы в ОС семейства  Linux/Unix.

----
Данная лабораторная работа была выполнена в Markdown

