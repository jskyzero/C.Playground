# How to run it

+ I assume you use linux, for instance ubuntu
+ then use `sudo apt-get install libopenmpi-dev` to install
+ use `mpicc helloworld.c` to compile c code to `a.out`
+ then use `mpirun -np 4 a.out` to run.

you will see some output like
```
helloworld
helloworld
helloworld
helloworld
``` 