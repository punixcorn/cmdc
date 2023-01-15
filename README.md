# very simple clean Command line C

written in bash script, the main idea is to write it in c lolz, for now enjoy bash
<br/>
give the `c` file executable rights and run it, done!

### idea?

- creates a file and puts your code there
- compiles it and runs it
- if it has a compilation error or runtime error from your last entered code, it will delete the line
- did i forget to add it has persistence? it does, untill you kill the program ( it still does lol, unless you restart the program )

### bigger idea?

- creates 2 files( mainly 2 c files, one for persistence and the other not )
- when you input a code say

```c
>> int a = 12;
```

it will be put into both files, but it will be compiled and run from the non-persistent file , after that it will be deleted from the non-persistent file
<br/>
but the persistent file will still hoard it

- if, it finds a compilation error or runtime error , the last line of code will be deleted from both files
- but if this senario happens

```c
printf("this is the value of a : %d",a);
```

- this code will run, compile and work, because if there is a compile error in the non-persistent file, it will clear it and run the persistent file hence any variable declared earlier will be available

### whats wrong with this?

- it's a bad idea
- expect unknown behaviours
- it creates too many files and reads and writes from them, which i dont like

### i wanna run a for loop or a function or something with a block of code

- no you cannot create functions or structs or anything that requires to be out of main as unlike a scripting language, this requires a main entry so what ever you type goes into `main(void)`
- might fix this will a macro you add to create a function or struct or others

- well apart from functions thank the C gods that the line breaker is a semicolon hence unlike others, hence you could theoretically write all your code on one line---
  except its unreadable so , for read-ability

```c
>>for( int i = 0; i < 10 ; i++ ) {\
printf("this is %d",i); \
} \
```

this will get translated into

```c
for( int i = 0; i < 10 ; i++) { printf("this is %d"); }
```

in the file and will run perfectly so all in all any code is possible?
and with persistency it makes it doable , atleast for me
