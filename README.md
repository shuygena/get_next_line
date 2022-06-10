# get_next_line

## Requirements:  
gcc compiler. 

## Download & Compile
Clone repository:
```
git clone https://github.com/shuygena/get_next_line gnl
```
Go to directory:
```
cd gnl 
```
To use the function in your code, simply include its header:
```C
#include "get_next_line.h"
```
Function Prototype:  
```C
int	get_next_line(int fd, char **line);
```
For compile program run:
```
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=[xx] *.c
```
