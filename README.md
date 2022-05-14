[![Lab05_test](https://github.com/User-XXI/TIMP_Labs/actions/workflows/actions.yml/badge.svg?branch=lab05_master)](https://github.com/User-XXI/TIMP_Labs/actions/workflows/actions.yml)
[![Coverage Status](https://coveralls.io/repos/github/User-XXI/TIMP_Labs/badge.svg?branch=main)](https://coveralls.io/github/User-XXI/TIMP_Labs?branch=main)

## Laboratory work V


Данная лабораторная работа посвещена изучению фреймворков для тестирования на примере **GTest**

```sh
$ open https://github.com/google/googletest
```

Подключаем к репозиторию подмодуль GoogleTest
```shell
$ mkdir third-party
$ git submodule add https://github.com/google/googletest third-party/gtest

Клонирование в «/home/andrey/User-XXI/workspace/projects/TIMP_Labs/third-party/gtest»…
remote: Enumerating objects: 24063, done.
remote: Counting objects: 100% (521/521), done.
remote: Compressing objects: 100% (277/277), done.
remote: Total 24063 (delta 286), reused 368 (delta 230), pack-reused 23542
Получение объектов: 100% (24063/24063), 10.23 МиБ | 2.48 МиБ/с, готово.
Определение изменений: 100% (17674/17674), готово.
```
Выбираем версию
```shell
$ cd third-party/gtest && git checkout release-1.11.0 && cd ../..

Note: switching to 'release-1.11.0'.

You are in 'detached HEAD' state. You can look around, make experimental
changes and commit them, and you can discard any commits you make in this
state without impacting any branches by switching back to a branch.

If you want to create a new branch to retain commits you create, you may
do so (now or later) by using -c with the switch command. Example:

  git switch -c <new-branch-name>

Or undo this operation with:

  git switch -

Turn off this advice by setting config variable advice.detachedHead to false

HEAD сейчас на e2239ee6 Googletest export
```
```shell
$ git add third-party/gtest
$ git commit -m "Created third-party/gtest"

[lab05_master 4dfb41d] Created third-party/gtest
 2 files changed, 4 insertions(+)
 create mode 100644 .gitmodules
 create mode 160000 third-party/gtest
```

```sh
$ cmake -H. -B_build -DBUILD_TESTS=ON

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
-- Found Python: /usr/bin/python3.8 (found version "3.8.10") found components: Interpreter 
-- Looking for pthread.h
-- Looking for pthread.h - found
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD - Failed
-- Looking for pthread_create in pthreads
-- Looking for pthread_create in pthreads - not found
-- Looking for pthread_create in pthread
-- Looking for pthread_create in pthread - found
-- Found Threads: TRUE  
-- Configuring done
-- Generating done
-- Build files have been written to: /home/andrey/User-XXI/workspace/projects/TIMP_Labs/_build
```

```sh
$ cmake --build _build

Scanning dependencies of target account
[  6%] Building CXX object CMakeFiles/account.dir/banking/Account.cpp.o
[ 13%] Linking CXX static library libaccount.a
[ 13%] Built target account
Scanning dependencies of target transaction
[ 20%] Building CXX object CMakeFiles/transaction.dir/banking/Transaction.cpp.o
[ 26%] Linking CXX static library libtransaction.a
[ 26%] Built target transaction
Scanning dependencies of target gtest
[ 33%] Building CXX object third-party/gtest/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
[ 40%] Linking CXX static library ../../../lib/libgtest.a
[ 40%] Built target gtest
Scanning dependencies of target gtest_main
[ 46%] Building CXX object third-party/gtest/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o
[ 53%] Linking CXX static library ../../../lib/libgtest_main.a
[ 53%] Built target gtest_main
Scanning dependencies of target gmock
[ 60%] Building CXX object third-party/gtest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o
[ 66%] Linking CXX static library ../../../lib/libgmock.a
[ 66%] Built target gmock
Scanning dependencies of target gmock_main
[ 73%] Building CXX object third-party/gtest/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o
[ 80%] Linking CXX static library ../../../lib/libgmock_main.a
[ 80%] Built target gmock_main
Scanning dependencies of target check
[ 86%] Building CXX object CMakeFiles/check.dir/tests/test1.cpp.o
[ 93%] Building CXX object CMakeFiles/check.dir/tests/test2.cpp.o
[100%] Linking CXX executable check
[100%] Built target check
```

```sh
$ cmake --build _build --target test

Running tests...
Test project /home/andrey/User-XXI/workspace/projects/TIMP_Labs/_build
    Start 1: check
1/1 Test #1: check ............................   Passed    0.00 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.00 sec
```


```sh
$ _build/check

Running main() from /home/andrey/User-XXI/workspace/projects/TIMP_Labs/third-party/gtest/googletest/src/gtest_main.cc
[==========] Running 5 tests from 2 test suites.
[----------] Global test environment set-up.
[----------] 4 tests from Account
[ RUN      ] Account.GetBalance
[       OK ] Account.GetBalance (0 ms)
[ RUN      ] Account.ChangeBalance
[       OK ] Account.ChangeBalance (0 ms)
[ RUN      ] Account.Lock
[       OK ] Account.Lock (0 ms)
[ RUN      ] Account.Unlock
[       OK ] Account.Unlock (0 ms)
[----------] 4 tests from Account (0 ms total)

[----------] 1 test from Transaction
[ RUN      ] Transaction.SaveToDataBase
[       OK ] Transaction.SaveToDataBase (0 ms)
[----------] 1 test from Transaction (0 ms total)

[----------] Global test environment tear-down
[==========] 5 tests from 2 test suites ran. (0 ms total)
[  PASSED  ] 5 tests.
```
.yml
```yml

name: 'lab05-actions'

on:
   push:
     branches:
       - lab05_master
      
jobs:
  build:
    runs-on: ubuntu-latest
  
    steps:      
      - name: Git clone
        uses: actions/checkout@v1 
        
      - name: Git checkout
        run : git checkout lab05_master
        
      - name: Git pull
        run : git pull origin lab05_master
    
      - name: Test
        shell: bash
        run: |
          cmake -H. -B_build -DBUILD_TESTS=O
          cmake --build _build
          cmake --build _build --target test
          _build/check
          cmake --build _build --target test -- ARGS=--verbose
       
```
### Задание
1. Создайте `CMakeList.txt` для библиотеки *banking*.
2. Создайте модульные тесты на классы `Transaction` и `Account`.
   * Используйте mock-объекты.
   * Покрытие кода должно составлять 100%.
3. Настройте сборочную процедуру на **TravisCI**.
4. Настройте [Coveralls.io](https://coveralls.io/).
5. Проверить собирается ли файл ... `.gcov`, нужен флаг `--coverage` в `CmakeLists`

## Links

- [C++ CI: Travis, CMake, GTest, Coveralls & Appveyor](http://david-grs.github.io/cpp-clang-travis-cmake-gtest-coveralls-appveyor/)
- [Boost.Tests](http://www.boost.org/doc/libs/1_63_0/libs/test/doc/html/)
- [Catch](https://github.com/catchorg/Catch2)


