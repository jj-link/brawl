#include <types.h>
#pragma force_active on

extern s32 fn_803974FC(void);
extern void *fn_80397564(void);
extern void **fn_80397570(s32);
extern void fn_80392738(void *dst, s32 count);
extern void fn_803944E4(s32 *);
extern s32 fn_80394664(s32 *);
extern s32 fn_8039471C(s32 *);
extern s32 fn_80394870(s32 *);
extern s32 fn_803949F0(s32 *);
extern s32 fn_80394B44(s32 *);
extern s32 fn_80394FE0(s32 *);
extern s32 fn_803951CC(s32 *);
extern void fn_803954C8(s32 *);

struct Loc {
    s32 sp8;
    u8 bufA[0x100];
    u8 bufB[0x200];
    u8 pad0[0x10];
    s32 sp31C;
    s32 sp320;
    u8 pad1[8];
    s32 sp32C;
    u8 pad2[4];
    s32 sp334;
    s32 sp338;
    s32 sp33C;
    s32 sp340;
    s32 sp344;
};

void fn_80395AB8(void)
{
    struct Loc L;
    s32 t;
    u8 *temp_r27;
    void **temp_r28;
    s32 temp_r3;
    s32 temp_r3_2;

    t = fn_803974FC();
    temp_r27 = (u8 *)fn_80397564();
    temp_r28 = fn_80397570(t);
    L.sp8 = -1;
    fn_80392738(L.bufA, 0x100);
    fn_80392738(L.bufB, 0x200);
    L.sp31C = -1;
    L.sp320 = -1;
    L.sp32C = 0;
    L.sp340 = 0;
    L.sp344 = 0;
    L.sp33C = 0;
    L.sp334 = 0;
    L.sp338 = 0;
    while (*(s32 *)(temp_r27 + 0x7dc) == 0) {
        if (L.sp33C == 0) {
            if (fn_80394664(&L.sp8) != 0) {
                if (*(s32 *)(*(u8 **)((u8 *)*temp_r28 + 0xc)) != 0) {
                    fn_803944E4(&L.sp8);
                } else if (fn_8039471C(&L.sp8) == 0) {
                    fn_803944E4(&L.sp8);
                } else {
                    goto block_7;
                }
            }
        } else {
block_7:
            if (L.sp33C == 1) {
                L.sp33C = 0;
            }
            if (fn_80394870(&L.sp8) == 0) {
                fn_803944E4(&L.sp8);
            } else {
                temp_r3 = fn_803949F0(&L.sp8);
                switch (temp_r3) {
                case 2:
                    L.sp33C = 1;
                    break;
                case 1:
                    fn_803944E4(&L.sp8);
                    break;
                case 0:
                default:
                    temp_r3_2 = fn_80394B44(&L.sp8);
                    switch (temp_r3_2) {
                    case 2:
                        L.sp33C = 1;
                        break;
                    case 1:
                    case 3:
                        fn_803944E4(&L.sp8);
                        break;
                    case 0:
                    default:
                        if (*(s32 *)(*(u8 **)((u8 *)*temp_r28 + 0xc)) != 0) {
                            fn_803944E4(&L.sp8);
                        } else if (fn_80394FE0(&L.sp8) == 0) {
                            fn_803944E4(&L.sp8);
                        } else if (fn_803951CC(&L.sp8) == 0) {
                            fn_803944E4(&L.sp8);
                        } else {
                            fn_803954C8(&L.sp8);
                            fn_803944E4(&L.sp8);
                        }
                        break;
                    }
                    break;
                }
            }
        }
    }
}
