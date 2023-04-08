#!/bin/bash
persistent_file=/tmp/main_persistence.c
n_persistence_file=/tmp/main_npersistence.c
tempf=/tmp/tempcpersistent_file #for main.c file edits
tempf2=/tmp/tempcpersistent_file2 #for handling errors
dummyfile=/tmp/dummyfile
cmpf=/tmp/cmpfile
err_runtime=0
instream=1
term=0
touch $dummyfile >/dev/null 2>&1

function remove_blank(){
	awk 'NF' $1 > $tempf
	if [ -f $tempf ];then
	cat $tempf > $1
	else
	echo "$tempf not found"
	fi
    echo "" > $tempf
}

function Err_runtime(){
    if [ $1 -ne 0 ];then
    head -n -1 $2 > $tempf; mv $tempf $2
    err_runtime=1
    else
    if [ "$2"  = "/tmp/main_npersistence.c" ];then
        head -n -1 $2 > $tempf; mv $tempf $2
    fi
    cmp -s $tempf2 $cmpf || cat $tempf2
    err_runtime=0
    echo $tempf2 > $cmpf
    fi
}

function Err_compile(){
    if [ $1 -ne 0 ];then # error
    head -n -2 $2 > $tempf; mv $tempf $2
    err_runtime=1
    else # no errors
    head -n -1 $2 > $tempf; mv $tempf $2
    head -n -1 $3 > $tempf; mv $tempf $3
    ./main >$tempf2 2>&1
    Err_runtime $? $2
    fi
}

function runmain(){
    cc $n_persistence_file -o main >/dev/null 2>&1
    Err_compile $? $n_persistence_file $persistent_file
    if [ $err_runtime -eq 1 ];then
        cc $persistent_file -o main 
        Err_compile $? $persistent_file $dummyfile
        err_runtime=0
    fi
}

function mainrunner(){
    if [[ $1 -eq 0 ]];then
    printf "#include<custom.h>\nint main(void){\n" > $persistent_file
    printf "#include<custom.h>\nint main(void){\n" > $n_persistence_file
    fi
    printf "\n"
    read -p ">>" string
    if [ "$string" = "compile" ] || [ "$string" = "cc" ];then
        printf "\nreturn 0;}" >> $persistent_file
        remove_blank $persistent_file 
        cc $persistent_file -o main
        Err_compile $? $persistent_file $dummyfile

    elif [[ "$string"  = "view"  ]];then
        printf "\nreturn 0;}" >> $persistent_file
        remove_blank $persistent_file
        cat $persistent_file
        head -n -1 $persistent_file > $tempf; mv $tempf $persistent_file
    else
        echo $string >> $persistent_file
        echo $string >> $n_persistence_file
        printf "\nreturn 0;}" >> $persistent_file
        printf "\nreturn 0;}" >> $n_persistence_file
        remove_blank $persistent_file
        remove_blank $n_persistence_file
        runmain
    fi
}

printf "%s\n%s\n%s\n%s\n%s" "simple Command line C" "it creates a file, runs your code and compile to output result" "stuff you can do" "compile what you have done so far : cc / compile" "view your code : view"
while [ $instream = 1 ];do
    mainrunner $term
    (( term++ ))
done
instream=0
