#pragma force_active on
extern "C" {
extern unsigned char lbl_115_data_188C[];
extern unsigned char g_ftCommonDataAccesser;
void* fn_27_148A4C(void*, int, void*);
void fn_115_13524(void*, int, void*, void*);
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
extern "C" void* fn_115_80FC(void* self, void* fighter) {
    *(void**)self = lbl_115_data_188C;
    Locals local;
    local.unused = false;
    local.flag = false;
    local.unusedPair.a = 0;
    int kind = local.unusedPair.b = 27;
    void* data = getData(fighter);
    local.pair.a = local.unusedPair.a;
    local.pair.b = local.unusedPair.b;
    local.args.pair = &local.pair;
    local.args.data = data;
    void* common = fn_27_148A4C(&g_ftCommonDataAccesser, kind, &local.flag);
    fn_115_13524((char*)self + 4, 1, &local.args, common);
    return self;
}
