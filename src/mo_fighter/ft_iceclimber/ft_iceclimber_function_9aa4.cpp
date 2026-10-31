#pragma force_active on

extern "C" {
extern unsigned char lbl_105_data_1D8C[];
extern unsigned char g_ftCommonDataAccesser;
void* fn_27_1491DC(void*, int, void*);
void fn_27_348538(void*, int, void*, void*);
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

extern "C" void* fn_105_9AA4(void* self, void* fighter) {
    *(void**)self = lbl_105_data_1D8C;
    Locals local;
    local.unused = false;
    local.flag = false;
    local.unusedPair.a = 0;
    int kind = local.unusedPair.b = 15;
    void* data = getData(fighter);
    local.pair.a = local.unusedPair.a;
    local.pair.b = local.unusedPair.b;
    local.args.pair = &local.pair;
    local.args.data = data;
    void* common = fn_27_1491DC(&g_ftCommonDataAccesser, kind, &local.flag);
    fn_27_348538((char*)self + 4, 1, &local.args, common);
    return self;
}
