# How to create a static linked library
1. Add at least a source file and a header file with the declaration of things you want to share between the libraries
2. Compile the object file for the code with the G++ flag -c: `g++ -c ./exampleLib/Logging.cpp -o ./exampleLib/Logging.o`
3. Using the resulting object file, compile using the program ar with rvs: `ar rvs ./exampleLib/liblogging.a ./exampleLib/Logging.o` (remember to use the [lib]libraryname[.a] pattern)
    - ar command explanation:
        - r:  replace existing or insert new file(s) into the archive
        - v be verbose
        - act as ranlib
4. Now you use the library normaly by adding it to the compilation command of your project: `g++ ./source/Main.cpp -I./exampleLib -L./exampleLib -llogging`
5. Done, now you have a statically linked library produced in your project
