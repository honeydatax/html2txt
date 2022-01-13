printf "\ec\e[44;36m\n"
cp $1 $1.txt
sed -i 's/\t//g' $1.txt
#sed -i 's/  //g' $1.txt
tr -d '\n' < $1.txt > /tmp/1
tr -d '\r' < /tmp/1  > $1.txt
sed -i 's/<br>/\n/g' $1.txt
sed -i 's/<p>/\n/g' $1.txt 
./html2txt $1.txt
rm /tmp/1
