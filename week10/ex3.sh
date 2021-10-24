touch _ex3.txt
echo "Aliaksei Korshuk" > _ex3.txt

chmod ugo-x _ex3.txt
ls -l _ex3.txt  > ex3.txt

chmod uo+rwx _ex3.txt >> ex3.txt
ls -l _ex3.txt  >> ex3.txt

chmod g=u _ex3.txt
ls -l _ex3.txt  >> ex3.txt

