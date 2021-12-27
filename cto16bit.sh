printf "\ec\e[44;36m\a\n\n"
bcc $1 -Md -S -o /tmp/tmp 
cat /tmp/tmp | grep -v "!" 

