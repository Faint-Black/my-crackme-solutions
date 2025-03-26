#!/bin/bash

if [ -z "$1" ]; then
    echo "provide the binary executable's name!"
    exit 1
fi

if [ ! -e "$1" ]; then
    echo "ERROR" > dump.txt
    echo "executable file \"$1\" does not exist!"
    exit 1
fi

echo "Binary name: $1" > dump.txt

echo " "                                                                         >> dump.txt
echo "+============+"                                                            >> dump.txt
echo "|  ELF DATA  |"                                                            >> dump.txt
echo "+============+===========================================================" >> dump.txt
readelf --all $1                                                                 >> dump.txt
echo "=========================================================================" >> dump.txt
echo " "                                                                         >> dump.txt
echo " "                                                                         >> dump.txt
echo "+===========+"                                                             >> dump.txt
echo "|  .RODATA  |"                                                             >> dump.txt
echo "+===========+============================================================" >> dump.txt
readelf -x .rodata $1                                                            >> dump.txt
echo "=========================================================================" >> dump.txt
echo " "                                                                         >> dump.txt
echo " "                                                                         >> dump.txt
echo "+=========+"                                                               >> dump.txt
echo "|  .DATA  |"                                                               >> dump.txt
echo "+=========+==============================================================" >> dump.txt
readelf -x .data $1                                                              >> dump.txt
echo "=========================================================================" >> dump.txt
echo " "                                                                         >> dump.txt
echo " "                                                                         >> dump.txt
echo "+========+"                                                                >> dump.txt
echo "|  .BSS  |"                                                                >> dump.txt
echo "+========+===============================================================" >> dump.txt
echo " "                                                                         >> dump.txt
size -x $1 | awk 'NR==2 {print $3 " Amount of bytes allocated"}'                 >> dump.txt
echo " "                                                                         >> dump.txt
echo "=========================================================================" >> dump.txt
echo " "                                                                         >> dump.txt
echo " "                                                                         >> dump.txt
echo "+=================================+"                                       >> dump.txt
echo "|  BINARY EXECUTABLE DISASSEMBLY  |"                                       >> dump.txt
echo "+=================================+======================================" >> dump.txt
objdump -d -M intel $1                                                           >> dump.txt
echo "=========================================================================" >> dump.txt
echo " "                                                                         >> dump.txt
echo " "                                                                         >> dump.txt

echo "Success!"
