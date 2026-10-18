#include <types.h>
#pragma force_active on

struct Pair8 {
    u32 a;
    u32 b;
};

struct Donkey92Obj {
    u32 unk0;
    u32 unk4;
    Pair8 pair;
};

extern "C" Pair8 fn_92_BAE8(Donkey92Obj* obj) {
    return obj->pair;
}
