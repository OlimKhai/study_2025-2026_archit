# Лабораторная работа № 7
## Анализ файловой системы Linux.Команды для работы с файлами и каталогами


## Студент
- **ФИО:**  Хайдаров Олим Фирдавсович
- **Группа:** НБИбд-02-25
- **Студ.билет:** 1032242468
- **Дата выполнения:**  28 марта 2026

---

## 5.1. Цель работы

Ознакомление с файловой системой Linux, её структурой, именами и содержанием каталогов. Приобретение практических навыков по применению команд для работы с файлами и каталогами, по управлению процессами (и работами), по проверке использования диска и обслуживанию файловой системы.

## 5.2. Указания к работе

### 5.2.1. Команды для работы с файлами и каталогами

Для создания текстового файла можно использовать команду touch.

Формат команды:
1 touch имя-файла

Для просмотра файлов небольшого размера можно использовать команду cat.

Формат команды:
1 cat имя-файла

Для просмотра файлов постранично удобнее использовать команду less.

Формат команды:
1 less имя-файла

Следующие клавиши используются для управления процессом просмотра:
– Space — переход к следующей странице,
– ENTER — сдвиг вперёд на одну строку,
– b — возврат на предыдущую страницу,
– h — обращение за подсказкой,
– q — выход из режима просмотра файла.

Команда head выводит по умолчанию первые 10 строк файла.

Формат команды:
1 head [-n] имя-файла, где n — количество выводимых строк.

Команда tail выводит умолчанию 10 последних строк файла.
Формат команды:
1 tail [-n] имя-файла, где n — количество выводимых строк.

### 5.2.2. Копирование файлов и каталогов

Команда cp используется для копирования файлов и каталогов.

Формат команды:
1 cp [-опции] исходный_файл целевой_файл

Примеры:
1. Копирование файла в текущем каталоге. Скопировать файл ~/abc1 в файл april и в файл may:
1 cd
2 touch abc1
3 cp abc1 april
4 cp abc1 may

2. Копирование нескольких файлов в каталог. Скопировать файлы april и may в каталог monthly:
1 mkdir monthly
2 cp april may monthly

3. Копирование файлов в произвольном каталоге. Скопировать файл monthly/may в файл с именем june:
1 cp monthly/may monthly/june
2 ls monthly

Опция i в команде cp выведет на экран запрос подтверждения о перезаписи файла. Для рекурсивного копирования каталогов, содержащих файлы, используется команда cp с опцией r.
Примеры:

1. Копирование каталогов в текущем каталоге. Скопировать каталог monthly в каталог monthly.00:
1 mkdir monthly.00
2 cp -r monthly monthly.00

2. Копирование каталогов в произвольном каталоге. Скопировать каталог monthly.00 в каталог /tmp
1 cp -r monthly.00 /tmp

### 5.2.3. Перемещение и переименование файлов и каталогов

Команды mv и mvdir предназначены для перемещения и переименования файлов и каталогов.

Формат команды mv:
48 Лабораторная работа № 5. Анализ файловой системы Linux. Команды для работы …
1 mv [-опции] старый_файл новый_файл

Примеры:
1. Переименование файлов в текущем каталоге. Изменить название файла april на july в домашнем каталоге:
1 cd
2 mv april july

2. Перемещение файлов в другой каталог. Переместить файл july в каталог monthly.00:
1 mv july monthly.00
2 ls monthly.00

Результат:
1 april july june may
Если необходим запрос подтверждения о перезаписи файла, то нужно использовать опцию i.

3. Переименование каталогов в текущем каталоге. Переименовать каталог monthly.00 в monthly.01
1 mv monthly.00 monthly.01

4. Перемещение каталога в другой каталог. Переместить каталог monthly.01в каталог reports:
1 mkdir reports
2 mv monthly.01 reports

5. Переименование каталога, не являющегося текущим. Переименовать каталог reports/monthly.01 в reports/monthly:
1 mv reports/monthly.01 reports/monthly

### 5.2.4. Права доступа

Каждый файл или каталог имеет права доступа (табл. 5.1). В сведениях о файле или каталоге указываются: 
– тип файла (символ (-) обозначает файл, а символ (d) — каталог);
– права для владельца файла (r — разрешено чтение, w — разрешена запись, x — разрешено выполнение, - — право доступа отсутствует);
– права для членов группы (r — разрешено чтение, w — разрешена запись, x — разрешено выполнение, - — право доступа отсутствует);
– права для всех остальных (r — разрешено чтение, w — разрешена запись, x — разрешено выполнение, - — право доступа отсутствует).

Примеры:

Таблица 5.1

							Права доступа

Право		Обозначение			Файл							Каталог
Чтение			r	Разрешены просмотр и копирование				Разрешён просмотр списка входящих файлов
Запись 			w 	Разрешены изменение и переименование				Разрешены создание и удаление файлов
Выполнение 		x	Разрешено выполнение файла (скриптов и/или программ)		Разрешён доступ в каталог и есть возможность сделать его текущим

1. Для файла (крайнее левое поле имеет значение -) владелец файла имеет право на
чтение и запись (rw-), группа, в которую входит владелец файла, может читать файл
(r--), все остальные могут читать файл (r--):
1 -rw-r--r--

2. Только владелец файла имеет право на чтение, изменение и выполнение файла:
1 -rwx------

3. Владелец каталога (крайнее левое поле имеет значение d) имеет право на просмотр,
изменение и доступа в каталог, члены группы могут входить и просматривать его, все
остальные — только входить в каталог:
1 drwxr-x--x

### 5.2.5. Изменение прав доступа

Права доступа к файлу или каталогу можно изменить, воспользовавшись командой chmod. Сделать это может владелец файла (или каталога) или пользователь с правами администратора.

Формат команды:
1 chmod режим имя_файла
Режим (в формате команды) имеет следующие компоненты структуры и способ записи:
= установить право
- лишить права
+ дать право
r чтение
w запись

x выполнение
u (user) владелец файла
g (group) группа, к которой принадлежит владелец файла
o (others) все остальные

В работе с правами доступа можно использовать их цифровую запись (восьмеричное значение) вместо символьной (табл. 5.2).

Таблица 5.2

		Формы записи прав доступа
Двоичная 		Восьмеричная 			Символьная
111				7			rwx
110 				6 			rw-
101 				5 			r-x
100 				4			r--
011 				3 			-wx
010 				2 			-w-
001 				1 			--x
000 				0 			---

Примеры:

1. Требуется создать файл ~/may с правом выполнения для владельца:
1 cd
2 touch may
3 ls -l may
4 chmod u+x may
5 ls -l may

2. Требуется лишить владельца файла ~/may права на выполнение:
1 chmod u-x may
2 ls -l may

3. Требуется создать каталог monthly с запретом на чтение для членов группы и всех остальных пользователей:
1 cd
2 mkdir monthly
3 chmod g-r, o-r monthly

4. Требуется создать файл ~/abc1 с правом записи для членов группы:
1 cd
2 touch abc1
3 chmod g+w abc1

###5.2.6. Анализ файловой системы

Файловая система в Linux состоит из фалов и каталогов. Каждому физическому носителю соответствует своя файловая система. Существует несколько типов файловых систем. Перечислим наиболее часто встречающиеся типы:
– ext2fs (second extended filesystem);
– ext2fs (third extended file system);
– ext4 (fourth extended file system);
– ReiserFS;
– xfs;
– fat (file allocation table);
– ntfs (new technology file system).

Для просмотра используемых в операционной системе файловых систем можно воспользоваться командой mount без параметров. В результате её применения можно получить примерно следующее:
1 mount
2
3 proc on /proc type proc (rw)
4 sysfs on /sys type sysfs (rw,nosuid,nodev,noexec)
5 udev on /dev type tmpfs (rw,nosuid)
6 devpts on /dev/pts type devpts (rw,nosuid,noexec)
7 /dev/sda1 on /mnt/a type ext3 (rw,noatime)
8 /dev/sdb2 on /mnt/docs type reiserfs (rw,noatime)
9 shm on /dev/shm type tmpfs (rw,noexec,nosuid,nodev)
10 usbfs on /proc/bus/usb type usbfs
11 (rw,noexec,nosuid,devmode=0664,devgid=85)
12 binfmt_misc on /proc/sys/fs/binfmt_misc type binfmt_misc
13 (rw,noexec,nosuid,nodev)
14 nfsd on /proc/fs/nfs type nfsd (rw,noexec,nosuid,nodev)
15

В данном случае указаны имена устройств, названия соответствующих им точек монтирования (путь), тип файловой системы и параметрами монтирования. В контексте команды mount устройство — специальный файл устройства, с помощью которого операционная система получает доступ к аппаратному устройству. Файлы устройств обычно располагаются в каталоге /dev, имеют сокращённые имена (например, sdaN, sdbN или hdaN, hdbN, где N — порядковый номер устройства, sd — устройства SCSI, hd — устройства MFM/IDE).

Точка монтирования — каталог (путь к каталогу), к которому присоединяются файлы
устройств.

Другой способ определения смонтированных в операционной системе файловых си-
стем — просмотр файла/etc/fstab. Сделать это можно например с помощью команды
cat:

1 cat /etc/fstab
2
3 /dev/hda1 / ext2 defaults 1 1
4 /dev/hda5 /home ext2 defaults 1 2
5 /dev/hda6 swap swap defaults 0 0
6 /dev/hdc /mnt/cdrom auto umask=0,user,noauto,ro,exec,users 0 0
7 none /mnt/floppy supermount dev=/dev/fd0,fs=ext2:vfat,--,
8 sync,umask=0 0 0
9 none /proc proc defaults 0 0
10 none /dev/pts devpts mode=0622 0 0

В каждой строке этого файла указано:
– имя устройство;
– точка монтирования;
– тип файловой системы;
– опции монтирования;
– специальные флаги для утилиты dump;
– порядок проверки целостности файловой системы с помощью утилиты fsck.

Для определения объёма свободного пространства на файловой системе можно воспользоваться командой df, которая выведет на экран список всех файловых систем в соответствии с именами устройств, с указанием размера и точки монтирования. Например:

1 df
2
3 Filesystem 1024-blocks Used Available Capacity Mounted on
4 /dev/hda3 297635 169499 112764 60% /

С помощью команды fsck можно проверить (а в ряде случаев восстановить) целостность файловой системы:

Формат команды:
1 fsck имя_устройства

Пример:
1 fsck /dev/sda1


## 5.3. Последовательность выполнения работы (Выполнение лабораторной работы)

*Задание:*
Скопируйте файл /usr/include/sys/io.h в домашний каталог и назовите его
equipment. Если файла io.h нет, то используйте любой другой файл в каталоге
/usr/include/sys/ вместо него.
 
**Команда:**
ofkhayjdarovdk5n18@fedora:~/Desktop$ ls /usr/include/sys/

Результат:

acct.h      dir.h      fanotify.h  gmon_out.h  kd.h     mtio.h         pidfd.h   profil.h  raw.h       select.h    signal.h           statfs.h   sysinfo.h    time.h      ttydefaults.h  unistd.h   vm86.h
auxv.h      elf.h      fcntl.h     inotify.h   klog.h   param.h        platform  ptrace.h  reboot.h    sem.h       single_threaded.h  stat.h     syslog.h     timerfd.h   types.h        user.h     vt.h
bitypes.h   epoll.h    file.h      ioctl.h     mman.h   pci.h          poll.h    queue.h   reg.h       sendfile.h  socket.h           statvfs.h  sysmacros.h  times.h     ucontext.h     utsname.h  wait.h
cdefs.h     errno.h    fsuid.h     io.h        mount.h  perm.h         prctl.h   quota.h   resource.h  shm.h       socketvar.h        swap.h     termios.h    timex.h     uio.h          vfs.h      xattr.h
debugreg.h  eventfd.h  gmon.h      ipc.h       msg.h    personality.h  procfs.h  random.h  rseq.h      signalfd.h  soundcard.h        syscall.h  timeb.h      ttychars.h  un.h           vlimit.h

Нашли искомый файл:

ofkhayjdarovdk5n18@fedora:~/Desktop$ ls /usr/include/sys/io.h
/usr/include/sys/io.h

И далее переместили его в ~/equipment
ofkhayjdarovdk5n18@fedora:~/Desktop$ cp /usr/include/sys/io.h ~/equipment

Результат: Успешно было скопировано


*Задание:*
В домашнем каталоге создайте директорию ~/ski.plaсes.

**Команда:**

ofkhayjdarovdk5n18@fedora:~/Desktop$ mkdir ~/ski.places
ofkhayjdarovdk5n18@fedora:~/Desktop$ ls -ld ~/ski.places
drwxr-xr-x. 1 ofkhayjdarovdk5n18 ofkhayjdarovdk5n18 0 Mar 28 11:49 /home/ofkhayjdarovdk5n18/ski.places

Результат: успешно создали и проверили его наличие

*Задание:*
2.3. Переместите файл equipment в каталог ~/ski.plases.

**Команда:**
ofkhayjdarovdk5n18@fedora:~/Desktop$ mv ~/equipment ~/ski.places
ofkhayjdarovdk5n18@fedora:~/Desktop$ ls ~/ski.places
equipment

Результат: Мы проверили его наличие в директории ~/ski.places, и убедились в его наличии


*Задание:*
2.4. Переименуйте файл ~/ski.plases/equipment в ~/ski.plases/equiplist.

**Команда:**
ofkhayjdarovdk5n18@fedora:~/Desktop$ mv ~/ski.places/equipment ~/ski.places/equiplist
ofkhayjdarovdk5n18@fedora:~/Desktop$ ls  ~/ski.places/equiplist
/home/ofkhayjdarovdk5n18/ski.places/equiplist

Результат: Успешно переименовали файл


*Задание:*
2.5. Создайте в домашнем каталоге файл abc1 и скопируйте его в каталог ~/ski.plases, назовите его equiplist2.

**Команда:**
ofkhayjdarovdk5n18@fedora:~/Desktop$ touch ~/abc1
ofkhayjdarovdk5n18@fedora:~/Desktop$ cp ~/abc1 ~/ski.places/equiplist2
ofkhayjdarovdk5n18@fedora:~/Desktop$ ls ~/ski.places/
equiplist  equiplist2

Результат: Создали файл abc1 и скопировали его в нужный каталог с дальнейшей проверкой на его наличие


*Задание:*
2.6. Создайте каталог с именем equipment в каталоге ~/ski.plases.

**Команда:**
ofkhayjdarovdk5n18@fedora:~/Desktop$ mkdir ~/ski.places/equipment
ofkhayjdarovdk5n18@fedora:~/Desktop$ ls -l ~/ski.places
total 8
-rw-r--r--. 1 ofkhayjdarovdk5n18 ofkhayjdarovdk5n18 5086 Mar 28 11:48 equiplist
-rw-r--r--. 1 ofkhayjdarovdk5n18 ofkhayjdarovdk5n18    0 Mar 28 11:54 equiplist2
drwxr-xr-x. 1 ofkhayjdarovdk5n18 ofkhayjdarovdk5n18    0 Mar 28 11:55 equipment

Результат: Создали и проверили на наличие каталог с именем equipment


*Задание:*
2.7. Переместите файлы ~/ski.plases/equiplist и equiplist2 в каталог ~/ski.plases/equipment.

**Команда**
ofkhayjdarovdk5n18@fedora:~/Desktop$ mv ~/ski.places/equiplist ~/ski.places/equipment
ofkhayjdarovdk5n18@fedora:~/Desktop$ mv ~/ski.places/equiplist2  ~/ski.places/equipment
ofkhayjdarovdk5n18@fedora:~/Desktop$ ls ~/ski.places/equipment
equiplist  equiplist2

Результат: Файлы были успешно перемещены




*Задание:*
2.8. Создайте и переместите каталог ~/newdir в каталог ~/ski.plases и назовите его plans.

**Команда:**
ofkhayjdarovdk5n18@fedora:~/Desktop$ mkdir ~/newdir
ofkhayjdarovdk5n18@fedora:~/Desktop$ mv ~/newdir ~/ski.places/plans
ofkhayjdarovdk5n18@fedora:~/Desktop$ ls -l ~/ski.places/
total 0
drwxr-xr-x. 1 ofkhayjdarovdk5n18 ofkhayjdarovdk5n18 38 Mar 28 11:58 equipment
drwxr-xr-x. 1 ofkhayjdarovdk5n18 ofkhayjdarovdk5n18  0 Mar 28 11:58 plans

Результат: Успешно был создан новый директорий ~/newdir и он был перемещен в каталог ~/ski.places/plans, с оследующей проверкой файла командой ls



*Задание:*
3. Определите опции команды chmod, необходимые для того, чтобы присвоить перечис-
ленным ниже файлам выделенные права доступа, считая, что в начале таких прав
нет:
3.1. drwxr--r-- ... australia
3.2. drwx--x--x ... play
3.3. -r-xr--r-- ... my_os
3.4. -rw-rw-r-- ... feathers
При необходимости создайте нужные файлы.

Изначально исходим из того, что в начале прав никаких для файлов нет. Наглядная структура  показана ниже



№		Файл/Каталог			Требуемые права			Восьмеричный			Команда chmod
3.1		australia (каталог)		drwxr--r--			744				chmod 744 australia
3.2		play (каталог)			drwx--x--x			711				chmod 711 play
3.3		my_os (файл)			-r-xr--r--			544				chmod 544 my_os
3.4		feathers (файл)			-rw-rw-r--			664				chmod 664 feathers



**Команда:**
ofkhayjdarovdk5n18@fedora:~$ mkdir australia play (Создаем файлы/каталоги)
ofkhayjdarovdk5n18@fedora:~$ touch my_os feathers
ofkhayjdarovdk5n18@fedora:~$ chmod 000 australia play my_os feathers (Устанавливаем права, но в начале сбрасываем их все - 000)
ofkhayjdarovdk5n18@fedora:~$ chmod 744 australia (далее устанавливаем требуемые)
ofkhayjdarovdk5n18@fedora:~$ chmod 711 play
ofkhayjdarovdk5n18@fedora:~$ chmod 544 my_os
ofkhayjdarovdk5n18@fedora:~$ chmod 664 feathers
ofkhayjdarovdk5n18@fedora:~$ ls -l australia play my_os feathers (Проверяем)
-rw-rw-r--. 1 ofkhayjdarovdk5n18 ofkhayjdarovdk5n18 0 Mar 28 12:02 feathers
-r-xr--r--. 1 ofkhayjdarovdk5n18 ofkhayjdarovdk5n18 0 Mar 28 12:02 my_os

australia:
total 0

play:
total 0


Результат: Успешно создали файлы/каталоги и задали права


*Задание:*
4.1. Просмотрите содержимое файла /etc/password.

**Команда:**
ofkhayjdarovdk5n18@fedora:~$ cat  /etc/passwd
root:x:0:0:Super User:/root:/bin/bash
bin:x:1:1:bin:/bin:/usr/sbin/nologin
daemon:x:2:2:daemon:/sbin:/usr/sbin/nologin
adm:x:3:4:adm:/var/adm:/usr/sbin/nologin
lp:x:4:7:lp:/var/spool/lpd:/usr/sbin/nologin
sync:x:5:0:sync:/sbin:/bin/sync
shutdown:x:6:0:shutdown:/sbin:/sbin/shutdown
halt:x:7:0:halt:/sbin:/sbin/halt
mail:x:8:12:mail:/var/spool/mail:/usr/sbin/nologin
operator:x:11:0:operator:/root:/usr/sbin/nologin
games:x:12:100:games:/usr/games:/usr/sbin/nologin
ftp:x:14:50:FTP User:/var/ftp:/usr/sbin/nologin
nobody:x:65534:65534:Kernel Overflow User:/:/usr/sbin/nologin
dbus:x:81:81:System Message Bus:/:/usr/sbin/nologin
tss:x:59:59:Account used for TPM access:/:/usr/sbin/nologin
systemd-oom:x:999:999:systemd Userspace OOM Killer:/:/usr/sbin/nologin
polkitd:x:114:114:User for polkitd:/:/sbin/nologin
systemd-coredump:x:998:998:systemd Core Dumper:/:/usr/sbin/nologin
systemd-timesync:x:997:997:systemd Time Synchronization:/:/usr/sbin/nologin
chrony:x:996:996:chrony system user:/var/lib/chrony:/sbin/nologin
systemd-network:x:192:192:systemd Network Management:/:/usr/sbin/nologin
systemd-resolve:x:193:193:systemd Resolver:/:/usr/sbin/nologin
avahi:x:70:70:Avahi mDNS/DNS-SD Stack:/var/run/avahi-daemon:/usr/sbin/nologin
unbound:x:993:993:Unbound DNS resolver:/var/lib/unbound:/sbin/nologin
clevis:x:992:992:Clevis Decryption Framework unprivileged user:/var/cache/clevis:/usr/sbin/nologin
usbmuxd:x:113:113:usbmuxd user:/:/usr/sbin/nologin
gluster:x:991:991:GlusterFS daemons:/run/gluster:/usr/sbin/nologin
qemu:x:107:107:qemu user:/:/usr/sbin/nologin
apache:x:48:48:Apache:/usr/share/httpd:/sbin/nologin
openvpn:x:990:990:OpenVPN:/etc/openvpn:/usr/sbin/nologin
nm-openvpn:x:989:989:Default user for running openvpn spawned by NetworkManager:/:/usr/sbin/nologin
abrt:x:173:173::/etc/abrt:/usr/sbin/nologin
wsdd:x:987:987:Web Services Dynamic Discovery host daemon:/:/usr/sbin/nologin
nm-openconnect:x:986:986:NetworkManager user for OpenConnect:/:/usr/sbin/nologin
rtkit:x:985:985:RealtimeKit:/:/usr/sbin/nologin
pipewire:x:984:984:PipeWire System Daemon:/run/pipewire:/usr/sbin/nologin
flatpak:x:982:982:Flatpak system helper:/:/usr/sbin/nologin
geoclue:x:981:981:User for geoclue:/var/lib/geoclue:/sbin/nologin
sssd:x:980:980:User for sssd:/run/sssd:/sbin/nologin
colord:x:979:979:colord colour management daemon:/var/lib/colord:/usr/sbin/nologin
gdm:x:42:42:GNOME Display Manager:/var/lib/gdm:/usr/sbin/nologin
rpc:x:32:32:Rpcbind Daemon:/var/lib/rpcbind:/usr/sbin/nologin
dnsmasq:x:978:978:Dnsmasq DHCP and DNS server:/var/lib/dnsmasq:/usr/sbin/nologin
rpcuser:x:29:29:RPC Service User:/var/lib/nfs:/usr/sbin/nologin
gnome-remote-desktop:x:976:976:GNOME Remote Desktop:/var/lib/gnome-remote-desktop:/usr/sbin/nologin
vboxadd:x:974:1::/var/run/vboxadd:/usr/sbin/nologin
sshd:x:74:74:Privilege-separated SSH:/usr/share/empty.sshd:/usr/sbin/nologin
passim:x:973:973:Local Caching Server:/usr/share/empty:/usr/sbin/nologin
tcpdump:x:72:72:tcpdump:/:/usr/sbin/nologin
ofkhayjdarovdk5n18:x:1000:1000:Olim Khayjdarov:/home/ofkhayjdarovdk5n18:/bin/bash

Результат: Мы посмотрели содержимое этого файла и изучили его


*Задания:*
4.2. Cкопируйте файл ~/feathers в файл ~/file.old.
4.3. Переместите файл ~/file.old в каталог ~/play.
4.4. Скопируйте каталог ~/play в каталог ~/fun.
4.5. Переместите каталог ~/fun в каталог ~/play и назовите его games.

**Команды**:
ofkhayjdarovdk5n18@fedora:~$ cp ~/feathers ~/file.old
ofkhayjdarovdk5n18@fedora:~$ mv ~/file.old ~/play/
ofkhayjdarovdk5n18@fedora:~$ cp -r ~/play ~/fun
ofkhayjdarovdk5n18@fedora:~$ mv ~/fun ~/play/games
ofkhayjdarovdk5n18@fedora:~$ ls ~/play
file.old  games

Результат: Успешно выполнили преобразования файла из ~/feathers в ~/file.old и его дальнейшее перемещение в каталог ~/play с последующим копированием данного в ~/fun и его перемещение в каталог ~/play с перемеинованием в games


*Задания:*
4.6. Лишите владельца файла ~/feathers права на чтение.
4.7. Что произойдёт, если вы попытаетесь просмотреть файл ~/feathers командой
cat?
4.8. Что произойдёт, если вы попытаетесь скопировать файл ~/feathers?

**Команды:**
ofkhayjdarovdk5n18@fedora:~$ chmod u-r ~/feathers
ofkhayjdarovdk5n18@fedora:~$ ls -l ~/feathers
--w-rw-r--. 1 ofkhayjdarovdk5n18 ofkhayjdarovdk5n18 0 Mar 28 12:02 /home/ofkhayjdarovdk5n18/feathers
ofkhayjdarovdk5n18@fedora:~$ cat ~/feathers
cat: /home/ofkhayjdarovdk5n18/feathers: Permission denied
ofkhayjdarovdk5n18@fedora:~$ cp ~/feathers ~/feathers.copy
cp: cannot open '/home/ofkhayjdarovdk5n18/feathers' for reading: Permission denied

Результат: После лишения прав на чтение система не может открыть содержимое оного с помощью команды (cat), в случае попытки выдаёт ошибку: cat: /home/ofkhayjdarovdk5n18/feathers: Permission denied. Соответственно, при попытке скопировать данный файл система пытается открыть его для копирования, но из-за ранее лишённых прав доступа не может, также выдавая ошибку: cp: cannot open '/home/ofkhayjdarovdk5n18/feathers' for reading: Permission denied


*Задания:*
4.9. Дайте владельцу файла ~/feathers право на чтение.
4.10. Лишите владельца каталога ~/play права на выполнение.
4.11. Перейдите в каталог ~/play. Что произошло?

**Команды:**
ofkhayjdarovdk5n18@fedora:~$ chmod u+r ~/feathers
ofkhayjdarovdk5n18@fedora:~$ ls -l ~/feathers
-rw-rw-r--. 1 ofkhayjdarovdk5n18 ofkhayjdarovdk5n18 0 Mar 28 12:02 /home/ofkhayjdarovdk5n18/feathers
ofkhayjdarovdk5n18@fedora:~$ chmod u-x ~/play
ofkhayjdarovdk5n18@fedora:~$ ls -ld ~/play
drw---x--x. 1 ofkhayjdarovdk5n18 ofkhayjdarovdk5n18 26 Mar 28 12:09 /home/ofkhayjdarovdk5n18/play
ofkhayjdarovdk5n18@fedora:~$ cd ~/play
bash: cd: /home/ofkhayjdarovdk5n18/play: Permission denied

Результат: После введённой нами команды для файла ~/feathers для выдачи права на чтение, при проверке(ls -l) файла мы видим, что он изменился(наличие кода из -rw-rw-r--. 1....), что свидетельствует об успешном редактировании прав к нему. В свою очередь после лишения прав владельца к каталогу ~/play и при дальнейшей попытки обращения к нему система не может этого сделать из-за ранее введённых нами ограничений к каталогу, с выдаваемой ошибкой (bash: cd: /home/ofkhayjdarovdk5n18/play: Permission denied)


*Задание:*
4.12. Дайте владельцу каталога ~/play право на выполнение.

**Команды:**
ofkhayjdarovdk5n18@fedora:~$ chmod u+x ~/play
ofkhayjdarovdk5n18@fedora:~$ cd ~/play
ofkhayjdarovdk5n18@fedora:~/play$ pwd
/home/ofkhayjdarovdk5n18/play

Результат: Мы вернули владельцу право на выполнению для каталога ~/play. Соответственно, и обращение к этому каталогу теперь возможно, что я и сделал (ofkhayjdarovdk5n18@fedora:~$ cd ~/play
ofkhayjdarovdk5n18@fedora:~/play$ pwd
/home/ofkhayjdarovdk5n18/play)


*Задания:*
5. Прочитайте man по командам mount, fsck, mkfs, kill и кратко их охарактеризуйте,
приведя примеры.


**Ответ и Объяснения:**

5.1 - mount — монтирование файловых систем

Команда для обращения к инструкции:
man mount

Параметр				Описание

Назначение				Подключение файловой системы к дереву каталогов
Синтаксис				mount [-t тип] устройство точка_монтирования
Примеры					mount /dev/sdb1 /mnt/data — смонтировать раздел
					mount -t ext4 /dev/sdc1 /media/usb — с указанием типа ФС
					mount | grep ext4 — показать только ext4
					mount -a — смонтировать все из /etc/fstab
					umount /mnt/data — размонтировать




5.2 - fsck — проверка и восстановление ФС

Команда	для обращения к	инструкции:
man fsck


Параметр				Описание

Назначение				Проверка целостности и исправление ошибок ФС

Важно!					Запускать только на размонтированной ФС!
Синтаксис				fsck [-опции] устройство
Примеры					sudo fsck /dev/sda1 — проверить раздел
					sudo fsck -y /dev/sda1 — автоматически исправлять ошибки
					sudo fsck -n /dev/sda1 — только проверка, без исправлений




5.3 - mkfs — создание файловой системы

Команда для обращения к инструкции:
man mkfs


Параметр				Описание

Назначение				Форматирование раздела с созданием новой ФС
Синтаксис				mkfs.тип устройство
Примеры					sudo mkfs.ext4 /dev/sdc1 — создать ext4
					sudo mkfs.vfat /dev/sdb1 — создать FAT32
					sudo mkfs.xfs /dev/sdd1 — создать XFS



5.4 kill — управление процессами

Команда для обращения к инструкции:
man kill


Параметр				Описание

Назначение				Отправка сигналов процессам (завершение, перезапуск)
Синтаксис				kill [-сигнал] PID
Примеры					kill 1234 — завершить процесс с PID 1234 (SIGTERM)
					kill -9 1234 — принудительное завершение (SIGKILL)
					kill -15 1234 — корректное завершение (SIGTERM)
					killall firefox — завершить все процессы firefox
					ps aux | grep имя — найти PID процесса



### 5.5 Ответы на контрольные вопросы

1. Характеристика файловых систем на диске Для просмотра ФС используется команда mount и df -h. В моей системе (Fedora) используются:

    ext4 — основная ФС для корневого раздела (/)
    tmpfs — временная ФС в оперативной памяти (/tmp, /run)
    proc — виртуальная ФС для информации о процессах
    sysfs — виртуальная ФС для информации об устройствах

2. Общая структура файловой системы Linux
Каталог					Назначение

/					Корневой каталог
/bin					Основные исполняемые файлы (команды)
/boot					Файлы загрузчика ядра
/dev					Специальные файлы устройств
/etc					Конфигурационные файлы системы
/home					Домашние каталоги пользователей
/lib					Библиотеки для программ
/media					Точки монтирования съёмных носителей
/mnt					Временные точки монтирования
/opt					Дополнительное ПО
/proc					Виртуальная ФС с информацией о процессах
/root					Домашний каталог администратора
/run					Данные о работающих процессах
/sbin					Системные исполняемые файлы
/tmp					Временные файлы
/usr					Пользовательские программы и данные
/var					Переменные данные (логи, почта, кэш)

3. Операция для доступа к ФС
Чтобы содержимое файловой системы стало доступно, необходимо выполнить монтирование командой mount. ФС подключается к точке монтирования (каталогу) в дереве каталогов Linux.

4. Причины нарушения целостности ФС и устранение
Причины:

    Внезапное отключение питания
    Аварийное завершение работы системы
    Физические повреждения диска
    Ошибки программного обеспечения
    Неправильное извлечение съёмных носителей

Устранение:

    Использование утилиты fsck для проверки и восстановления
    Регулярное резервное копирование
    Использование журналируемых ФС (ext4, xfs)

5. Создание файловой системы
ФС создаётся командой mkfs на предварительно подготовленном разделе:

sudo mkfs.ext4 /dev/sdc1

Перед созданием раздел должен быть размечен (fdisk, parted).


6. Команды для просмотра текстовых файлов
Команда				Назначение

cat				Вывод всего содержимого файла
less				Постраничный просмотр с навигацией
more				Постраничный просмотр (базовый)
head				Первые n строк файла
tail				Последние n строк файла
nano, vim			Просмотр и редактирование


7. Возможности команды cp

    Копирование файлов: cp файл1 файл2
    Копирование нескольких файлов: cp файл1 файл2 каталог
    Рекурсивное копирование каталогов: cp -r каталог1 каталог2
    Копирование с подтверждением: cp -i файл1 файл2
    Сохранение атрибутов: cp -p файл1 файл2
    Копирование с обновлением: cp -u файл1 файл2

8. Возможности команды mv

    Переименование файлов: mv старый новый
    Перемещение файлов: mv файл каталог
    Перемещение каталогов: mv -r каталог1 каталог2
    Перемещение с подтверждением: mv -i файл каталог
    Принудительное перемещение: mv -f файл каталог

9. Права доступа и их изменение
Права доступа — разрешения на выполнение операций с файлами/каталогами для трёх категорий пользователей: владелец (user), группа (group), остальные (others).

Типы прав:

    r (read) — чтение
    w (write) — запись
    x (execute) — выполнение/доступ в каталог

Изменение прав:

    Команда chmod (символьный или восьмеричный режим)
    Команда chown — смена владельца
    Команда chgrp — смена группы

Примеры:

chmod 755 файл      # восьмеричный режим
chmod u+x файл      # символьный режим
chmod g-w,o-r файл  # комбинированный режим


## Выводы
В процессе выполнения лабораторной работы № 5 были получены навыки:

Я ознакомился с файловой системой Linux, её структурой, именами и содержанием каталогов.
Также приобрёл практические навыки по применению команд для работы с файлами и каталогами, а именно:
	Освоил команды работы с файлами — touch, cat, less, head, tail для создания и просмотра файлов.
	Освоил команды копирования и перемещения — cp (в том числе с опцией -r для каталогов) и mv для перемещения и переименования.
	Изучил система прав доступа — понял различия между правами для владельца, группы и остальных пользователей.
	Научился изменять права — использовал команду chmod в восьмеричном и символьном режимах.
	Изучил команды обслуживания ФС — mount, fsck, mkfs, df и их практическое применение.
	Понял важность права x для каталогов — без него невозможен вход в каталог, даже при наличии права на чтение.

Практическая значимость: Полученные навыки необходимы для администрирования Linux-систем, обеспечения безопасности файлов и каталогов, а также для повседневной работы в командной строке.

----
Данная лабораторная работа была выполнена в Markdown
