#pragma force_active on
extern "C" {
extern unsigned char lbl_108_data_1A30[];
extern unsigned char g_ftCommonDataAccesser;
void* fn_27_148620(void*, int, void*);
void fn_27_354048(void*, int, void*, void*);
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
extern "C" void* fn_108_9978(void* self, void* fighter) {
    *(void**)self = lbl_108_data_1A30;
    Locals local;
    local.unused = false;
    local.flag = false;
    local.unusedPair.a = 0;
    int kind = local.unusedPair.b = 19;
    void* data = getData(fighter);
    local.pair.a = local.unusedPair.a;
    local.pair.b = local.unusedPair.b;
    local.args.pair = &local.pair;
    local.args.data = data;
    void* common = fn_27_148620(&g_ftCommonDataAccesser, kind, &local.flag);
    fn_27_354048((char*)self + 4, 1, &local.args, common);
    return self;
}
