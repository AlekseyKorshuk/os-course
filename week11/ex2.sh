sudo echo "Aliaksei" > file1
sudo echo "Korshuk" > file2
sudo cp file1 lofsdisk/file1
sudo cp file2 lofsdisk/file2

# Copy files with ldd /bin/bash

sudo cp -v --parents /bin/bash lofsdisk
for i in $(ldd /bin/bash | egrep -o '/lib.*\.[0-9]'); do sudo cp -v --parents "$i" "lofsdisk"; done

sudo cp -v --parents /bin/cat lofsdisk
for i in $(ldd /bin/cat | egrep -o '/lib.*\.[0-9]'); do sudo cp -v --parents "$i" "lofsdisk"; done

sudo cp -v --parents /bin/ls lofsdisk
for i in $(ldd /bin/ls | egrep -o '/lib.*\.[0-9]'); do sudo cp -v --parents "$i" "lofsdisk"; done

sudo cp -v --parents /bin/echo lofsdisk
for i in $(ldd /bin/echo | egrep -o '/lib.*\.[0-9]'); do sudo cp -v --parents "$i" "lofsdisk"; done

gcc ex2.c -o ex2.out
sudo cp ex2.out lofsdisk/ex2.out
sudo chroot lofsdisk /ex2.out > ex2.txt
./ex2.out >> ex2.txt


#exit


