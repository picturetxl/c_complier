

num=1
for file in `ls test/compiler_tests/*/*.c`
do
    echo "work on "$file
    obj="tmp/mips/"$num".s"
    
    touch $obj
    mips-linux-gnu-gcc -mfp32  $file -o $obj
    num=`expr $num + 1`
done