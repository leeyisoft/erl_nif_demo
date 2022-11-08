https://www.erlang.org/doc/man/erl_nif.html

https://stackoverflow.com/questions/8288358/erlang-nif-test-os-x-lion

Compile and test can look as follows (on MacOS M1):
```
arch -arm64 gcc -fPIC -bundle -flat_namespace -undefined suppress -o niftest.so niftest.c -I "/opt/homebrew/Cellar/erlang@24/24.3.4_1/lib/erlang/usr/include/"
```

Compile and test can look as follows (on MacOS ):
```
gcc -undefined dynamic_lookup -dynamiclib niftest.c -o niftest.so -I "/opt/homebrew/Cellar/erlang@24/24.3.4_1/lib/erlang/usr/include/"

Compile and test can look as follows (on Linux):
```
gcc -fPIC -shared -o niftest.so niftest.c -I $ERL_ROOT/usr/include/
```

run erl
```
% $> erl
%
% 1> c(niftest).
% {ok,niftest}
% 2> niftest:hello().
% "Hello world!"
```
