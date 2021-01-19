gcc-10 -fanalyzer -fdiagnostics-path-format=separate-events -g -Wall -o r_w_structs  test.c
# Static code analysis
splint test.c
cpplint test.c
cppcheck --xml --xml-version=2 . 2>report-src.xml
 mkdir VIMs_SRC && /usr/bin/cppcheck-htmlreport --source-dir=. --title=VIMs_SRC --file=report-src.xml --report-dir=VIMs_SRC
clang-tidy-10 -checks='modernize-use-override' test.c -- -std=c++11
