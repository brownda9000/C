#!/usr/bin/bash
clear
echo " C Memory and code checks"
echo " ------------------------"

PS3="Select the C tools operation: "

select opt in gcc infer gprof quit; do

  case $opt in
    gcc)
      make ;
      ./bin/mem1 ;;
    infer)
         infer run -- gcc -c src/mem1.c;
       ;;
    gprof)
         gprof ./bin/mem1  gmon.out >> app_gprof_data.txt;
         gprof2dot  app_gprof_data.txt | dot -Tpng -o profiling.png 
       ;;

   quit)
      break;;
    *)
      echo "Invalid option $REPLY";;
  esac
done
