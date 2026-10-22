#pragma force_active on
extern "C" {
extern unsigned char lbl_112_data_16A0[];
extern unsigned char g_ftCommonDataAccesser;
void* fn_27_1490FC(void*, int, void*);
void fn_27_35D9F8(void*, int, void*, void*);
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
extern "C" void* fn_112_8FC8(void* self, void* fighter) {
    *(void**)self = lbl_112_data_16A0;
    Locals local;
    local.unused = false;
    local.flag = false;
    local.unusedPair.a = 0;
    int kind = local.unusedPair.b = 23;
    void* data = getData(fighter);
    local.pair.a = local.unusedPair.a;
    local.pair.b = local.unusedPair.b;
    local.args.pair = &local.pair;
    local.args.data = data;
    void* common = fn_27_1490FC(&g_ftCommonDataAccesser, kind, &local.flag);
    fn_27_35D9F8((char*)self + 4, 1, &local.args, common);
    return self;
}
