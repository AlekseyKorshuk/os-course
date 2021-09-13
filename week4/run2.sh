gcc ex2.c -o ex2
./ex2 &
for i in 0 1 2 3 4 5 6 7 8 9 10
  do
    pstree $$
  done