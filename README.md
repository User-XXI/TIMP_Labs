## Laboratory work V
### *Не завершена*

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
### Задание
1. Создайте `CMakeList.txt` для библиотеки *banking*.
2. Создайте модульные тесты на классы `Transaction` и `Account`.
    * Используйте mock-объекты.
    * Покрытие кода должно составлять 100%.
3. Настройте сборочную процедуру на **TravisCI**.
4. Настройте [Coveralls.io](https://coveralls.io/).

## Links

- [C++ CI: Travis, CMake, GTest, Coveralls & Appveyor](http://david-grs.github.io/cpp-clang-travis-cmake-gtest-coveralls-appveyor/)
- [Boost.Tests](http://www.boost.org/doc/libs/1_63_0/libs/test/doc/html/)
- [Catch](https://github.com/catchorg/Catch2)


