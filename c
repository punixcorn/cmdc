#!/bin/bash
file=/tmp/main.c
tempf=/tmp/tempcfile
instream=1
term=0

function remove_blank(){
	awk 'NF' $file > $tempf
	if [ -f $tempf ];then
	cat $tempf > $file
	else
	echo "$tempf not found"
	fi
	echo "" > $tempf
}

function Err_runtime(){
    if [ $1 -ne 0 ];then
    head -n -1 $file > $tempf; mv $tempf $file
    fi
}

function Err_compile(){
    if [ $1 -ne 0 ];then
    head -n -2 $file > $tempf;mv $tempf $file
    else
    head -n -1 $file > $tempf; mv $tempf $file
    ./main
    Err_runtime $?
    fi
}

function mainrunner(){
    if [[ $1 -eq 0 ]];then
    printf "#include<custom.h>\nint main(void){\n" > $file
    fi
    printf "\n"
    read -p ">>" string
    if [ "$string" = "compile" ] || [ "$string" = "cc" ];then
        printf "\nreturn 0;}" >> $file
        remove_blank
	    cc $file -o main
        Err_compile $?
    elif [[ "$string"  = "view"  ]];then
        printf "\nreturn 0;}" >> $file
        remove_blank
        cat $file
        head -n -1 $file > $tempf; mv $tempf $file
    else
        echo $string >> $file
        printf "\nreturn 0;}" >> $file
        remove_blank
	    cc $file -o main
        Err_compile $?
    fi
}

printf "%s\n%s\n%s\n%s\n%s" "simple Command line C" "it creates a file, runs your code and compile to output result" "stuff you can do" "compile what you have done so far : cc / compile" "view your code : view"
while [ $instream = 1 ];do
    mainrunner $term
    (( term++ ))
done
instream=0
