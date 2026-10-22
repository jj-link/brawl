#pragma force_active on
extern "C" {

extern unsigned char lbl_95_data_151C[12];
extern unsigned char g_ftCommonDataAccesser;
void* fn_27_148A9C(void*, int, void*);
void fn_95_15174(void*, int, void*, void*);

struct Pair { int a, b; };
struct Args { Pair* pair; void* data; };
struct Locals {
    bool unused1;
    bool flag;
    Pair unusedPair;
    Pair pair;
    Args args;
};
inline void* getData(void* fighter) {
    return *(void**)(*(char**)((char*)fighter + 0xd8) + 0xc0);
}
extern "C" void* fn_95_9AB0(void* self, void* fighter) {
    *(void**)self = lbl_95_data_151C;
    Locals local;
    local.unused1 = false;
    local.flag = false;
    local.unusedPair.a = 0;
    int kind = local.unusedPair.b = 4;
    void* data = getData(fighter);
    local.pair.a = local.unusedPair.a;
    local.pair.b = local.unusedPair.b;
    local.args.pair = &local.pair;
    local.args.data = data;
    void* common = fn_27_148A9C(&g_ftCommonDataAccesser, kind, &local.flag);
    fn_95_15174((char*)self + 4, 0, &local.args, common);
    return self;
}

}
