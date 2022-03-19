[![lab04-actions](https://github.com/User-XXI/TIMP_Labs/actions/workflows/actions.yml/badge.svg?branch=lab04_master)](https://github.com/User-XXI/TIMP_Labs/actions/workflows/actions.yml)

## Laboratory work IV

Данная лабораторная работа посвещена изучению систем непрерывной интеграции на примере сервиса **[GitHub Actions](https://github.com/features/actions)**

___

Вы продолжаете проходить стажировку в "Formatter Inc." (см [подробности](https://github.com/tp-labs/lab03#Homework)).

В прошлый раз ваше задание заключалось в настройке автоматизированной системы **CMake**.

Сейчас вам требуется настроить систему непрерывной интеграции для библиотек и приложений, с которыми вы работали в [прошлый раз](https://github.com/tp-labs/lab03#Homework). Настройте сборочные процедуры на различных платформах:
* используйте [GitHub Actions](https://github.com/features/actions) для сборки на операционной системе **Linux** с использованием компиляторов **gcc** и **clang**;
* используйте [AppVeyor](https://www.appveyor.com/) для сборки на операционной системе **Windows**.

```bash
$ mkdir .githud
$ cd .githud
$ mkdir workflows
$ touch actions.yml
```
Заполняем файл `actions.yml`

```bash
cat > actions.yml <<EOF
> name: 'lab04-actions'
> on:
>   push:
>     branches:
>       - lab04_master
>      
> jobs:
>   build:
>     runs-on: ubuntu-latest
>   
>     steps:      
>       - name: Git clone
>         uses: actions/checkout@v1 
>         
>       - name: Git checkout
>         run : git checkout lab04_master
>         
>       - name: Git pull
>         run : git pull origin lab04_master
>     
>       - name: Test_formatter_lib
>         working-directory: formatter_lib
>         shell: bash
>         run: |
>           cmake -H. -B_build
>           cmake --build _build
>          
>       - name: Test_formatter_ex_lib
>         working-directory: formatter_ex_lib
>         shell: bash
>         run: |
>           cmake -H. -B_build
>           cmake --build _build
>          
>       - name: Test_hello_world_application
>         working-directory: hello_world_application
>         shell: bash
>         run: |
>           cmake -H. -B_build
>          cmake --build _build
> EOF
```