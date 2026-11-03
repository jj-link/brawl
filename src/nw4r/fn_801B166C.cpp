#include <types.h>
#pragma force_active on

extern "C" u32 GetResNodeNumEntries__Q34nw4r3g3d6ResMdlFv(void*);
extern "C" void* GetResNode__Q34nw4r3g3d6ResMdlCFUl(void*, u32);
extern "C" void fn_801AE08C(void*, void*, void*);
extern "C" void fn_80197AFC(s8*, u32*, void*);
extern "C" void fn_80197A40(u32*, void*);

struct HandlerObj {
    virtual void vf0();
    virtual void vf1(u32, void*, void*, void*);
};

struct MdlObj {
    u8 pad0[0xd4];
    void* h;
    u8 b;
    u8 pad1[1];
    u16 hw;
    u8 pad2[4];
    u8 pad3[8];
    u32 mdl;
    u8 pad4[0x3c];
    void* h2;
    u8 pad5[0x10];
    u32 flag;
    u8 pad6[8];
    u8* flags;
};

extern "C" void fn_801B166C(void* self_, void* arg1, void* arg2) {
    MdlObj* p = (MdlObj*)self_;
    u32 sp10;
    u32 spC;
    u32 sp8;

    fn_801AE08C(self_, arg1, arg2);
    if (!(p->flag & 2) && (p->flag & 1)) {
        sp8 = p->mdl;
        u32 count = GetResNodeNumEntries__Q34nw4r3g3d6ResMdlFv(&sp8);
        if (p->flags) {
            u32 i = 0;
            if (count) {
                while (i < count) {
                    void* node = GetResNode__Q34nw4r3g3d6ResMdlCFUl(&sp8, i);
                    u32 nv;
                    if (node)
                        nv = (*(u32*)((u8*)node + 0x14) >> 8) & 1;
                    else
                        nv = 0;
                    if (nv)
                        p->flags[i] = 1;
                    else
                        p->flags[i] = 0;
                    i++;
                }
            }
        }
        p->flag &= ~1;
    }

    void* h2v = p->h2;
    if (h2v) {
        if (p->flags) {
            sp10 = p->mdl;
            fn_80197AFC((s8*)p->flags, &sp10, h2v);
            p->flag |= 1;
        } else {
            spC = p->mdl;
            fn_80197A40(&spC, h2v);
        }
    }

    if (p->h && (p->hw & 1) && (p->b & 4))
        ((HandlerObj*)p->h)->vf1(4, self_, arg1, arg2);
}