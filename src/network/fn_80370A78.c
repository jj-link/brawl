#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern s32 fn_8035B2D0(void *a, void *b, void *c);
extern void fn_80370A58(void *a, void *d);

s32 fn_80370A78(void **arg0, s32 arg1, s32 arg2) {
    void *sp[4];
    void *temp_r7;

    temp_r7 = *arg0;
    sp[1] = (void *)arg1;
    sp[2] = (void *)arg2;
    sp[0] = (void *)arg0;
    return fn_8035B2D0(*(void **)((char *)temp_r7 + 0x444), (void *)fn_80370A58, &sp[0]) == 0;
}
