printf "\ec\e[44;36m\n"
cat $1 | sed 's/\t//g' | sed 's/  //g' | tr -d '\n' | tr -d '\r' | sed 's/<br>/\n/g' | sed 's/<p>/\n/g' | ./html2txt

