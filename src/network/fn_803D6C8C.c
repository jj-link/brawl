#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;
typedef int s32;

extern char lbl_805644C0[];

typedef struct { char pad[0x1F8C]; u16 f; char pad2[0x1FBC-0x1F8E]; u32 id; char pad3[0x1FC8-0x1FC0]; } E;

void fn_803D6C8C(u32 arg0) {
    s32 i;
    for (i = 0; i < 0x1A; i++) {
        E *e = (E *)(lbl_805644C0 + 0xA0) + i;
        if (e->id == arg0) {
            if (e->f & 8) {
                e->f |= 0x20;
            }
            e->f &= ~0xC;
        }
    }
}
