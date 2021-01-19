cppcheck --xml --xml-version=2 . 2>report-src.xml
genhtml coverage.info --output-directory out
gcc-10 -fanalyzer -fdiagnostics-path-format=separate-events -g -Wall -o r_w_structs  test.c
lcov -c -i -d . -o app_base.info
./r_w_structs
lcov -c -d . -o app_test.info
lcov -a app_base.info -a app_test.info -o app_total.info
lcov --capture --directory . --output-file coverage.info
gcov -b r_w_structs.c
scan-build clang++ -c r_w_structs.c
scan-build -v -v -v --keep-going -o /tmp/myclangdir/ clang -W -Wall -c r_w_structs.c
scan-build --keep-going -o /tmp/myclangdir/ clang -W -Wall -c
cppinclude  --report unresolved
