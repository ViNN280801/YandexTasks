# А. Самые частые элементы

|                     |                                  |
| :------------------ | :------------------------------- |
| Ограничение времени | 1 секунда                        |
| Ограничение памяти  | 64.0 Mb                          |
| Ввод                | стандартный ввод или input.txt   |
| Вывод               | стандартный вывод или output.txt |

У нас есть N сундуков, пронумерованных от 0 до N-1, причем все они закрыты на начальный момент времени, кроме сундука с номером 0. Наша цель - открыть все сундуки. Однако, мы не можем открыть какой-то сундук, если у нас нет ключа от него.

Когда мы открываем сундук, то в нём мы можем найти набор уникальных ключей. На каждом ключе написан номер, означающий, какой сундук он открывает.

В ответе выведите true, если мы можем открыть все сундуки, и false в ином случае.

## Формат ввода

На вход в первой строке подается N - число сундуков.

В следующих N строк подается набор ключей в каждом из сундуков в виде чисел, разделенных через пробел. Если в соответствующем сундуке нет ни одного ключа, то выводится строка EMPTY.

## Формат вывода

В ответ выведите true, если можно открыть все сундуки, и false в ином случае.

### Пример 1

| Ввод  | Вывод |
| :---- | :---- |
| 4     | true  |
| 1     |       |
| 2     |       |
| 3     |       |
| EMPTY |       |

### Пример 2

| Ввод  | Вывод |
| :---- | :---- |
| 4     | false |
| 1     |       |
| 2     |       |
| 3     |       |
| EMPTY |       |

### Пример 3

| Ввод  | Вывод |
| :---- | :---- |
| 4     | true  |
| 1     |       |
| 2     |       |
| 3     |       |
| EMPTY |       |
