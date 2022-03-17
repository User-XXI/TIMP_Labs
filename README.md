#
___

### Задание 1
Вам поручили перейти на систему автоматизированной сборки **CMake**.
Исходные файлы находятся в директории [formatter_lib](formatter_lib).
В этой директории находятся файлы для статической библиотеки *formatter*.
Создайте `CMakeList.txt` в директории [formatter_lib](formatter_lib),
с помощью которого можно будет собирать статическую библиотеку *formatter*.

```sh
$ cat > CMakeLists.txt <<EOF
> cmake_minimum_required(VERSION 3.4)
> project (lab03)
> 
> set(CMAKE_CXX_STANDARD 11)
> set(CMAKE_CXX_STANDARD_REQUIRED ON)
> 
> add_library(formatter STATIC ${CMAKE_CURRENT_SOURCE_DIR}/formatter.cpp)
>
> include_directories(${CMAKE_CURRENT_SOURCE_DIR})
> EOF
```

```shell
$ cmake -H. -B_build

-- Configuring done
-- Generating done
-- Build files have been written to: /home/andrey/User-XXI/workspace/projects/lab03/TIMP_Labs/formatter_lib/_build
```

```shell
$ cmake --build _build

Scanning dependencies of target formatter
[ 50%] Building CXX object CMakeFiles/formatter.dir/formatter.cpp.o
[100%] Linking CXX static library libformatter.a
[100%] Built target formatter

```


### Задание 2 
У компании "Formatter Inc." есть перспективная библиотека,
которая является расширением предыдущей библиотеки. Т.к. вы уже овладели
навыком созданием `CMakeList.txt` для статической библиотеки *formatter*, ваш
руководитель поручает заняться созданием `CMakeList.txt` для библиотеки
*formatter_ex*, которая в свою очередь использует библиотеку *formatter*.

```shell
$ edit formatter_ex.cpp

- | #include "formatter.h"

+ | #include "../formatter_lib/formatter.h"
```

```shell
$ cat > CMakeLists.txt <<EOF
> cmake_minimum_required(VERSION 3.4)
> project(lab03_2)
> 
> set(CMAKE_CXX_STANDART 11)
> set(CMAKE_CXX_STANDART_REQUIRED ON)
> 
> include_directories("../formatter_lib")
>
> add_library(formatter_ex_lib STATIC ${CMAKE_CURRENT_SOURCE_DIR}/formatter_ex.cpp)
>
> target_link_libraries(formatter_ex_lib formatter_lib)
> EOF
```

```shell
$ cmake -H. -B _build

-- The C compiler identification is GNU 9.4.0
-- The CXX compiler identification is GNU 9.4.0
-- Check for working C compiler: /usr/bin/cc
-- Check for working C compiler: /usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: /home/andrey/User-XXI/workspace/projects/lab03/TIMP_Labs/formatter_ex_lib/_build
```

```shell
$ cmake --build _build

Scanning dependencies of target formatter_ex_lib
[ 50%] Building CXX object CMakeFiles/formatter_ex_lib.dir/formatter_ex.cpp.o
[100%] Linking CXX static library libformatter_ex_lib.a
[100%] Built target formatter_ex_lib

```

### Задание 3
Конечно же ваша компания предоставляет примеры использования своих библиотек.
Чтобы продемонстрировать как работать с библиотекой *formatter_ex*,
вам необходимо создать два `CMakeList.txt` для двух простых приложений:
* *hello_world*, которое использует библиотеку *formatter_ex*;
* *solver*, приложение которое испольует статические библиотеки *formatter_ex* и *solver_lib*.

**Удачной стажировки!**

## Links
- [Основы сборки проектов на С/C++ при помощи CMake](https://eax.me/cmake/)
- [CMake Tutorial](http://neerc.ifmo.ru/wiki/index.php?title=CMake_Tutorial)
- [C++ Tutorial - make & CMake](https://www.bogotobogo.com/cplusplus/make.php)
- [Autotools](http://www.gnu.org/software/automake/manual/html_node/Autotools-Introduction.html)
- [CMake](https://cgold.readthedocs.io/en/latest/index.html)

```