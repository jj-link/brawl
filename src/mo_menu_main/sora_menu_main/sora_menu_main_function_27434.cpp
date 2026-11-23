#include <types.h>
#pragma force_active on

extern "C" {
extern void* g_GameGlobal;
void* fn_8004E5D8(void*, void*);
void fn_803F8ACC(void*, unsigned int, unsigned int, void*);
}

struct MenuEntry {
    int pad0;
    int key;
    unsigned char flag;
    int sum;
};

extern "C" int fn_2_27514(MenuEntry*, MenuEntry*);

struct Menu {
    char pad0[0x678];
    unsigned char* buf;
};

extern "C" void fn_2_27434(Menu* self, int sum) {
    int key;
    int off4;
    int off12;
    int joff;
    int i;

    i = 0;
    off4 = 0;
    off12 = 0;
    while (i < (s32)self->buf[0x8c]) {
        int j;
        sum = 0;
        j = 0;
        joff = 0;
        *(int*)(self->buf + off12 + 0x90) = *(int*)(self->buf + off4);
        *(unsigned char*)(self->buf + off12 + 0x98) = (unsigned char)i;
        while (j < (s32)self->buf[0x8c]) {
            key = *(int*)(self->buf + joff);
            int a = *(int*)(off4 + (int)self->buf);
            unsigned short* tbl = (unsigned short*)fn_8004E5D8(g_GameGlobal, (void*)a);
            sum += tbl[key];
            joff += 4;
            j += 1;
        }
        *(int*)(self->buf + off12 + 0x94) = sum;
        off4 += 4;
        off12 += 12;
        i += 1;
    }
    if (self->buf[0x8c] > 1) {
        fn_803F8ACC(self->buf + 0x90, self->buf[0x8c], 12, fn_2_27514);
    }
}
