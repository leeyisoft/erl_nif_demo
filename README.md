https://www.erlang.org/doc/man/erl_nif.html

https://stackoverflow.com/questions/8288358/erlang-nif-test-os-x-lion

Compile and test can look as follows (on MacOS M1):
```
arch -arm64 gcc -fPIC -bundle -flat_namespace -undefined suppress -o niftest.so niftest.c -I "/opt/homebrew/Cellar/erlang@24/24.3.4_1/lib/erlang/usr/include/"
```

Compile and test can look as follows (on MacOS ):
```
gcc -undefined dynamic_lookup -dynamiclib niftest.c -o niftest.so -I "/opt/homebrew/Cellar/erlang@24/24.3.4_1/lib/erlang/usr/include/"
```

Compile and test can look as follows (on Linux):
```
gcc -fPIC -shared -o niftest.so niftest.c -I $ERL_ROOT/usr/include/
```

run erl

```
$> erl

erl
Erlang/OTP 24 [erts-12.3.2] [source] [64-bit] [smp:8:8] [ds:8:8:10] [async-threads:1] [dtrace]

Eshell V12.3.2  (abort with ^G)
1> c(niftest).
{ok,niftest}
2> niftest:sum(1,2).
3
3> niftest:findPrime(50).
[47,43,41,37,31,29,23,19,17,13,11,7,5,3]
```

# other demo
* bitwise: NIF examples showing Erlang scheduler concerns
 [github](https://github.com/vinoski/bitwise)
