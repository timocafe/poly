#!/bin/bash


for i in data_p7 data_p8 data_sb data_hw
do
cp $i ${i}_cp
perl stat.pl ${i}_cp > ${i}_n
mv ${i}_n ${i}
rm ${i}_cp
done
