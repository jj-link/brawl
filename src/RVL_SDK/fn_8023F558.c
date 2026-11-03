#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct Ent {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u16 unkC;
    u8 unkE;
    u8 unkF;
    char name1[0x16];
    char name2[0x16];
} Ent;

extern void fn_802319FC(s32, void *, s32);
extern void fn_80231A2C(s32, void *, s32, void *, s32);
extern void fn_80231A74(s32, void *, u16, u8, s32, u16, u32, s32);
extern int strncmp(const char *, const char *, unsigned long);
extern char *strncpy(char *, const char *, unsigned long);
extern u8 lbl_804814C8[];
extern u8 lbl_80529CF8[];

s32 fn_8023F558(s32 arg0, char *arg1, u8 arg2, s32 arg3, u16 arg4, u32 arg5, s32 arg6)
{
    u8 *base = lbl_804814C8;
    Ent *e;
    u16 i;
    u16 freeIdx;
    s32 found;

    freeIdx = 0xFFFF;
    e = (Ent *)(lbl_80529CF8 + 0x1990);
    found = 0;
    i = 0;

    while (i < 0x18) {
        if (e->unkE & 0x80) {
            if (e->unkC == arg4 && e->unk0 == arg5 && arg2 == e->unkF
                && (strncmp(arg1, e->name1, 0x15) == 0 || strncmp(arg1, e->name2, 0x15) == 0)) {
                found = 1;
                break;
            }
        } else if (found == 0) {
            found = 1;
            freeIdx = i;
        }
        i++;
        e++;
    }

    if (found != 0) {
        if (i >= 0x18) {
            i = freeIdx;
            e = (Ent *)((u32)lbl_80529CF8 + i * 0x3C + 0x1990);
        }
        e->unkC = arg4;
        e->unkF = arg2;
        e->unk0 = arg5;
        if (arg0 != 0) {
            e->unk4 = arg6;
            e->unkE = (u8)(e->unkE & 0xFFFFFFC7);
            strncpy(e->name1, arg1, 0x15);
        } else {
            e->unk8 = arg6;
            e->unkE &= 0xF8;
            strncpy(e->name2, arg1, 0x15);
        }
        e->unkE |= (arg3 | 0x80);
        if (lbl_80529CF8[0x27C0] >= 3) {
            fn_80231A74(0xD0002, base + 0xE0, i, arg2, arg0, arg4, arg5, arg6);
        }
        if (lbl_80529CF8[0x27C0] >= 3) {
            fn_80231A2C(0xD0002, base + 0x128, e->unkE, arg1, 0x15);
        }
    } else if (lbl_80529CF8[0x27C0] >= 2) {
        fn_802319FC(0xD0001, base + 0x170, 0x18);
    }
    return found;
}
