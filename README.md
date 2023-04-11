# Задания от компании Яндекс

В этом репозитории будут собираться решеные на C++, Python и возможно других языках программирования задачи с различных мероприятий, проводимых компанией Яндекс

## Значения ошибок, возвращаемых проверяющей системой

|        Сообщение        | Кратко | Сообщается ли номер теста? |
| :---------------------: | :----: | :------------------------: |
|           OK            |   OK   |            Нет             |
|    Compilation error    |   CE   |            Нет             |
|      Wrong answer       |   WA   |             Да             |
|   Presentation error    |   PE   |             Да             |
|   Time-limit exceeded   |   TL   |             Да             |
|  Memory limit exceeded  |   ML   |             Да             |
|  Output limit exceeded  |   OL   |             Да             |
|     Run-time error      |   RE   |             Да             |
| Precompile check failed |  PCF   |            Нет             |
| Idleness limit exceeded |   IL   |             Да             |

## Настройки компиляторов

Intel(R) Xeon(R) CPU E5-2660 @ 2.20GHz, 20480KB cache, virtualizаtion on 1 core, 4GB RAM, used OS Linux

| Язык программирования |                                 Компиляция                                  |
| :-------------------: | :-------------------------------------------------------------------------: |
|       GNU c 4.9       |     gcc -O2 -fno-stack-limit -x c -std=c99 файл -lm -o исполняемый_файл     |
|     GNU c x32 4.9     |  gcc -O2 -fno-stack-limit -x c -std=c99 -m32 файл -lm -o исполняемый_файл   |
|      GNU c11 4.9      |     gcc -O2 -fno-stack-limit -x c -std=c11 файл -lm -o исполняемый_файл     |
|      GNU c11 7.3      |     gcc -lm -O2 -fno-stack-limit -std=c11 -x c файл -o исполняемый_файл     |
|    GNU c++ 14 4.9     | g++-4.9 -lm -O2 -fno-stack-limit -std=c++14 -x c++ файл -o исполняемый_файл |
|      GNU c++ 4.9      |          g++ -O2 -fno-stack-limit -x c++ файл -o исполняемый_файл           |
|    GNU c++ x32 4.9    |        g++ -O2 -fno-stack-limit -x c++ -m32 файл -o исполняемый_файл        |
|    GNU c++ 11 4.9     | g++-4.9 -lm -O2 -fno-stack-limit -std=c++11 -x c++ файл -o исполняемый_файл |
|  GNU c++ 11 x32 4.9   |  g++ -O2 -fno-stack-limit -x c++ -std=c++11 -m32 файл -o исполняемый_файл   |
|     GNU c++17 7.3     |   g++ -lm -O2 -fno-stack-limit -std=c++1z -x c++ файл -o исполняемый_файл   |
