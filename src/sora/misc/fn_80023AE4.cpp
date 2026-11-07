#include <types.h>
#pragma force_active on

extern "C" {
void fn_801F0A30();
void fn_801F0CE8(void (*)());
void fn_80023ECC(void*);
void fn_8002402C(void*);
void fn_801F08D8(u16);
void fn_80023D90();
void GXSetDrawDone();
u32 OSDisableInterrupts();
void OSRestoreInterrupts(u32);
u64 OSGetTime();
void VIWaitForRetrace();
extern u8 lbl_8059FFF8;
}

struct Entry {
    u32 pad;
    s32 state;
};

struct Obj {
    u8 pad0[4];
    u8 count;
    u8 pad5;
    u8 f6;
    u8 f7;
    Entry entries[7];
    u64 t40;
    u8 pad48[0x10];
    u64 t58;
    u64 t60;
    u64 t68;
    u8 pad70[4];
    u8 f74;
};

static bool hasFree(Obj* p) {
    for (int i = 0; i < p->count; i++) {
        if (p->entries[i].state == 0) return true;
    }
    return false;
}

extern "C" void fn_80023AE4(Obj* arg0) {
    fn_801F0A30();
    while (!hasFree(arg0)) {
        arg0->f74 &= ~0x20;
        arg0->t58 = OSGetTime();
        VIWaitForRetrace();
        u64 now = OSGetTime();
        arg0->t60 = now;
        arg0->t68 = now - arg0->t58;
        arg0->f74 |= 0x20;
    }
    if ((arg0->f74 >> 3) & 1) {
        u32 irq = OSDisableInterrupts();
        fn_801F0CE8(fn_80023D90);
        fn_80023ECC(arg0);
        if (arg0->f6 == 0xF1) arg0->f6 = 0;
        Entry* e = &arg0->entries[arg0->f7];
        if (e->state == 0) {
            e->state = 1;
            u8 cur = arg0->f7;
            s32 nxt = cur + 1;
            arg0->f6 = cur;
            arg0->f7 = (u8)nxt;
            if ((u8)nxt >= arg0->count) arg0->f7 = 0;
            if (lbl_8059FFF8 == 0) lbl_8059FFF8 = 1;
        }
        GXSetDrawDone();
        OSRestoreInterrupts(irq);
    } else {
        fn_8002402C(arg0);
    }
    arg0->t40 = OSGetTime();
    fn_801F08D8(0xF000);
}
