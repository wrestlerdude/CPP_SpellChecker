runa:
	./test

runb:
	./spell sentences_test.txt
	./spell single_words_test.txt

partb: lib buildalphabet clean

parta: lib buildtest clean

clean:
	rm BinarySearchTree.o bst.a

clean2:
	rm spell test

lib:
	g++ -std=c++11 -c -Wall BinarySearchTree.cpp
	ar rcs bst.a BinarySearchTree.o
	
buildtest:
	g++ -std=c++11 test.cpp bst.a -o test

buildalphabet:
	g++ -std=c++11 main.cpp stream.cpp tokens.cpp bst.a -o spell

