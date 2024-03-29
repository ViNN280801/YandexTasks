# 353. Сортировка положительных чисел в обратном порядке (разминка)

## Бэкэнд. Легкая

Разработчики бэкенда часто взаимодействуют с многочисленными API и дополнительно обрабатывают результаты. Сейчас вам придётся сделать именно это!

Во входном файле четыре строчки. В первой находится адрес сервера, во второй — номер порта. В следующих двух строках записаны два целых 32-разрядных числа: <i>a</i> и <i>b</i>. Необходимо осуществить GET-запрос к серверу по указанному номеру порта, передав значения чисел <i>a</i> и <i>b</i> в значениях одноименных CGI-параметров. Сервер ответит JSON-массивом из целых чисел. Необходимо отсортировать числа в порядке невозрастания и распечатать в выходной файл положительные — по одному числу в строке.

Гарантируется, что общее количество чисел в ответе не превосходит 100, при этом каждое из них — 32-разрядное знаковое целое число.

Это разминочная задача, к которой мы размещаем готовое решения, чтобы вы могли познакомиться с нашей автоматической системой проверки решений. Ввод и вывод осуществляется через файлы, либо через стандартные потоки ввода-вывода, как вам удобнее.

Примеры решений:

- [GNU c++ 11 + network + libcurl + json](https://pastebin.com/r0iMSTPa).
- [Python 3.7 + network + requests](https://pastebin.com/wHtwKbk3).
- [Java 8 + network + json-simple](https://pastebin.com/nw27gBdm).
- [Golang 1.14.4 + network](https://pastebin.com/4J3bK8i8).

## Формат ввода

Строка — URL сервера. \ Целое число — порт сервера. \ Целое число — число <i>a</i>. \ Целое число — число <i>b</i>.

## Формат вывода

Целые положительные числа, отсортированные по невозрастанию, из списка в ответе сервера, по одному в строке.
Примечание

Для решений на языке python доступны библиотеки json, requests и urllib.

Для решений на языке Java доступна библиотека json-simple версии 1.1.1. Соответствующие import'ы могут выглядеть так:

```java
import org.json.simple.JSONArray;
import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;
import org.json.simple.parser.ParseException;
```

Для решений на языке C++ доступны библиотеки [libcurl](https://curl.haxx.se/libcurl/) v7.47.0 и [nlohmann/json](https://github.com/nlohmann/json/releases/tag/v3.8.0) v3.8.0. Соответствующие include выглядят так:

```cpp
#include <curl/curl.h>
#include "json.hpp"
```

Для решений на golang доступны все стандартные пакеты, включая encoding/json, net/http, sort и другие.

Для решений на C# доступны библиотеки System.Text.Json и Newtonsoft.Json. Соответствующие using могут выглядеть так:

```csharp
using Newtonsoft.Json;
using System.Text.Json;
```

Пример ответа сервера для первого теста:

```
curl "http://127.0.0.1:7777?a=2&b=4"
[
  8,
  6,
  -2,
  2,
  4,
  17,
  256,
  1024,
  -17,
  -19
]
```

| Ввод             | Вывод |
| :--------------- | :---- |
| http://127.0.0.1 | 1024  |
| 7777             | 256   |
| 2                | 17    |
| 4                | 8     |
|                  | 6     |
|                  | 4     |
|                  | 2     |
