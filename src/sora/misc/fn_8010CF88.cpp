#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_8010D0F0(void*, void*, void*);

extern void* g_GameGlobal;
extern void* lbl_805A0348;

struct GameGlobal {
    char pad[0x30];
    void* unk30;
};

struct Obj {
    char pad[0x620];
    unsigned long word;
};

extern "C" void* fn_8010CF88(void* a, void* b) {
    GameGlobal* g = (GameGlobal*)g_GameGlobal;
    Obj* o = (Obj*)g->unk30;
    unsigned long w = o->word & 0xFF000000UL;
    if (w != 0x2A000000UL && (int)b == 0) {
        return 0;
    }
    void* p = __nw__FUlQ25Heaps8HeapType(0x40C, 0x28);
    if (p != 0) {
        p = fn_8010D0F0(p, a, b);
    }
    lbl_805A0348 = p;
    return p;
}
