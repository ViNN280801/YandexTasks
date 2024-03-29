# B. Ровный забор

|                     |                                  |
| :------------------ | :------------------------------- |
| Ограничение времени | 2 секунды                        |
| Ограничение памяти  | 256Mb                            |
| Ввод                | стандартный ввод или input.txt   |
| Вывод               | стандартный вывод или output.txt |

Вася разобрал на даче старый сарай на n досок одинаковой ширины и толщины, но разной длины. Он решил построить из них забор. Высота забора не имеет для Васи особого значения, главное чтобы он был как можно более ровным. Неровность забора определяется как разница высот между самой короткой и самой длинной доской, использованной для постройки забора. После тщательного измерения оказалось, что k из n досок лишние и их можно не использовать для строительства забора.

Определите минимальную неровность забора, который можно построить из n−k досок.

## Формат ввода

В первой строке входных данных записаны два числа n и k (0≤k<n≤200000) — количество досок от разбора сарая и количество лишних досок.

Во второй строке записаны n целых чисел li (1≤li≤10<sup>9</sup>) — длины досок.

## Формат вывода

Выведите единственное целое число — минимальную неровность забора.

### Пример 1

|       |       |
| :---- | :---- |
| Ввод  | Вывод |
| 2 0   | 4     |
| 15 19 |       |

### Пример 2

|                    |       |
| :----------------- | :---- |
| Ввод               | Вывод |
| 7 2                | 9     |
| 1 11 6 41 15 13 14 |       |

## Примечания

В первом примере нет лишних досок, поэтому неровность равна 19−15=4.
Во втором примере можно не использовать первую и четвертую доску для строительства забора.
