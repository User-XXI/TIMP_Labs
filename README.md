## Laboratory work II
*Максимов Андрей*

Данная лабораторная работа посвещена изучению систем контроля версий на примере **Git**.
___
## Homework

### Part I


***1.** Создайте пустой репозиторий на сервисе [github.com](https://github.com/).*

```sh
$ cd ~/User-XXI/workspace/projects
$ mkdir lab02
$ cd lab02
$ git init
$ git config --global user.name ${GITHUB_USERNAME}
$ git config --global user.email ${GITHUB_EMAIL}
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab02.git
$ git pull origin master
$ touch README.md
$ git status
$ git add README.md
$ git commit -m"added README.md"
$ git push origin master
```

***2.** Выполните инструкцию по созданию первого коммита на странице репозитория, созданного на предыдещем шаге.*

Создаём файл `.gitignore`

```sh
$ cat .gitignore  <<EOF
*build*/ 
*install*/
*.swp
.idea/
EOF
```
Загружаем его на GitHub

```sh
$ git add .gitignore
$ git commit -m"created .gitignore"
$ git push origin master
```

***3.** Создайте файл `hello_world.cpp` в локальной копии репозитория (который должен был появиться на шаге 2). Реализуйте программу **Hello world** на языке C++ используя плохой стиль кода. Например, после заголовочных файлов вставьте строку `using namespace std;`.*

```sh
$ cat > sources/hello_world.cpp <<EOF
#include <iostream>
using namespace std;
int main(int argc, char** argv){cout << "Hello world from User-XXI" << endl; return 0;}
EOF
```

***4.** Добавьте этот файл в локальную копию репозитория.*

```sh
$ git add sources/hello_world.cpp
```

***5.** Закоммитьте изменения с *осмысленным* сообщением.*

```sh
$ git commit -m"added hello_world.cpp"
```

***6.** Изменитьте исходный код так, чтобы программа через стандартный поток ввода запрашивалось имя пользователя. А в стандартный поток вывода печаталось сообщение `Hello world from @name`, где `@name` имя пользователя.*

```sh
$ cat > sources/hello_world.cpp <<EOF
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char** argv){string name;cout << "Input user_name";cin >> name;cout << "Hello world from " << name << endl; return 0;}
EOF
```

***7.** Закоммитьте новую версию программы. Почему не надо добавлять файл повторно `git add`?*

```sh
$ git commit sources/hello_world.cpp -m"Changed hello_world.cpp"
```

***8.** Запуште изменения в удалёный репозиторий.*

```sh
$ git push origin master
```

***9.** Проверьте, что история коммитов доступна в удалёный репозитории.*
___
### Part II

**Note:** *Работать продолжайте с теми же репоззиториями, что и в первой части задания.*

***1.** В локальной копии репозитория создайте локальную ветку `patch1`.*
```bash
$ git checkout -b patch1
```

***2.** Внесите изменения в ветке `patch1` по исправлению кода и избавления от `using namespace std;`.*

```bash
$ cat > sources/hello_world.cpp <<EOF
#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    std::string name;
    std::cout << "Input user_name";
    std::cin >> name;
    std::cout << "Hello world from " << name << std::endl;
    return 0;
}

EOF
```

***3.** **commit**, **push** локальную ветку в удалённый репозиторий.*

```bash
$ git status
$ git add examples
$ git commit -m"Created examples"
$ git add include
$ git commit -m"Created include"
$ git add sources
$ git commit -m"Created sources"
$ git push origin patch1
```
Вывод команды:

<details>

```bash
Username for 'https://github.com': User-XXI
Password for 'https://User-XXI@github.com': 
Перечисление объектов: 15, готово.
Подсчет объектов: 100% (15/15), готово.
При сжатии изменений используется до 8 потоков
Сжатие объектов: 100% (13/13), готово.
Запись объектов: 100% (14/14), 1.44 КиБ | 1.44 МиБ/с, готово.
Всего 14 (изменения 2), повторно использовано 0 (изменения 0)
remote: Resolving deltas: 100% (2/2), done.
remote: 
remote: Create a pull request for 'patch1' on GitHub by visiting:
remote:      https://github.com/User-XXI/lab02/pull/new/patch1
remote: 
To https://github.com/User-XXI/lab02.git
 * [new branch]      patch1 -> patch1
```
</details>

***4.** Проверьте, что ветка `patch1` доступна в удалёный репозитории.*


***5.** Создайте pull-request `patch1 -> master`.*


***6.** В локальной копии в ветке `patch1` добавьте в исходный код комментарии.*

```bash
$ cat > sources/hello_world.cpp <<EOF
#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    std::string name; // Инициальзируем переменную name типа string
    std::cout << "Input user_name"; // Просим ввести имя пользователя
    std::cin >> name; // Запрашиваем значение переменной name из потока ввода вывода
    std::cout << "Hello world from " << name << std::endl; // Выводим преветствие
    return 0;
}

EOF
```
***7.** **commit**, **push**.*

```bash
$ git status
$ git commit -a -m"Added comments"
$ git push origin patch1
```

***8.** Проверьте, что новые изменения есть в созданном на **шаге 5** pull-request*


***9.** В удалённый репозитории выполните  слияние PR `patch1 -> master` и удалите ветку `patch1` в удаленном репозитории.*


***10.** Локально выполните **pull**.*

```bash
$ git pull origin master
```

Вывод программы

<details>

```bash
Из https://github.com/User-XXI/lab02
 * branch            master     -> FETCH_HEAD
Уже обновлено.
```

</details>

***11.** С помощью команды **git log** просмотрите историю в локальной версии ветки `master`.*

```bash
$ git log
```
Вывод программы

<details>

```bash
commit fac9507f84f0b5c48f3b55fa2571d96f55015bb4 (HEAD -> patch1)
commit fac9507f84f0b5c48f3b55fa2571d96f55015bb4 (HEAD -> patch1)
Merge: ac93ed5 4d208b1
Author: User-XXI <andmak96@gmail.com>
Date:   Tue Mar 8 19:22:33 2022 +0300

    Added comments

commit ac93ed56e39372525cd6ce2a98d26ba90c82667e (origin/patch1)
Author: User-XXI <andmak96@gmail.com>
Date:   Tue Mar 8 19:16:57 2022 +0300

    Added comments

commit 511f551302be2faeeada9b2d08d9645e3e71fd1d
Author: User-XXI <andmak96@gmail.com>
Date:   Tue Mar 8 18:55:36 2022 +0300

    Created sources
commit fac9507f84f0b5c48f3b55fa2571d96f55015bb4 (HEAD -> patch1)
Merge: ac93ed5 4d208b1
Author: User-XXI <andmak96@gmail.com>
Date:   Tue Mar 8 19:22:33 2022 +0300

    Added comments

commit ac93ed56e39372525cd6ce2a98d26ba90c82667e (origin/patch1)
Author: User-XXI <andmak96@gmail.com>
Date:   Tue Mar 8 19:16:57 2022 +0300

    Added comments

commit 511f551302be2faeeada9b2d08d9645e3e71fd1d
Author: User-XXI <andmak96@gmail.com>
Date:   Tue Mar 8 18:55:36 2022 +0300

    Created sources

commit 63eaae0074bacc1445054302e2610bb737cd132f
Author: User-XXI <andmak96@gmail.com>
Date:   Tue Mar 8 18:55:24 2022 +0300

    Created include

commit 3828c1adf1994cfc1c928a35bab6d2ebb0237799
Author: User-XXI <andmak96@gmail.com>
Date:   Tue Mar 8 18:55:09 2022 +0300

    Created examples

commit 4d208b15377a7e53b05cc7204ef92a626af837d2 (origin/master)
Author: User-XXI <andmak96@gmail.com>
Date:   Tue Mar 8 15:27:06 2022 +0300

    Changed hello_world.cpp

commit 864254bfb3f98f7b740fb4bfa20c1d3988febb90
Author: User-XXI <andmak96@gmail.com>
Date:   Tue Mar 8 15:24:24 2022 +0300

    added hello_world.cpp

commit f1d75e568e9955e70331d3769a9fc520f2f26f3e
Author: User-XXI <andmak96@gmail.com>
Date:   Tue Mar 8 15:21:19 2022 +0300

    Created sources

commit 662a71a01b84dbb46fa92901def73a79f30d59c1
Author: User-XXI <andmak96@gmail.com>
Date:   Tue Mar 8 15:21:06 2022 +0300

    Created include

commit 1bfa5df3e526e4de3eb8b98fdbe282800e4827ac
    Created sources

commit 662a71a01b84dbb46fa92901def73a79f30d59c1
Author: User-XXI <andmak96@gmail.com>
Date:   Tue Mar 8 15:21:06 2022 +0300

    Created include

commit 1bfa5df3e526e4de3eb8b98fdbe282800e4827ac
Author: User-XXI <andmak96@gmail.com>
Date:   Tue Mar 8 15:20:51 2022 +0300

    Created examples

commit b34df2201b23618f2ae625c03ddf50abb902be5c
Author: User-XXI <andmak96@gmail.com>
Date:   Tue Mar 8 15:16:34 2022 +0300

    added README.md

commit 5ffe783078ae786a9075c5523012754ad1e22b7b
Author: User-XXI <andmak96@gmail.com>
Date:   Tue Mar 8 15:14:26 2022 +0300

    0

commit e6c765d9bdf960477a668def9d53fec2f5139514 (patch2, master)
Author: User-XXI <andmak96@gmail.com>
Date:   Tue Mar 8 15:08:24 2022 +0300

    ""

commit 951f1595cf77a72fdc708d7a8ec47af9d8cac8cb
Author: User-XXI <andmak96@gmail.com>
Date:   Tue Mar 8 14:53:09 2022 +0300

    added hello_world.cpp

commit a279e38a53cd37d237cbfc91dc5c51ac58c2d029
Author: User-XXI <andmak96@gmail.com>
Date:   Tue Mar 8 14:41:46 2022 +0300

    added hello_world.cpp

commit dd402f5f1627573a1dd48b317f39f64b4a0f9f9a
Author: User-XXI <andmak96@gmail.com>
Date:   Tue Mar 8 14:39:44 2022 +0300

    added sources

commit fab018403f84d116a7dc4aa84fced6c2d5990cdb
Author: User-XXI <andmak96@gmail.com>
Date:   Tue Mar 8 13:55:47 2022 +0300

    added sources

commit 02a3cd3d64a85098600eadd9b3d37dd05a417585
Author: User-XXI <andmak96@gmail.com>
Date:   Tue Mar 8 13:55:33 2022 +0300

    added include

commit 1f8eeac26b317ea611f1129e97c8d0029d6b6802
Author: User-XXI <andmak96@gmail.com>
Date:   Tue Mar 8 13:55:10 2022 +0300

    added examples

commit 95701137db73fa2bc5b1817cde7bec7dfe684c70
Author: User-XXI <andmak96@gmail.com>
Date:   Tue Mar 8 13:54:04 2022 +0300

    created .gitignore

commit a3db673261fbe17b1a23be4949b1e13de1437820
Author: User-XXI <andmak96@gmail.com>
Date:   Tue Mar 8 13:15:36 2022 +0300

    added README.md
(END)
```

</details>

***12.** Удалите локальную ветку `patch1`.*

```bash
$ git branch -d patch1
>> Ветка patch1 удалена (была fac9507).
```
___

### Part III

**Note:** *Работать продолжайте с теми же репоззиториями, что и в первой части задания.*
***1.** Создайте новую локальную ветку `patch2`.*

```bash
$ git checkout -b patch2
$ git checkout patch2
$ git clone https://github.com/User-XXI/lab02.git -b master
```

***2.** Измените *code style* с помощью утилиты [**clang-format**](http://clang.llvm.org/docs/ClangFormat.html). Например, используя опцию `-style=Mozilla`.*

```bash
$ clang-format -style=Mozilla -i ./sources/hello_world.cpp
```

***3.** **commit**, **push**, создайте pull-request `patch2 -> master`.*

```bash
$ git status
$ git add examples
$ git commit -m"Created examples"
$ git add include
$ git commit -m"Created include"
$ git add sources
$ git commit -m"Created sources"
$ git push origin patch2
```

***4.** В ветке **master** в удаленном репозитории измените комментарии, например, расставьте знаки препинания, переведите комментарии на другой язык.*


***5.** Убедитесь, что в pull-request появились *конфликтны*.*

***6.** Для этого локально выполните **pull** + **rebase** (точную последовательность команд, следует узнать самостоятельно). **Исправьте конфликты**.*

```bash
$ git checkout master
$ git pull origin master
$ git checkout patch2
```

```bash
$ git add sources/hello_world.cpp
$ git rebase master
$ git rebase --continue
```

***7.** Сделайте *force push* в ветку `patch2`*

```bash
$ git push -f origin patch2
```

Вывод программы:

<details>

```bash
Username for 'https://github.com': User-XXI
Password for 'https://User-XXI@github.com': 
Перечисление объектов: 10, готово.
Подсчет объектов: 100% (10/10), готово.
При сжатии изменений используется до 8 потоков
Сжатие объектов: 100% (9/9), готово.
Запись объектов: 100% (9/9), 1.26 КиБ | 1.26 МиБ/с, готово.
Всего 9 (изменения 2), повторно использовано 0 (изменения 0)
remote: Resolving deltas: 100% (2/2), completed with 1 local object.
To https://github.com/User-XXI/lab02.git
 + c533e10...a390524 patch2 -> patch2 (forced update)
```

</details>

***8.** Убедитель, что в pull-request пропали конфликтны.*


***9.** Вмержите pull-request `patch2 -> master`.*



## Links

- [hub](https://hub.github.com/)
- [GitHub](https://github.com)
- [Bitbucket](https://bitbucket.org)
- [Gitlab](https://about.gitlab.com)
- [LearnGitBranching](http://learngitbranching.js.org/)

```
Copyright (c) 2015-2021 The ISC Authors
```
