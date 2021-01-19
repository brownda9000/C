# Check cpplint
echo "Checking  cpplint ..."
/home/daveb/.local/bin/cpplint graphics1.c
# Check include files
echo "Checking include files ..."
iwyu graphics1.c
echo "Checking clang-tidy files ..."
clang-tidy -checks=-*,clang-analyzer-*,-clang-analyzer-cplusplus* graphics1.c -- -DDEBUG -I./include
echo "Checking cppcheck ..."
#/usr/bin/cppcheck --template={file};{line};{severity};{id};{message} --enable=all --verbose --platform=unix64 --std=c++11 --file-list=-
cppcheck --enable=all --inconclusive --library=posix graphics1.c --check-config --suppress=missingIncludeSystem
echo "Compile application ..."
gcc-10 -fdiagnostics-path-format=separate-events -fsanitize=address -static-libasan   -fanalyzer  -Werror -O0 -Wextra -Wall -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow -ggdb3  -o graphics1 graphics1.c -lcs50 -lgraph
echo "Valgrind memory check ..."
valgrind --leak-check=full ./graphics1
