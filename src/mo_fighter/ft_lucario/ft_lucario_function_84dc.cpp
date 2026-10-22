#pragma force_active on
extern "C" {
extern void* fn_27_1494D0(void*, int, void*);
extern void fn_27_39BDA8(void*, int, void*, void*);
extern unsigned char g_ftCommonDataAccesser;
extern unsigned char lbl_118_data_1158[];
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

extern "C" void* fn_118_84DC(void* self, void* fighter) {
    *(void**)self = lbl_118_data_1158;
    Locals local;
    local.unused = false;
    local.flag = false;
    local.unusedPair.a = 0;
    int kind = local.unusedPair.b = 33;
    void* data = *(void**)(*(char**)((char*)fighter + 0xd8) + 0xc0);
    local.pair.a = local.unusedPair.a;
    local.pair.b = local.unusedPair.b;
    local.args.pair = &local.pair;
    local.args.data = data;
    void* common = fn_27_1494D0(&g_ftCommonDataAccesser, kind, &local.flag);
    fn_27_39BDA8((char*)self + 4, 0, &local.args, common);
    return self;
}
