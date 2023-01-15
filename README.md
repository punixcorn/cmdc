# very simple clean Command line C

written in bash script
the main idea is to write it in c lolz, for now enjoy bash

### idea?

- creates a file and puts your code there
- compiles it and runs it
- if it has a compilation error or runtime error from your last entered code, it will delete the line
- did i forget to add it has persistence? it does, untill you kill the program ( it still does lol, unless you restart the program )

### whats wrong with this?

- it's a bad idea
- if you wanted to run each line of code individualy you can't, it will run all at once ( could be a simple fix );
- expect unknown behaviours

### i wanna run a for loop or a function or something with a block of code

well thank the C gods that the line breaker is a semicolon hence unlike someone you could theoretically write all your code on one line
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
and with persistency it makes it better or worst , i dunno
