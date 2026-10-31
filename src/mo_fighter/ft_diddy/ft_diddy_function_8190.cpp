#pragma force_active on
extern "C" {
extern unsigned char lbl_115_data_13B4[];
extern unsigned char g_ftCommonDataAccesser;
int fn_27_1489B8(void*, int, bool*);
void fn_27_364EBC(void*, int, void*, int);
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
extern "C" void* fn_115_8190(void* self, void* fighter) {
    *(void**)self = lbl_115_data_13B4;
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
    int common = fn_27_1489B8(&g_ftCommonDataAccesser, kind, &local.flag);
    fn_27_364EBC((char*)self + 4, 0, &local.args, common);
    return self;
}
