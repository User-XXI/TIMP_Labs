# Laboratory work III
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
> project(formatter_ex_lib)
> 
> set(CMAKE_CXX_STANDART 11)
> set(CMAKE_CXX_STANDART_REQUIRED ON)
> 
> add_library(formatter_exlib STATIC ${CMAKE_CURRENT_SOURCE_DIR}/formatter_ex.cpp)
>
> add_executable(formatter_ex ${CMAKE_CURRENT_SOURCE_DIR}/formatter_ex.cpp)
> 
> 
> include_directories(${CMAKE_CURRENT_SOURCE_DIR})
> include_directories("../formatter_lib")
> 
> target_link_libraries(formatter_ex /formatter_lib/formatter)
> EOF
```

```shell
$ cmake -H. -B_build
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
Scanning dependencies of target formatter_exlib
[ 25%] Building CXX object CMakeFiles/formatter_exlib.dir/formatter_ex.cpp.o
[ 50%] Linking CXX static library libformatter_exlib.a
[ 50%] Built target formatter_exlib
Scanning dependencies of target formatter_ex
[ 75%] Building CXX object CMakeFiles/formatter_ex.dir/formatter_ex.cpp.o
[100%] Linking CXX executable formatter_ex
/usr/bin/ld: /usr/lib/gcc/x86_64-linux-gnu/9/../../../x86_64-linux-gnu/Scrt1.o: в функции «_start»:
(.text+0x24): неопределённая ссылка на «main»
/usr/bin/ld: CMakeFiles/formatter_ex.dir/formatter_ex.cpp.o: в функции «formatter(std::ostream&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)»:
formatter_ex.cpp:(.text+0x33): неопределённая ссылка на «formatter(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)»
collect2: error: ld returned 1 exit status
make[2]: *** [CMakeFiles/formatter_ex.dir/build.make:85: formatter_ex] Ошибка 1
make[1]: *** [CMakeFiles/Makefile2:78: CMakeFiles/formatter_ex.dir/all] Ошибка 2
make: *** [Makefile:84: all] Ошибка 2
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
