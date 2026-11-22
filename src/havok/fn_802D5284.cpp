#pragma force_active on

#include <types.h>

extern "C" {
extern char lbl_80487688[];
extern int __cntlzw(unsigned int);

struct Elem {
    char pad[0x11];
    s8 flag;
    char rest[0x30 - 0x12];
};

struct Obj {
    void* m_00;
    char pad4[2];
    short m_06;
    char pad8[4];
    void* m_0c;
    char pad10[0x34 - 0x10];
    char* m_34;
    int m_38;
};

void fn_802D5284(Obj* __restrict self, int* __restrict p) {
    self->m_06 = 1;
    self->m_00 = lbl_80487688;
    self->m_0c = lbl_80487688 + 0x28;
    if (*p == 0) {
        return;
    }
    int off;
    Elem* e;
    for (int i = 0, dummy = (off = 0); i < self->m_38; i++) {
        e = (Elem*)(self->m_34 + off);
        if ((s8)((u32)__cntlzw(e->flag) >> 5)) {
            e->flag = 1;
        }
        off += 0x30;
    }
}
}