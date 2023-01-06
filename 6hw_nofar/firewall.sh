#!/bin/bash

pkt=$(cat -)
rules="$1"


[[ ! -f "$rules" ]] && exit
##remove extra spaces from the rules file
rules=$(sed -e 's/#.*//g' -e '/^$/d' "$rules")

   while read line; do
   ##separte fileds
   line_sep=$(echo "$line" |\
   awk '{split($0,val,/,/);for(i=1;i<=length(val);i++) print val[i] }')
   length=$(echo "$line" |\
   awk '{split($0,val,/,/); print length(val)}')

   out=$pkt

   for((i=0;i<"$length";i++));do
      array_line[i]=$(echo "$line_sep" | head -n $i | tail -n 1)
   done

   for i in ${array_line[@]} 
      do
          out=$(echo "$out" |./firewall.exe "$i")
      done
   output=$(echo -e "$out"'\n'"$output")
done < <(echo "$rules")

echo "$output" | sort | sed -e 's/\ //g' -e '/^$/d'|uniq 
