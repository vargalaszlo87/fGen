@echo off &setlocal
Rem Easy Builder for C on Windows
Rem Author: vargalaszlo.com 
Rem ---
Rem set files of project
set bin=fGen.exe
set sources=main signals operands outputs adjust create
Rem creating
if not exist build mkdir build
if not exist bin mkdir bin
Rem cleaning
rm -f build/*.*
Rem compiling
for %%v in (%sources%) do  gcc -c src/%%v.c -o build/%%v.o -I"include"
Rem building
for %%v in (%sources%) do call set "obj=%%obj%% build/%%v.o" 
gcc %obj% -o bin/%bin%
pause