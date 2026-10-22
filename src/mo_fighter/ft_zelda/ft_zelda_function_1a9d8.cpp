#pragma force_active on
extern "C" {
extern unsigned char lbl_104_data_A0B8[];
extern unsigned char g_ftCommonDataAccesser;
void* fn_27_148C54(void*, int, void*);
void fn_27_33D1C4(void*, int, void*, void*);
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
extern "C" void* fn_104_1A9D8(void* self, void* fighter) {
    *(void**)self = lbl_104_data_A0B8;
    Locals local;
    local.unused = false;
    local.flag = false;
    local.unusedPair.a = 0;
    int kind = local.unusedPair.b = 14;
    void* data = getData(fighter);
    local.pair.a = local.unusedPair.a;
    local.pair.b = local.unusedPair.b;
    local.args.pair = &local.pair;
    local.args.data = data;
    void* common = fn_27_148C54(&g_ftCommonDataAccesser, kind, &local.flag);
    fn_27_33D1C4((char*)self + 4, 0, &local.args, common);
    return self;
}
