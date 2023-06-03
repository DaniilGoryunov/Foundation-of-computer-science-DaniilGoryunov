from os import *

print('enter the suffix')
suffix = input()
if suffix=='--help':
    while suffix=='--help':
        print("myrename [suffix] [prefix] [directory]")
        print('enter the suffix')
        suffix = input()
print('enter the prefix')
prefix = input()
print('enter the directory')
directory = input() 

chdir(directory)

files = listdir()

for file in files:
    if file.endswith(suffix):
        new_name = prefix + file
        rename(file, new_name)
