#pragma force_active on
extern "C" {
extern unsigned char lbl_116_data_1478[];
extern unsigned char g_ftCommonDataAccesser;
int fn_27_148198(void*, int, void*);
void fn_27_369AF0(void*, int, void*, int);
}

struct Pair { int a, b; };
struct Args { Pair* pair; void* data; };
struct Locals {
    bool unused;
    bool flag;
    int pad;
    Pair pair;
    int extra;
    Args args;
};

inline void* getData(void* fighter) {
    return *(void**)(*(char**)((char*)fighter + 0xd8) + 0xc0);
}

struct Out {
    void* f0;
    void* f1;
};

extern "C" Out* fn_116_8CF8(Out* self, void* fighter) {
    *(void**)self = lbl_116_data_1478;
    Locals local;
    local.unused = false;
    local.flag = false;
    local.pad = 0;
    int kind = local.pair.a = 29;
    void* data = getData(fighter);
    local.pair.b = 0;
    local.extra = local.pair.a;
    local.args.pair = (Pair*)&local.pair.b;
    local.args.data = data;
    int common = fn_27_148198(&g_ftCommonDataAccesser, kind, &local.flag);
    fn_27_369AF0((char*)self + 4, 0, &local.args, common);
    return self;
}
