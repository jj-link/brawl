#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern void fn_803974FC(void);
extern s32 fn_80397580(void);
extern void *fn_803970D4(s32 a, s32 b);
extern s32 fn_80397094(s32 a, void *b);
extern void fn_80391B8C(s32 a, s32 b);
extern s32 fn_8039702C(s32 a, void *b);
extern void fn_803900A0(void *p);

void NHTTPDestroyResponse(s32 arg0) {
    s32 temp_r31;
    void *temp_r30;

    fn_803974FC();
    temp_r31 = fn_80397580();
    temp_r30 = fn_803970D4(temp_r31, arg0);
    if (temp_r30 != 0) {
        if (fn_80397094(temp_r31, temp_r30) != 0) {
            fn_80391B8C(temp_r31, *(s32 *)((char *)temp_r30 + 0x14));
        }
        fn_8039702C(temp_r31, temp_r30);
        fn_803900A0(temp_r30);
    }
}
