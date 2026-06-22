---
marp: true
theme: default
paginate: true
headingDivider: 2
style: |
  section {
    font-family: 'Arial', sans-serif;
    padding: 40px;
    font-size: 22px;
  }
  h1 {
    color: #2c3e50;
    font-size: 36px;
    text-align: center;
  }
  h2 {
    color: #34495e;
    font-size: 28px;
    border-bottom: 2px solid #3498db;
    padding-bottom: 10px;
  }
  h3 {
    color: #2980b9;
    font-size: 24px;
  }
  img {
    max-height: 380px;
    object-fit: contain;
    display: block;
    margin: 20px auto;
    border: 1px solid #ddd;
    border-radius: 5px;
  }
  .toc a {
    color: #3498db;
    text-decoration: none;
    display: block;
    margin: 12px 0;
    font-size: 20px;
    padding: 8px;
    border-radius: 5px;
    transition: background-color 0.3s;
  }
  .toc a:hover {
    color: #2980b9;
    background-color: #ecf0f1;
  }
  .title-slide {
    text-align: center;
    background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
    color: white;
  }
  .title-slide h1 {
    color: white;
    font-size: 42px;
    margin-bottom: 30px;
  }
  .title-slide p {
    font-size: 24px;
    margin: 15px 0;
  }
  code {
    background-color: #f4f4f4;
    padding: 2px 6px;
    border-radius: 3px;
    font-family: 'Courier New', monospace;
  }
  pre {
    background-color: #2d3748;
    color: #e2e8f0;
    padding: 15px;
    border-radius: 5px;
    overflow-x: auto;
    font-size: 16px;
  }
---

<!-- _class: title-slide -->
# Лабораторная работа №12

## Программирование в командном процессоре ОС UNIX

### Командные файлы

**Студент:** Хайдаров Олим Фирдавсович  
**ORCID:** 0000-0002-0877-7063  
**Дата:** 2026

---

<!-- _class: toc -->
# 📋 Оглавление

[Цель работы](#3)

[Задание 1: Резервное копирование](#4)

[Задание 2: Обработка аргументов](#9)

[Задание 3: Аналог команды ls](#14)

[Задание 4: Подсчёт файлов](#19)

[Выводы](#24)

[Контрольные вопросы](#25)

---

# 🎯 Цель работы

## Изучить основы программирования в оболочке ОС UNIX/Linux

## Научиться писать небольшие командные файлы

### Основные задачи:
- Создание bash-скриптов
- Работа с аргументами командной строки
- Архивация файлов
- Анализ файловой системы
- Проверка прав доступа

---

# Задание 1: Резервное копирование

## Условие

Создать скрипт, который:
1. ✅ Делает резервную копию **самого себя**
2. ✅ Сохраняет в папку `~/backup`
3. ✅ Архивирует файл (tar/zip/bzip2)

---

![Скрипт, создание](/home/ofkhayjdarovdk5n18/Pictures/Screenshots/Screenshot From 2026-05-02 18-52-39.png )

---

![Код скрипта](/home/ofkhayjdarovdk5n18/Pictures/Screenshots/Screenshot From 2026-05-02 18-51-21.png )

---

![Запуск скрипта](/home/ofkhayjdarovdk5n18/Pictures/Screenshots/Screenshot From 2026-05-02 18-53-08.png )

---

## Задание 1: Создание файла

Создаём директорию `lab12` и файл `task1_backup.sh`

![Создание скрипта](Screenshot From 2026-05-02 18-52-39.png)

---

## Задание 1: Код скрипта

```bash
#!/bin/bash
mkdir -p ~/backup
SCRIPT_NAME=$(basename "$0")
TIMESTAMP=$(date +%Y%m%d_%H%M%S)
tar -czf ~/backup/${SCRIPT_NAME}.${TIMESTAMP}.tar.gz "$0"
echo "✓ Резервная копия создана!"

---

![Код скрипта](/home/ofkhayjdarovdk5n18/Pictures/Screenshots/Screenshot From 2026-05-02 18-51-21.png )

---

# Задание 1: Делаем файл исполняемым

![Запуск скрипта](/home/ofkhayjdarovdk5n18/Pictures/Screenshots/Screenshot From 2026-05-02 18-53-08.png )

Результат: Резервная копия успешно создана! 

---

# Задание 2: Обработка аргументов

##Условие

Написать скрипт, обрабатывающий любое число аргументов (в том числе > 10)
Особенности:

    Для аргументов > 9 используем ${10}, ${11}
    Перебор всех аргументов через "$@"
    Поддержка аргументов с пробелами

---

## Задание 2: Создание файла

Создаём файл tasks2_args.sh

![Создание файла](Screenshot From 2026-05-02 19-00-52.png)

---

![Код скрипта](Screenshot From 2026-05-02 18-59-45.png)

---

## Задание 2: Запуск с 13 аргументами

![Запуск файла](Screenshot From 2026-05-02 19-01-59.png)

Результат: Все 13 аргументов обработаны корректно!

---

# Задание 3: Аналог команды ls

Создаём файл task3_ls_analog.sh

![Создание файла](Screenshot From 2026-05-02 19-12-46.png)

---

## Задание 3: Создание файла

Создаём файл task3_ls_analog.sh

![Создание файла](Screenshot From 2026-05-02 19-12-46.png)

---

## Задание 3: Код скрипта

[Запуск файла](Screenshot From 2026-05-02 19-20-36.png)

Результат: Скрипт выводит список файлов с правами доступа!

---

## Задание 4: Подсчёт файлов

Условие:

Создать скрипт, который:

    Принимает расширение файла (.txt, .sh и т.д.)
    Принимает путь к директории
    Считает количество файлов с таким расширением

---

## Создание файла

Создаём файл task4_count.sh

![Создание файла](Screenshot From 2026-05-02 19-25-47.png)

---

## Задание 4: Код скрипта

![Код скрипта](Screenshot From 2026-05-02 19-25-09.png)

---

## Задание 4: Запуск и результат

![Запуск файла](Screenshot From 2026-05-02 19-26-18.png)

Результат: Найдено 4 файла с расширением .sh

---

## Выводы

В ходе лабораторной работы я:

 Изучил основы программирования в оболочке ОС UNIX/Linux
 Научился писать базовые скрипты и командные файлы

 Освоил:

    Работу с аргументами командной строки
    Создание резервных копий с архивацией
    Анализ файловой системы
    Проверку прав доступа к файлам

---

## Контрольные вопросы (1-5)

1. Командная оболочка — программа для взаимодействия с ОС

Примеры: sh, csh, ksh, BASH

2. POSIX — стандарты для совместимости UNIX/Linux систем

3. Переменные: имя=значение, массивы: set -A имя val1 val2

4. let — арифметика, read — ввод с клавиатуры

5. Операции: +, -, *, /, %, &&, ||, <, > и др.

---

6. (()) — арифметические выражения без let

7. Стандартные переменные: PATH, HOME, IFS, MAIL, TERM

8. Метасимволы: *, ?, [], <, >, |

9. Экранирование: , '', ""

10. Создание файлов: создать → chmod +x → запуск

---

11. Функции: fname() { команды }

12. Проверка файлов: test -f, test -d

13. set — список переменных, typeset — атрибуты, unset — удаление

14. Параметры: 0, $1, $2, ... ${10}, 

15. Специальные переменные: ?,?,,,!, ∗,∗,@

---

Спасибо за внимание!
