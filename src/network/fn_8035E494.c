#include <types.h>
#pragma force_active on
typedef struct Obj {
    s32 unk0;
    u32 unk4;
    u32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    void *unk20;
    void *unk24;
    void (*unk28)();
    void (*unk2C)();
    s32 (*unk30)();
    s32 (*unk34)();
} Obj;
extern char lbl_805348E0[];
void fn_8035D24C(void *);
void fn_8035D250(void *);
u32 fn_8035D728(void);
void fn_8035E00C(void *);
s32 fn_8035E494(Obj *obj) {
    char *base = lbl_805348E0;
    s32 state = 0;
    s32 r29;
    char *cursor;
    s32 i;
    if (obj == 0) return 4;
    if (obj->unk14 != 0 && obj->unk34 != 0)
        state = obj->unk34(obj->unk20);
    if (obj->unk18 == 0 && state == 1) {
        if (obj->unk4 != 0 && fn_8035D728() - obj->unk8 > obj->unk4) {
            base = lbl_805348E0;
            fn_8035D24C(base + 0x10);
            if (obj->unk14 != 0 && obj->unk18 == 0) {
                void (*f)() = obj->unk2C;
                obj->unk18 = 1;
                if (f != 0) f(obj->unk20);
            }
            fn_8035D250(base + 0x10);
            if (obj->unk1C != 0) {
                void (*g)() = obj->unk28;
                obj->unk1C = 0;
                if (g != 0) g(obj->unk20, 3);
            }
        }
    } else if (state != 1) {
        r29 = 1;
        if (obj->unk14 != 0) {
            if (obj->unk1C != 0) {
                void (*h)() = obj->unk28;
                obj->unk1C = 0;
                if (h != 0) h(obj->unk20);
            }
            obj->unk14 = 0;
        }
        if (obj->unk30 != 0) r29 = obj->unk30(obj->unk20);
        if (r29 != 0) {
            fn_8035D24C(base + 0x10);
            cursor = base;
            for (i = 0; i < 0x28; cursor += 4, i++) {
                if (*(Obj **)(cursor + 0x28) == obj) {
                    *(void **)(base + 0x28 + i * 4) = 0;
                    fn_8035E00C(obj);
                    break;
                }
            }
            fn_8035D250(base + 0x10);
            return 4;
        }
    }
    return 1;
}