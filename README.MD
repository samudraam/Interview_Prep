g++ main.cpp -o main && ./main

g++ main.cpp: Invokes the C++ compiler on your source file.-o main: Names the generated executable file main instead of the default a.out / a.exe.&&: Chain operator that only executes the next command if compilation succeeds../main: Instantly executes the compiled binary.