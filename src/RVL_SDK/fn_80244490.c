#include <types.h>
#pragma force_active on

extern unsigned char lbl_804821B0[];
extern unsigned char lbl_804821F4[];
extern unsigned char lbl_8052C4C0[];

extern void fn_802319FC(u32, const char *);
extern void fn_80231A14(u32, const char *, u32, void *);
extern u8 fn_8023C69C(void *, void (*)(u16 *));
extern s32 fn_8023C974(s32);
extern void *memcpy(void *, const void *, u32);
extern u32 strlen(const char *);
extern s32 strncmp(const char *, const char *, u32);

void fn_80244490(u16 *arg0) {
    unsigned char *base = lbl_8052C4C0;
    unsigned char *result = base + 0x34;
    u16 value;
    void (*callback)(int, void *);

    if (base[0x7E]) {
        if (*arg0 == 0) {
            if (base[0x28] >= 4) {
                fn_80231A14(0xE0003, (const char *)lbl_804821B0, *arg0, arg0 + 2);
            }
            if (strncmp((const char *)result + 8, (const char *)(arg0 + 2),
                        strlen((const char *)(result + 2) + 6)) == 0) {
                memcpy(result + 2, *(char **)(base + 0x30) + 2, 6);
                *(u16 *)result = 0;
            } else {
                *(s32 *)(base + 0x30) = fn_8023C974(*(s32 *)(base + 0x30));
                if (*(s32 *)(base + 0x30) != 0) {
                    if (fn_8023C69C((void *)(*(s32 *)(base + 0x30) + 2),
                                    fn_80244490) == 1) {
                        return;
                    }
                    switch ((u8)*arg0) {
                    case 0: value = 0; break;
                    case 1: value = 0x10B; break;
                    case 2: value = 0x103; break;
                    case 4:
                    case 5: value = 0x109; break;
                    case 6: value = 0x10C; break;
                    case 7: value = 0x10D; break;
                    case 8: value = 0x115; break;
                    default: value = 0x114; break;
                    }
                    *(u16 *)result = value;
                } else {
                    *(u16 *)result = 0x102;
                }
            }
        } else {
            if (base[0x28] >= 4) {
                fn_802319FC(0xE0003, (const char *)lbl_804821F4);
            }
            switch ((u8)*arg0) {
            case 0: value = 0; break;
            case 1: value = 0x10B; break;
            case 2: value = 0x103; break;
            case 4:
            case 5: value = 0x109; break;
            case 6: value = 0x10C; break;
            case 7: value = 0x10D; break;
            case 8: value = 0x115; break;
            default: value = 0x114; break;
            }
            *(u16 *)result = value;
        }

        callback = *(void (**)(int, void *))(base + 0x2C);
        if (callback != 0) {
            callback(5, result);
        }
        base[0x7E] = 0;
        *(void (**)(int, void *))(base + 0x2C) = 0;
    }
}
