#pragma force_active on
extern "C" {
extern unsigned char lbl_98_data_20C4[];
extern unsigned char g_ftCommonDataAccesser;
void* fn_27_1480CC(void*, int, void*);
void fn_27_3269C4(void*, int, void*, void*);
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
extern "C" void* fn_98_8CD0(void* self, void* fighter) {
    *(void**)self = lbl_98_data_20C4;
    Locals local;
    local.unused = false;
    local.flag = false;
    local.unusedPair.a = 0;
    int kind = local.unusedPair.b = 7;
    void* data = getData(fighter);
    local.pair.a = local.unusedPair.a;
    local.pair.b = local.unusedPair.b;
    local.args.pair = &local.pair;
    local.args.data = data;
    void* common = fn_27_1480CC(&g_ftCommonDataAccesser, kind, &local.flag);
    fn_27_3269C4((char*)self + 4, 3, &local.args, common);
    return self;
}
