#include <types.h>
#pragma force_active on

struct Pair {
    void* first;
    void* second;
};

struct PairHolder {
    u32 pad[2];
    Pair pair;
};

extern "C" Pair fn_108_D708(PairHolder* holder) {
    return holder->pair;
}
