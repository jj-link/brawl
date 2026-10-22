#pragma force_active on
extern "C" {
extern char lbl_122_data_774C[];
extern char g_ftCommonDataAccesser[];
void* fn_27_149B58(void* accesser, int k, void* out);
void fn_27_1DF5F8(void* self, int size, void* args, void* p, int flag);
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
extern "C" void* fn_122_C928(void* self, void* fighter) {
    *(void**)self = lbl_122_data_774C;
    Locals local;
    local.unused = false;
    local.flag = false;
    local.unusedPair.a = 0;
    int kind = local.unusedPair.b = 0x2e;
    void* data = getData(fighter);
    local.pair.a = local.unusedPair.a;
    local.pair.b = local.unusedPair.b;
    local.args.pair = &local.pair;
    local.args.data = data;
    void* common = fn_27_149B58(g_ftCommonDataAccesser, kind, &local.flag);
    fn_27_1DF5F8((char*)self + 4, 0xc, &local.args, common, 0);
    return self;
}
