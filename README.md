#TOOLCHAIN USED TO COMPILE PROGRAM:
GNU Compiler Collection's G++ v7.2.0 using C++11 standard.

#About spell:
This program spellcheck's the users textfile input (on program enter or
as part of an arg) against a provided dictionary.txt. It then displays the mispelled words and how many are misspelled. This is all done via the command-line.

#About test:
Pre-supplied test code-file applies test-cases on the methods created for bst.h.

#How-to build and usage:
To build the test use the command "make parta". To run the test you can
use `make runa` or `./test`. To build the spellchecker use "make partb". You can either
run the spellchecker by using "./spell" and then enter the textfile on prompt,
use `./spell <filename>` or if you want to run the spellchecker on the two test files provided,
just use "make runb".

`clean` cleans the library files.
`clean2` cleans the executables.


The output will be as follows:

Mispelled words:
{Vertical list of mispelled words}

(# mispelled words)
