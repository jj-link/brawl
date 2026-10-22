#pragma force_active on

extern "C" {
extern unsigned char lbl_105_data_1654[];
extern unsigned char g_ftCommonDataAccesser;
void* fn_27_1491C4(void*, int, void*);
void fn_105_16184(void*, int, void*, void*);
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

extern "C" void* fn_105_9B38(void* self, void* fighter) {
    *(void**)self = lbl_105_data_1654;
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
    void* common = fn_27_1491C4(&g_ftCommonDataAccesser, kind, &local.flag);
    fn_105_16184((char*)self + 4, 0, &local.args, common);
    return self;
}
