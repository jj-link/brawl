#pragma force_active on

struct Data28 {
    unsigned char padding[0x28];
    unsigned char flags;
};

extern "C" {
extern unsigned char lbl_8042E8FC[0x64];
extern int lbl_805A00F0;
extern int lbl_805A00F4;
extern Data28** g_GameGlobal;

void __dl__FPv(void*);
void __dt__6gfTaskFv(void*, int);
}

struct Task {
    unsigned char padding[0x3C];
    void* unk3C;
};

extern "C" Task* fn_8005A1A4(Task* p, int flag) {
    if (p) {
        p->unk3C = lbl_8042E8FC;
        lbl_805A00F4 = 0;
        (*g_GameGlobal)->flags &= ~0x20;
        lbl_805A00F0 = 0;
        __dt__6gfTaskFv(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
