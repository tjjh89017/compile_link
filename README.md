#Compile & Link Tutorial

##Slide

[slide.pdf](slide.pdf)

##Refernece

[How A Compiler Works: GNU Toolchain](http://www.slideshare.net/jserv/how-a-compiler-works-gnu-toolchain)

[The Internals of "Hello World" Program](http://www.slideshare.net/jserv/helloworld-internals)

[Internal and External Linkage in C](https://github.com/u1240976/mess_note/blob/master/talk/internal_and_external_linkage_in_C.rst)

##General Operation

Preprocess

```
make preprocess
```

Assembly Code Generation

```
make assembly
```

Compilation without linking

```
make object
```

Disassembly

```
make objdump
```

Build executable program

```
make build
```

Do all above

```
make all
```

Clean 

```
make clean
```

##4\_custom\_static

Build additional library

```
make lib
```

##6\_custom\_dynamic

Build additional library

```
make lib
```

Execute with custom shared library

```
make run
```

##7\_preload\_dynamic

Build additional library

```
make lib
```

Execute with libc.so (normal)

```
make normal_run
```

Execute with preload shared library

```
make run
```
