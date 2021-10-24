mkdir ../week1
touch ../week1/file.txt
echo "Aliaksei Korshuk" > ../week1/file.txt
mkdir ../week10

link ../week1/file.txt  _ex2.txt

node=($(ls -i _ex2.txt));

find ../week1/file.txt -inum $node > ex2.txt

cp ../week1/file.txt file.txt

find ../week1/file.txt -inum $node -exec rm {} \; >> ex2.txt
