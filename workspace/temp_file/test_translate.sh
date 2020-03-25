
echo "========================================"
echo " make ing....."
echo "========================================="
make 

echo ""

echo "========================================="
echo "working......"
echo "========================================="


num=1

echo "" > translate_test_output.txt
for file in `ls test/translator_tests/tests`
do
    if [ -d file ]
    then
        echo "not a file"
    else
        path="test/translator_tests/tests/"$file
        
        echo "=========================================" >> translate_test_output.txt
        echo "====="$path"======">>translate_test_output.txt
        echo "=========================================" >> translate_test_output.txt
        
        echo "" >> translate_test_output.txt
        bin/main $path >> translate_test_output.txt
        if [ $? -ne 0 ];then
            echo "======failed============="$path
        fi
        echo "" >> translate_test_output.txt
        echo "" >> translate_test_output.txt
        echo "" >> translate_test_output.txt
      
        echo -n "-"
        num=`expr $num + 1`
        
    fi
done    
echo ""
echo "total "$num" test"

echo "All passed"
echo "done"