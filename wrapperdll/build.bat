﻿set OutDirectory=%2
mkdir "%OutDirectory%"

RMDIR /S /Q build_x86
mkdir build_x86
cmake -B build_x86\ -S .\ -A "WIN32"
cmake --build .\build_x86\. --config %1
copy build_x86\%1\wrapperdll.dll "%OutDirectory%wrapperdll-x86.dll"

RMDIR /S /Q build_x64
mkdir build_x64
cmake -B build_x64\ -S .\ –A "x64"
cmake --build .\build_x64\. --config %1
copy build_x64\%1\wrapperdll.dll "%OutDirectory%wrapperdll-x64.dll"
