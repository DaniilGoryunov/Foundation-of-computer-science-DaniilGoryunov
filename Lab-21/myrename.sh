#!/bin/bash

function die() {
    echo "$@" >&2
    exit 1
}
if [[ $1 == "--help" ]]; then
    echo "myrename [directory] [suffix] [prefix]"
    exit 0
fi

name_dir=$1
suffix=$2
prefix=$3
if (( $# != 3 )); then
    die "Недостаточно аргументов. Пожалуйста, передайте в качестве аргумента имя. Пример: $0 Desktop/МАИ/первый txt 123"
fi
for file in "$name_dir"/*
do 
    file_name="$(basename "$file")"
    file_ext="${file_name##*.}"
    if [[ $file_ext == $suffix ]]; then 
        mv $file "$name_dir"/"$prefix""$file_name"
    fi
done