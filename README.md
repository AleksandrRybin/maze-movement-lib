# maze-movement-lib

Тестовое задание в "ЦРТ"

## Сборка

В системе должны быть установлены

- Cmake версии не ниже **3.10**
  
- GoogleTest 
  
- Boost **1.68.0**

1. Склонировать репозиторий проекта

```bash
git clone <repo_url>
```

2. Перейти в каталог с репозиторием

```bash
cd maze-movement-lib
```

3. Выполнить команду

```bash
cmake -H. -Bbuild
```

а затем

```bash
cmake --build build
```

В каталоге *build* появятся

- *libmaze_movement.so* - библиотека, которая реализует функционал работы с лабиринтом

- *demo* - демо приложение, которое демонстрирует использование основных возможностей библиотеки

- в папке *test* юнит тесты для библиотеки
  
  - *point_test*

  - *maze_movement_test*

## Запуск

### Демо приложение

Программа принимает на вход лабиринт, маршрут и координаты начальной точки. Аргументы программы:

- **--board** путь до файла с лабиринтом. **Обязательный** аргумент

- **--route** маршрут строка вида *"ulrlrldduu"* где

  - *u* - вверх

  - *d* - вниз
    
  - *r* - направо
  
  - *l* - налево

**Обязательный** аргумент
    
- **--start_x** или **-x** абсцисса начальной точки. По умолчанию значение **0**
    
- **--start_y** или **-y** ордината начальной точки. По умолчанию значение **0**
    
- **--log** включает логгирование движения в консоль. По умолчанию значение **false**

Пример файла с лабиринтом *board.txt*

    (0, 0), (1, 0), (0, 1), (1, 1), (2, 0), (2, 1)

Пример запуска программы

```bash
build/demo --board board.txt --route rrull -x 0 -y 0 --log true
```

Вывод программы

    start (0,0)
    route RIGHT RIGHT UP LEFT LEFT 
    step 1 Navigating from (0,0) RIGHT -> (1,0)
    step 2 Navigating from (1,0) RIGHT -> (2,0)
    step 3 Navigating from (2,0) UP -> (2,1)
    step 4 Navigating from (2,1) LEFT -> (1,1)
    step 5 Navigating from (1,1) LEFT -> (0,1)
    result (0,1)

### Тесты

Юнит тесты могут быть запущены двумя способами

- Запуск отдельно исполняемых файлов с *GoogleTest*

```bash
build/test/point_test
```

```bash
build/test/maze_movement_test
```

- Запуск всех тестов сразу через *Ctest*

```bash
cd build
ctest
```

### API библиотеки

# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public std::ostream & `[`operator<<`](#maze__movement_8hpp_1a79c25305ab19a4f4657485ae3cd099e3)`(std::ostream & out,const `[`IntegerMaze2D::MOVEMENT`](#class_integer_maze2_d_1acef743d89f483882fb6e35b6e5144e32)` & movement)`            | 
`public bool `[`operator==`](#point_8hpp_1a038e147fa170c36c9d3e54b07d6b2557)`(const `[`IntegerPoint2D`](#class_integer_point2_d)` & lhs,const `[`IntegerPoint2D`](#class_integer_point2_d)` & rhs)`            | 
`public std::ostream & `[`operator<<`](#point_8hpp_1a0c561b94b353da7f6990c46fcde21174)`(std::ostream & out,const `[`IntegerPoint2D`](#class_integer_point2_d)` & point)`            | 
`public int `[`main`](#demo_8cpp_1abf9e6b7e6f15df4b525a2e7705ba3089)`(int argc,char const * argv)`            | 
`public std::ostream & `[`operator<<`](#maze__movement_8cpp_1a205f12e9926575f456f95ec8015196eb)`(std::ostream & out,const `[`IntegerMaze2D`](#class_integer_maze2_d)` & maze)`            | 
`public std::ostream & `[`operator<<`](#maze__movement_8cpp_1a79c25305ab19a4f4657485ae3cd099e3)`(std::ostream & out,const `[`IntegerMaze2D::MOVEMENT`](#class_integer_maze2_d_1acef743d89f483882fb6e35b6e5144e32)` & movement)`            | 
`public bool `[`operator==`](#point_8cpp_1a038e147fa170c36c9d3e54b07d6b2557)`(const `[`IntegerPoint2D`](#class_integer_point2_d)` & lhs,const `[`IntegerPoint2D`](#class_integer_point2_d)` & rhs)`            | 
`public std::ostream & `[`operator<<`](#point_8cpp_1a0c561b94b353da7f6990c46fcde21174)`(std::ostream & out,const `[`IntegerPoint2D`](#class_integer_point2_d)` & point)`            | 
`class `[`IntegerPoint2D::Hash`](#class_integer_point2_d_1_1_hash) | Класс для хэширования объектов типа [IntegerPoint2D](#class_integer_point2_d).
`class `[`IntegerMaze2D`](#class_integer_maze2_d) | Класс лабиринт.
`class `[`IntegerPoint2D`](#class_integer_point2_d) | Двумерная точка в целочисленных координатах.
`class `[`IntegerMaze2D::PointsParser`](#class_integer_maze2_d_1_1_points_parser) | Вспомогательный класс для чтения лабиринта из файла.

## Members

#### `public std::ostream & `[`operator<<`](#maze__movement_8hpp_1a79c25305ab19a4f4657485ae3cd099e3)`(std::ostream & out,const `[`IntegerMaze2D::MOVEMENT`](#class_integer_maze2_d_1acef743d89f483882fb6e35b6e5144e32)` & movement)` 

#### `public bool `[`operator==`](#point_8hpp_1a038e147fa170c36c9d3e54b07d6b2557)`(const `[`IntegerPoint2D`](#class_integer_point2_d)` & lhs,const `[`IntegerPoint2D`](#class_integer_point2_d)` & rhs)` 

#### `public std::ostream & `[`operator<<`](#point_8hpp_1a0c561b94b353da7f6990c46fcde21174)`(std::ostream & out,const `[`IntegerPoint2D`](#class_integer_point2_d)` & point)` 

#### `public int `[`main`](#demo_8cpp_1abf9e6b7e6f15df4b525a2e7705ba3089)`(int argc,char const * argv)` 

#### `public std::ostream & `[`operator<<`](#maze__movement_8cpp_1a205f12e9926575f456f95ec8015196eb)`(std::ostream & out,const `[`IntegerMaze2D`](#class_integer_maze2_d)` & maze)` 

#### `public std::ostream & `[`operator<<`](#maze__movement_8cpp_1a79c25305ab19a4f4657485ae3cd099e3)`(std::ostream & out,const `[`IntegerMaze2D::MOVEMENT`](#class_integer_maze2_d_1acef743d89f483882fb6e35b6e5144e32)` & movement)` 

#### `public bool `[`operator==`](#point_8cpp_1a038e147fa170c36c9d3e54b07d6b2557)`(const `[`IntegerPoint2D`](#class_integer_point2_d)` & lhs,const `[`IntegerPoint2D`](#class_integer_point2_d)` & rhs)` 

#### `public std::ostream & `[`operator<<`](#point_8cpp_1a0c561b94b353da7f6990c46fcde21174)`(std::ostream & out,const `[`IntegerPoint2D`](#class_integer_point2_d)` & point)` 

# class `IntegerPoint2D::Hash` 

Класс для хэширования объектов типа [IntegerPoint2D](#class_integer_point2_d).

Для хэширования используется std::hash для каждой координаты, а для коомбинации хэшей boost::hash_combine.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public std::size_t `[`operator()`](#class_integer_point2_d_1_1_hash_1a48ab775b8eb570c020f0e82436286563)`(const `[`IntegerPoint2D`](#class_integer_point2_d)` & point) const` | 

## Members

#### `public std::size_t `[`operator()`](#class_integer_point2_d_1_1_hash_1a48ab775b8eb570c020f0e82436286563)`(const `[`IntegerPoint2D`](#class_integer_point2_d)` & point) const` 

# class `IntegerMaze2D` 

Класс лабиринт.

Лабиринт состоит из секций, которые представляются точками с двумя целочисленными координатами.

Класс представляет функционал навигации по лабиринту:

* шаг по лабиринту.

* движение по заданному маршруту.

и редактирования лабиринта:

* добавление секции.

* удалении секции.

Далее секция=точка.

Внутри лабиринт реализуется с помощью std::unordered_set (хэш таблица) Таким образом добавить, удалить и найти точку в лабиринте можно в большинстве случаев за О(1).

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`IntegerMaze2D`](#class_integer_maze2_d_1a5bc799571abb8ba669cf748e10992b98)`()` | Создать пустой лабиринт
`public  `[`IntegerMaze2D`](#class_integer_maze2_d_1ac438a04b300b330f1ae6da18a7a4891a)`(const std::string & path)` | Загрузка лабиринта из файла.
`public  `[`IntegerMaze2D`](#class_integer_maze2_d_1a9c1992ebeedcd1563e48d5448df2ab19)`(const std::list< `[`IntegerPoint2D`](#class_integer_point2_d)` > & points)` | Создание лабиринта из списка точек
`public std::size_t `[`size`](#class_integer_maze2_d_1a9b58bb9013670de0c2805ddcd67c3a6d)`() const` | Размер лабиринта
`public bool `[`is_empty`](#class_integer_maze2_d_1a6c35347997c6498f19c913b8ab05423a)`() const` | Проверка на пустоту лабиринта
`public bool `[`have_point`](#class_integer_maze2_d_1a9f01d370b28187504a6450da6b486a14)`(const `[`IntegerPoint2D`](#class_integer_point2_d)` & point) const` | Есть ли данная точка в лабиринте.
`public bool `[`have_neighbour`](#class_integer_maze2_d_1a70e75acc01390dd5e942ffb2bf158860)`(const `[`IntegerPoint2D`](#class_integer_point2_d)` & point,const `[`MOVEMENT`](#class_integer_maze2_d_1acef743d89f483882fb6e35b6e5144e32)` & movement) const` | Имеет ли точка смежную.
`public bool `[`add_point`](#class_integer_maze2_d_1a556b6a3798ecf225c00e9900466a9af3)`(const `[`IntegerPoint2D`](#class_integer_point2_d)` & point)` | Добавить точку в лабиринт.
`public bool `[`remove_point`](#class_integer_maze2_d_1a0ee9982e631909c7f276066a10ad60aa)`(const `[`IntegerPoint2D`](#class_integer_point2_d)` & point)` | Удалить точку из лабиринта.
`public `[`IntegerPoint2D`](#class_integer_point2_d)` `[`navigate`](#class_integer_maze2_d_1a45e61187a4e1aa3485da097763e3813f)`(const `[`IntegerPoint2D`](#class_integer_point2_d)` & from,const `[`MOVEMENT`](#class_integer_maze2_d_1acef743d89f483882fb6e35b6e5144e32)` & movement,bool log) const` | Сделать шаг по лабиринту.
`public `[`IntegerPoint2D`](#class_integer_point2_d)` `[`navigate`](#class_integer_maze2_d_1ac19256b4a34989677b38e8131e0e3450)`(const `[`IntegerPoint2D`](#class_integer_point2_d)` & from,const std::list< `[`MOVEMENT`](#class_integer_maze2_d_1acef743d89f483882fb6e35b6e5144e32)` > & movements,bool log) const` | Движение в лабиринте по заданному маршруту.
`enum `[`MOVEMENT`](#class_integer_maze2_d_1acef743d89f483882fb6e35b6e5144e32) | Направление движения в лабиринте.

## Members

#### `public  `[`IntegerMaze2D`](#class_integer_maze2_d_1a5bc799571abb8ba669cf748e10992b98)`()` 

Создать пустой лабиринт

#### `public  `[`IntegerMaze2D`](#class_integer_maze2_d_1ac438a04b300b330f1ae6da18a7a4891a)`(const std::string & path)` 

Загрузка лабиринта из файла.

Файл должен содержать список точек лабиринта через запятую. Точка представляется двумя координатами в скобках через запятую.

Пример: (0, 1), (1, 2), (3, 4), (-5, -15).

Если файл не может быть прочитан или содержит неккоректные данные, то лабиринт все равно создаётся, но будет пустым (не содержать ни одной точки).

#### Parameters
* `path` путь до файла.

#### `public  `[`IntegerMaze2D`](#class_integer_maze2_d_1a9c1992ebeedcd1563e48d5448df2ab19)`(const std::list< `[`IntegerPoint2D`](#class_integer_point2_d)` > & points)` 

Создание лабиринта из списка точек

#### Parameters
* `points` список точек

#### `public std::size_t `[`size`](#class_integer_maze2_d_1a9b58bb9013670de0c2805ddcd67c3a6d)`() const` 

Размер лабиринта

#### `public bool `[`is_empty`](#class_integer_maze2_d_1a6c35347997c6498f19c913b8ab05423a)`() const` 

Проверка на пустоту лабиринта

#### `public bool `[`have_point`](#class_integer_maze2_d_1a9f01d370b28187504a6450da6b486a14)`(const `[`IntegerPoint2D`](#class_integer_point2_d)` & point) const` 

Есть ли данная точка в лабиринте.

#### Parameters
* `point` точка для проверки. 

#### Returns
true если точка есть, иначе false.

#### `public bool `[`have_neighbour`](#class_integer_maze2_d_1a70e75acc01390dd5e942ffb2bf158860)`(const `[`IntegerPoint2D`](#class_integer_point2_d)` & point,const `[`MOVEMENT`](#class_integer_maze2_d_1acef743d89f483882fb6e35b6e5144e32)` & movement) const` 

Имеет ли точка смежную.

#### Parameters
* `point` точка для проверки. 

* `movement` направление для поиска. 

#### Returns
true если точка имеет соседа в данном направление, иначе false.

#### `public bool `[`add_point`](#class_integer_maze2_d_1a556b6a3798ecf225c00e9900466a9af3)`(const `[`IntegerPoint2D`](#class_integer_point2_d)` & point)` 

Добавить точку в лабиринт.

#### Parameters
* `point` точка для добавление. 

#### Returns
true если точка была добавлена, иначе false если точка уже есть в лабиринте.

#### `public bool `[`remove_point`](#class_integer_maze2_d_1a0ee9982e631909c7f276066a10ad60aa)`(const `[`IntegerPoint2D`](#class_integer_point2_d)` & point)` 

Удалить точку из лабиринта.

#### Parameters
* `point` точка для удаления. 

#### Returns
true если точка была удалена, иначе false если такой точки нет в лабиринте.

#### `public `[`IntegerPoint2D`](#class_integer_point2_d)` `[`navigate`](#class_integer_maze2_d_1a45e61187a4e1aa3485da097763e3813f)`(const `[`IntegerPoint2D`](#class_integer_point2_d)` & from,const `[`MOVEMENT`](#class_integer_maze2_d_1acef743d89f483882fb6e35b6e5144e32)` & movement,bool log) const` 

Сделать шаг по лабиринту.

Если в данном направлении нет смежной точки, то координаты начальной точки не меняются. Ошибки при этом не происходит.

#### Parameters
* `from` начальная точка. 

* `movement` направление движения. 

* `log` включает логгирование движения в консоль. 

#### Returns
точка в результате движения.

#### `public `[`IntegerPoint2D`](#class_integer_point2_d)` `[`navigate`](#class_integer_maze2_d_1ac19256b4a34989677b38e8131e0e3450)`(const `[`IntegerPoint2D`](#class_integer_point2_d)` & from,const std::list< `[`MOVEMENT`](#class_integer_maze2_d_1acef743d89f483882fb6e35b6e5144e32)` > & movements,bool log) const` 

Движение в лабиринте по заданному маршруту.

Маршрут представляет собой список элементарных перемещений. Если в данном направлении нет смежной точки, то координаты начальной точки не меняются. Ошибки при этом не происходит.

#### Parameters
* `from` начальная точка. 

* `movements` маршрут (список элементарных движений). 

* `log` включает логгирование движения в консоль. 

#### Returns
точка в результате движения.

#### `enum `[`MOVEMENT`](#class_integer_maze2_d_1acef743d89f483882fb6e35b6e5144e32) 

 Values                         | Descriptions                                
--------------------------------|---------------------------------------------
UP            | 
DOWN            | 
RIGHT            | 
LEFT            | 

Направление движения в лабиринте.

# class `IntegerPoint2D` 

Двумерная точка в целочисленных координатах.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`IntegerPoint2D`](#class_integer_point2_d_1abc9676eb553e5be2428b52f58e8c1381)`()` | 
`public  `[`IntegerPoint2D`](#class_integer_point2_d_1a32263df175b4654b83d25b19edc1dd68)`(const int & x,const int & y)` | 
`public int `[`get_x`](#class_integer_point2_d_1a5205e00d4dcafac45c7b66ba337796b8)`() const` | 
`public int `[`get_y`](#class_integer_point2_d_1ae73ed71b0d2699ddea28fc929b1dff29)`() const` | 
`public std::pair< int, int > `[`get`](#class_integer_point2_d_1af1b33f4d635daab1cc08c6d6d880398a)`() const` | 
`public void `[`set_x`](#class_integer_point2_d_1ad3489ca3e97b9a40e57c7af3c08f9d2b)`(const int & new_x)` | 
`public void `[`set_y`](#class_integer_point2_d_1af3664a19443cdd2180481979569cce01)`(const int & new_y)` | 
`public void `[`set`](#class_integer_point2_d_1aae74c49021c04cff1c9e3b7d25c121a2)`(const int & new_x,const int & new_y)` | 

## Members

#### `public  `[`IntegerPoint2D`](#class_integer_point2_d_1abc9676eb553e5be2428b52f58e8c1381)`()` 

#### `public  `[`IntegerPoint2D`](#class_integer_point2_d_1a32263df175b4654b83d25b19edc1dd68)`(const int & x,const int & y)` 

#### `public int `[`get_x`](#class_integer_point2_d_1a5205e00d4dcafac45c7b66ba337796b8)`() const` 

#### `public int `[`get_y`](#class_integer_point2_d_1ae73ed71b0d2699ddea28fc929b1dff29)`() const` 

#### `public std::pair< int, int > `[`get`](#class_integer_point2_d_1af1b33f4d635daab1cc08c6d6d880398a)`() const` 

#### `public void `[`set_x`](#class_integer_point2_d_1ad3489ca3e97b9a40e57c7af3c08f9d2b)`(const int & new_x)` 

#### `public void `[`set_y`](#class_integer_point2_d_1af3664a19443cdd2180481979569cce01)`(const int & new_y)` 

#### `public void `[`set`](#class_integer_point2_d_1aae74c49021c04cff1c9e3b7d25c121a2)`(const int & new_x,const int & new_y)` 

# class `IntegerMaze2D::PointsParser` 

Вспомогательный класс для чтения лабиринта из файла.

класс реализует функтор, который используется как семантическое действие в парсере boost::spirit::qi.

Парсер необходим для разбора содержимого файла при заполнении лабиринта.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`PointsParser`](#class_integer_maze2_d_1_1_points_parser_1a93a29bc83a53de3085bdd035cd5ab8d6)`(std::unordered_set< `[`IntegerPoint2D](#class_integer_point2_d), [IntegerPoint2D::Hash`](#class_integer_point2_d_1_1_hash)` > & maze_ref)` | 
`public void `[`add_val`](#class_integer_maze2_d_1_1_points_parser_1aaf735f682254167dcabc99d800085ffb)`(const int & val)` | Функция при обнаружении координаты точки

## Members

#### `public  `[`PointsParser`](#class_integer_maze2_d_1_1_points_parser_1a93a29bc83a53de3085bdd035cd5ab8d6)`(std::unordered_set< `[`IntegerPoint2D](#class_integer_point2_d), [IntegerPoint2D::Hash`](#class_integer_point2_d_1_1_hash)` > & maze_ref)` 

#### `public void `[`add_val`](#class_integer_maze2_d_1_1_points_parser_1aaf735f682254167dcabc99d800085ffb)`(const int & val)` 

Функция при обнаружении координаты точки

Функция срабатывает, когда парсер обнаруживает одну из двух координат точки.

Например для файла, содержащего (1, 2), (3, 4) ... Данная функция будет вызвана сначала при обнаружении первой координаты первой точки со значением 1, далее при обнаружении второй координаты со значением 2 и так далее со значениями 3, 4, ...

#### Parameters
* `val` число, обнаруженное парсером.

Generated by [Moxygen](https://sourcey.com/moxygen)