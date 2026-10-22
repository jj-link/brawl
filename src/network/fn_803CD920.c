#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern void *fn_803CD2E0(void);
extern s32 fn_803CD32C(void);
extern s32 fn_803CD284(s32 size);
extern void fn_803CD298(s32 p);
extern s32 fn_803CF870(s32 a, s32 b, s32 c, void *d, s32 e);
extern void fn_803CFBE4(s32 a, void *b);
extern void fn_803CD830(void);
extern void fn_803CD834(void);

void fn_803CD920(void) {
    s32 temp_r3;
    s32 temp_r3_2;
    char *temp_r31;

    temp_r31 = (char *)fn_803CD2E0();
    if (fn_803CD32C() == 0) {
        temp_r3 = fn_803CD284(0x100);
        *(s32 *)(temp_r31 + 0xA0) = temp_r3;
        temp_r3_2 = fn_803CF870(1, temp_r3, 0x100, (void *)fn_803CD834, 0);
        if (temp_r3_2 != 6 && (temp_r3_2 >= 6 || temp_r3_2 != 0)) {
            fn_803CD298(*(s32 *)(temp_r31 + 0xA0));
            *(s32 *)(temp_r31 + 0xA0) = 0;
            fn_803CFBE4(1, 0);
        }
    } else {
        fn_803CFBE4(1, (void *)fn_803CD830);
    }
}
