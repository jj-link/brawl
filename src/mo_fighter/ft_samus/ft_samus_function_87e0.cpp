#pragma force_active on
typedef unsigned char u8;
extern "C" {
extern unsigned char lbl_94_data_35CC[];
extern unsigned char g_ftCommonDataAccesser;
void* fn_27_14943C(void*, int, void*);
void fn_27_2F26DC(void*, int, void*, void*);
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
extern "C" void* fn_94_87E0(void* self, void* fighter) {
    *(void**)self = lbl_94_data_35CC;
    Locals local;
    local.unused = false;
    local.flag = false;
    local.unusedPair.a = 0;
    int kind = local.unusedPair.b = 3;
    void* data = getData(fighter);
    local.pair.a = local.unusedPair.a;
    local.pair.b = local.unusedPair.b;
    local.args.pair = &local.pair;
    local.args.data = data;
    void* common = fn_27_14943C(&g_ftCommonDataAccesser, kind, &local.flag);
    fn_27_2F26DC((char*)self + 4, 4, &local.args, common);
    return self;
}
