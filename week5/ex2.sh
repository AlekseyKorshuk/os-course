if [ ! -f num.txt ]; then
  echo "0" > num.txt
fi

while [ $(tail -1 num.txt ) -le 999 ]; do
  if ln num.txt num.lock
  then
    (cat num.txt | tail -n 1 | tr "\012" "+"; echo "1") | bc >> num.txt;
    rm num.lock
    fi
  done