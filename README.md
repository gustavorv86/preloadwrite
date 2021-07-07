# preloadwrite
LD_PRELOAD system call example.

```
gustavorv86@debian:~/preloadwrite$ make
"/usr/bin/gcc" -shared -fPIC -ldl -o preloadwrite.so src/preloadwrite.c
gustavorv86@debian:~/preloadwrite$ echo "hello" > file.txt
gustavorv86@debian:~/preloadwrite$ cat file.txt
hello
gustavorv86@debian:~/preloadwrite$ export LD_PRELOAD=${PWD}/preloadwrite.so
gustavorv86@debian:~/preloadwrite$ cat file.txt
Hello world
hello
Goodbye cruel world
gustavorv86@debian:~/preloadwrite$ unset LD_PRELOAD
```

