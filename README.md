# Unix Directory Tree in C
A C program to list contents of directories in a tree format. It will only lists the contents of the current directory.
At the end of the tree, it will also prints the total number of files and directories listed.
This project is an example of how N-ary tree traversals could be useful. 

## How to Use
### Option 1 [Easy]
* Copy 'treedir' executable file from the repo to your /bin/ folder
`sudo cp treedir /usr/local/bin`
* Run `treedir` from any directory

### Option 2
* Make C compiler (gcc) is installed
* Git clone the repo
* Type `make` (see Makefile for more details)
* Copy 'treedir' executable file from the repo to your /bin/ folder (need admin access)
`sudo cp treedir /usr/local/bin`
* Run `treedir` from any directory

## Sample Output
* Green: Folder
* Pink: Other files with no `.` in the file name (e.g. executable file, Makefile, etc.)
<img src="https://github.com/tiffanymarthin/directory-tree/blob/main/treedir_ss1.png" width="400"/>
<img src="https://github.com/tiffanymarthin/directory-tree/blob/main/treedir_ss3.png" width="400"/>
