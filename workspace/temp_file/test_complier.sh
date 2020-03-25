




echo "========================================"
echo " make ing....."
echo "========================================="
make 
if [ $? -ne 0 ];then
    echo "make failed"
fi
echo ""

echo "========================================="
echo "working......"
echo "========================================="

echo "" > compiler_test_output.txt
num=1
for file in `ls test/compiler_tests/`
do
    if [ -d file ]
    then
        echo "not a file"
    else
        path="test/compiler_tests/"$file
        for test_file in `ls ${path}`
        do
            echo "" >> compiler_test_output.txt
            filepath=$path"/"$test_file

            echo "=========================================" >> translate_test_output.txt
            echo "====="$filepath"======">>compiler_test_output.txt
            echo "=========================================" >> translate_test_output.txt
        
            bin/main $filepath >> compiler_test_output.txt
            if [ $? -ne 0 ];then
                echo "======failed============="$filepath
            fi
            echo "" >>compiler_test_output.txt
            echo "" >>compiler_test_output.txt
            echo "" >>compiler_test_output.txt
           

            num=`expr $num + 1`            
        done
        
        
    fi
done    
echo ""
echo "total "$num" test"

echo "All passed"
echo "done"