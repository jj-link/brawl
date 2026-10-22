#pragma force_active on
extern "C" {
extern unsigned char lbl_125_data_1E34[];
extern unsigned char g_ftCommonDataAccesser;
void* fn_27_1487F0(void*, int, void*);
void fn_125_E99C(void*, int, void*, void*);
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
extern "C" void* fn_125_993C(void* self, void* fighter) {
    *(void**)self = lbl_125_data_1E34;
    Locals local;
    local.unused = false;
    local.flag = false;
    local.unusedPair.a = 0;
    int kind = local.unusedPair.b = 0x2c;
    void* data = getData(fighter);
    local.pair.a = local.unusedPair.a;
    local.pair.b = local.unusedPair.b;
    local.args.pair = &local.pair;
    local.args.data = data;
    void* common = fn_27_1487F0(&g_ftCommonDataAccesser, kind, &local.flag);
    fn_125_E99C((char*)self + 4, 2, &local.args, common);
    return self;
}
