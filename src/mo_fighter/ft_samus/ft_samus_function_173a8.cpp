#pragma force_active on
extern "C" {
extern unsigned char lbl_94_data_B40C[];
extern unsigned char g_ftCommonDataAccesser;
void* fn_27_148BD0(void*, int, void*);
void fn_27_30424C(void*, int, void*, void*);
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
extern "C" void* fn_94_173A8(void* self, void* fighter) {
    *(void**)self = lbl_94_data_B40C;
    Locals local;
    local.unused = false;
    local.flag = false;
    local.unusedPair.a = 0;
    int kind = local.unusedPair.b = 0x18;
    void* data = getData(fighter);
    local.pair.a = local.unusedPair.a;
    local.pair.b = local.unusedPair.b;
    local.args.pair = &local.pair;
    local.args.data = data;
    void* common = fn_27_148BD0(&g_ftCommonDataAccesser, kind, &local.flag);
    fn_27_30424C((char*)self + 4, 1, &local.args, common);
    return self;
}
