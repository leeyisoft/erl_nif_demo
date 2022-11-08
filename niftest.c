/* niftest.c */
#include <erl_nif.h>
#include <stdbool.h>
#include <math.h>

static ERL_NIF_TERM hello(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    return enif_make_string(env, "Hello world!", ERL_NIF_LATIN1);
}

static ERL_NIF_TERM sum(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    int a, b;
    if(!enif_get_int(env, argv[0], &a))
            return enif_make_badarg(env);
    if(!enif_get_int(env, argv[1], &b))
            return enif_make_badarg(env);
    return enif_make_int(env, a + b);
}

static bool isPrime(int i)
{
    int j;
    int t = sqrt(i) + 1;
    for(j = 2; j <= t; ++j)
    {
            if(i % j == 0)
                    return false;
    }
    return true;
}

static ERL_NIF_TERM findPrime(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
        int n;
        if(!enif_get_int(env, argv[0], &n))
                return enif_make_badarg(env);
        else
        {
                int i;
                ERL_NIF_TERM res = enif_make_list(env, 0);
                for(i = 2; i < n; ++i)
                {
                        if(isPrime(i))
                                res = enif_make_list_cell(env, enif_make_int(env, i), res);
                }
                return res;
        }
}

static ErlNifFunc nif_funcs[] =
{
    {"hello", 0, hello},
    {"findPrime", 1, findPrime},
    {"sum", 2, sum}
};

static int load(ErlNifEnv* env, void** priv, ERL_NIF_TERM load_info)
{
    return 0;
}

static int upgrade(ErlNifEnv* caller_env, void** priv_data,
           void** old_priv_data, ERL_NIF_TERM load_info)
{
    return 0;
}

ERL_NIF_INIT(niftest, nif_funcs, load, NULL, upgrade, NULL)
// ERL_NIF_INIT(niftest, nif_funcs, NULL, NULL, NULL, NULL)
// ERL_NIF_INIT(niftest, nif_funcs, load, reload, upgrade, unload)

