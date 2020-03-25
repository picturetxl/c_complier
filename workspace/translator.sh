
echo "========================================"
echo " make ing....."
echo "========================================="
make 

echo ""

echo "========================================="
echo "working......"
echo "========================================="


num=1
outputfilepath="test/translate_output/"
for file in `ls test/translator_tests/tests/*.c`
do
    if [ -d file ]
    then
        echo "not a file"
    else
        # path=$file
        # echo $path
        
        # echo "=========================================" >> $outputfile
        # echo "====="$path"======">>$outputfile
        # echo "=========================================" >> $outputfile
        
        outputfile=$outputfilepath"$num"".py"
        echo $outfile
        echo "" >> $outputfile
        echo $outputfile
        bin/main --translate $file -o $outputfile
        if [ $? -ne 0 ];then
            echo "======failed============="$file
        fi
        echo "" >> $outputfile
        echo "" >> $outputfile
        echo "" >> $outputfile
      
        echo -n "-"
        num=`expr $num + 1`
        
    fi
done    
echo ""
echo "total "$num" test"

echo "All passed"
echo "done"