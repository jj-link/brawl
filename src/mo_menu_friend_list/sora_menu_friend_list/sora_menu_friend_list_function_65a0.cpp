#pragma force_active on

#include <gf/gf_task.h>

extern "C" {
int fn_800D69C8(void*, int);
void fn_800CCEC4(void*, int);
void fn_800BF830(void*);
extern void* g_muWifiInterfaceTask;
extern unsigned char lbl_14_rodata_21C[0x70];
extern unsigned char lbl_14_rodata_480[0x38];
}

struct MenuObject {
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13(void*) = 0;
};

struct Entry {
    unsigned char a;
    unsigned char b;
    unsigned char c;
    unsigned char pad;
    unsigned short d;
    unsigned char e;
    unsigned char pad2;
};

struct Self {
    char pad0[0x40];
    unsigned char f40;
    char pad41[3];
    int f44;
    char pad48[0x190 - 0x48];
    struct F190 {
        char pad[0x10];
        void* f10;
    } *f190;
    char pad194[0x1e0 - 0x194];
    MenuObject* f1e0;
    char pad1e4[0x24c4 - 0x1e4];
    int f24c4;
    char pad24c8[0x24ec - 0x24c8];
    struct F24EC {
        char pad[0x104];
        int status;
    } *f24ec;
    char pad24f0[0x2a1c - 0x24f0];
    MenuObject* f2a1c;
    int f2a20;
    char pad2a24[0x2a30 - 0x2a24];
    unsigned char f2a30;
    char pad2a31[3];
    int f2a34;
    unsigned char f2a38;
};

extern "C" int fn_14_65A0(Self* self) {
    int status;

    if (self->f40 == 0) {
        int result = fn_800D69C8(g_muWifiInterfaceTask, 0);
        switch (result) {
        case 0:
            status = 0;
            break;
        case 1:
            status = 1;
            break;
        case 2:
            status = 2;
            break;
        }
    }

    if (self->f24ec->status == 3) {
        if (self->f40 == 0) {
            fn_800CCEC4(g_muWifiInterfaceTask, 0);
        }
        status = 4;
    }

    if (status == 1) {
        int index = self->f2a20;
        Entry entry;

        entry.a = lbl_14_rodata_21C[index * 3];
        entry.b = *(&lbl_14_rodata_21C[index * 3] + 1);
        entry.c = *(&lbl_14_rodata_21C[index * 3] + 2);

        if (self->f2a30 == 0 &&
            (index == 6 || index == 0x12 || index == 0x16 || index == 0x1c)) {
            entry.a = 0x11;
            entry.c = 6;
        }

        entry.d = *(unsigned short*)&entry;
        entry.e = entry.c;
        self->f44 = lbl_14_rodata_480[entry.c];
        return 0x21;
    }

    if (status == 2 || status == 4) {
        fn_800BF830(self->f24ec);
        ((gfTask*)self->f24ec)->exit();
        self->f24ec = 0;
        self->f1e0->v13(self->f190->f10);
        self->f2a1c->v13(self->f1e0);

        if (status == 2) {
            self->f2a34 = 0x1b;
            self->f2a38 = 1;
        } else {
            self->f2a38 = 0;
            self->f2a34 = 0x19;
        }
        return 0xd;
    }

    return self->f24c4;
}
