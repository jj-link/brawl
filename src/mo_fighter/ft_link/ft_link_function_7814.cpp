#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_93_data_1DE8[];
extern char g_ftCommonDataAccesser;
s32 fn_27_147E6C(void*, s32, void*);
void fn_27_2E0F24(void*, s32, void*, s32);
}

struct Pair { int a, b; };
struct Args { Pair* pair; void* data; };
struct Locals {
    bool unused;
    bool flag;
    Pair unusedPair;
    Pair pair;
    Args args;
};
inline void* getData(void* fighter) {
    return *(void**)(*(char**)((char*)fighter + 0xd8) + 0xc0);
}

extern "C" void* fn_93_7814(void* self, void* fighter) {
    *(void**)self = lbl_93_data_1DE8;
    Locals local;
    local.unused = false;
    local.flag = false;
    local.unusedPair.a = 0;
    int kind = local.unusedPair.b = 2;
    void* data = getData(fighter);
    local.pair.a = local.unusedPair.a;
    local.pair.b = local.unusedPair.b;
    local.args.pair = &local.pair;
    local.args.data = data;
    s32 common = fn_27_147E6C(&g_ftCommonDataAccesser, kind, &local.flag);
    fn_27_2E0F24((char*)self + 4, 1, &local.args, common);
    return self;
}
