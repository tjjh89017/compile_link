#Compile & Link Tutorial

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

