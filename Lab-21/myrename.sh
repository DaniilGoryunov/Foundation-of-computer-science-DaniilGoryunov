#!/bin/bash

#error
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
if (( $# != 3 )); then #error
    die "Usage: $0 [directory] [suffix] [prefix]"
fi


# проход по файлам в директории
for file in "$name_dir"/*
do
    file_name="$(basename "$file")" # полное имя файла
    echo $file_name
    file_ext="${file_name##*.}" # берем расширение
    new_file_name="$name_dir"/"$prefix""$file_name" # создаем новое имя файла
    if [[ $file_ext == $suffix ]]; then 
        mv $file $new_file_name
    fi
done
