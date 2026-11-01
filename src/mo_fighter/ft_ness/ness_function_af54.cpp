#pragma force_active on
extern "C" {
extern unsigned char lbl_101_data_221C[];
extern unsigned char g_ftCommonDataAccesser;
void* fn_27_149644(void*, int, void*);
void fn_101_168B8(void*, int, void*, void*);
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
extern "C" void* fn_101_AF54(void* self, void* fighter) {
    *(void**)self = lbl_101_data_221C;
    Locals local;
    local.unused = false;
    local.flag = false;
    local.unusedPair.a = 0;
    int kind = local.unusedPair.b = 10;
    void* data = getData(fighter);
    local.pair.a = 0;
    local.pair.b = 10;
    local.args.pair = &local.pair;
    local.args.data = data;
    void* common = fn_27_149644(&g_ftCommonDataAccesser, kind, &local.flag);
    fn_101_168B8((char*)self + 4, 2, &local.args, common);
    return self;
}
