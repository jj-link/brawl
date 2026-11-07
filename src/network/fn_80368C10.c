#include <types.h>
#pragma force_active on

#define FIELD_S32(b, o) (*(s32 *)((u8 *)(b) + (o)))
#define FIELD_U8(b, o) (*(u8 *)((u8 *)(b) + (o)))

extern void fn_8035E00C(void *p);
extern void fn_8036EEE4(void **p, void *node);
extern s32 fn_80370A78(void **p, s32 a, s32 b);
extern s32 fn_80368BF4(u32 unused, u32 *arg2);

s32 fn_80368C10(void **arg0) {
    void *temp = *arg0;
    void *node;

    FIELD_U8(temp, 0x110) = 0;
    FIELD_U8(temp, 0x12F) = 0;
    FIELD_U8(temp, 0x144) = 0;
    FIELD_S32(temp, 0x1F0) = -1;
    FIELD_S32(temp, 0x1F4) = 0;
    FIELD_S32(temp, 0x200) = 0;
    FIELD_S32(temp, 0x204) = 0;
    FIELD_S32(temp, 0x1FC) = 0;
    fn_8035E00C(*(void **)((u8 *)temp + 0x1F8));
    FIELD_S32(temp, 0x1F8) = 0;
    FIELD_S32(temp, 0x20C) = 0;
    fn_8035E00C(*(void **)((u8 *)temp + 0x208));
    FIELD_S32(temp, 0x208) = 0;
    FIELD_S32(temp, 0x218) = 0;
    FIELD_S32(temp, 0x21C) = 0;
    FIELD_S32(temp, 0x214) = 0;
    fn_8035E00C(*(void **)((u8 *)temp + 0x210));
    FIELD_S32(temp, 0x210) = 0;
    FIELD_S32(temp, 0x464) = 0;
    FIELD_S32(temp, 0x468) = 0;
    FIELD_S32(temp, 0x460) = 0;
    fn_8035E00C(*(void **)((u8 *)temp + 0x45C));
    FIELD_S32(temp, 0x45C) = 0;
    FIELD_S32(temp, 0x474) = 0;
    FIELD_S32(temp, 0x478) = 0;
    FIELD_S32(temp, 0x470) = 0;
    fn_8035E00C(*(void **)((u8 *)temp + 0x46C));
    FIELD_S32(temp, 0x46C) = 0;
    FIELD_S32(temp, 0x220) = -1;
    FIELD_S32(temp, 0x228) = 2;
    while ((node = *(void **)((u8 *)temp + 0x440)) != 0) {
        fn_8036EEE4(arg0, node);
    }
    FIELD_S32(temp, 0x440) = 0;
    FIELD_S32(temp, 0x44C) = 0;
    fn_80370A78(arg0, (s32)fn_80368BF4, 0);
    FIELD_S32(temp, 0x19C) = 0;
    FIELD_S32(temp, 0x1A0) = 0;
    FIELD_S32(temp, 0x198) = 0;
    FIELD_S32(temp, 0x22C) = 0;
    FIELD_S32(temp, 0x438) = 0;
    FIELD_S32(temp, 0x450) = 0;
    FIELD_S32(temp, 0x230) = -1;
    FIELD_U8(temp, 0x234) = 0;
    FIELD_U8(temp, 0x334) = 0;
    return 0;
}
