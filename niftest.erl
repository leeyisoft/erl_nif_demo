-module(niftest).

-export([init/0, hello/0, upgrade/0, findPrime/1, sum/2]).

-nifs([hello/0]).

-on_load(init/0).

init() ->
      erlang:load_nif("./niftest", 0).

upgrade() ->
      erlang:upgrade_nif("./niftest", 0).

hello() ->
      erlang:nif_error("NIF library not loaded").

findPrime(_N) ->
      io:format("this function is not defined!~n").

sum(_A, _B) ->
      erlang:nif_error("NIF library not loaded").

% $> gcc -fPIC -shared -o niftest.so niftest.c -I "/opt/homebrew/Cellar/erlang@24/24.3.4_1/lib/erlang/usr/include/"
% on macos usccess
% gcc -undefined dynamic_lookup -dynamiclib niftest.c -o niftest.so -I "/opt/homebrew/Cellar/erlang@24/24.3.4_1/lib/erlang/usr/include/"
% arch -arm64 gcc -fPIC -bundle -flat_namespace -undefined suppress -o niftest.so niftest.c -I "/opt/homebrew/Cellar/erlang@24/24.3.4_1/lib/erlang/usr/include/"

% gcc -fPIC -bundle -flat_namespace -undefined suppress -o niftest.so niftest.c -I "/opt/homebrew/Cellar/erlang@24/24.3.4_1/lib/erlang/usr/include/"
% $> erl
%
% 1> c(niftest).
% {ok,niftest}
% 2> niftest:hello().
% "Hello world!"
