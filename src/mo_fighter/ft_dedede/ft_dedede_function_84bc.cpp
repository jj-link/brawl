#pragma force_active on

extern "C" {
extern unsigned char lbl_117_data_15EC[];
extern unsigned char g_ftCommonDataAccesser;
void* fn_27_1488D4(void*, int, void*);
void fn_117_12204(void*, int, void*, void*);
}

struct Pair {
    int a, b;
};

struct Args {
    Pair* pair;
    void* data;
};

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

extern "C" void* fn_117_84BC(void* self, void* fighter) {
    *(void**)self = lbl_117_data_15EC;
    Locals local;
    local.unused = false;
    local.flag = false;
    local.unusedPair.a = 0;
    int kind = local.unusedPair.b = 32;
    void* data = getData(fighter);
    local.pair.a = local.unusedPair.a;
    local.pair.b = local.unusedPair.b;
    local.args.pair = &local.pair;
    local.args.data = data;
    void* common = fn_27_1488D4(&g_ftCommonDataAccesser, kind, &local.flag);
    fn_117_12204((char*)self + 4, 0, &local.args, common);
    return self;
}
