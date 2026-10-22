#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern void fn_8035A5C8(void *, void **);
extern void fn_8035B120(s32, void **);
extern void fn_80373C54(void *, s32);
extern void fn_8037765C(void);
extern void fn_80377AD0(void *);
extern void fn_803782F8(void *);

void fn_803746D0(void *arg0, s32 arg1) {
    void *sp8;

    if (arg1 != 0) {
        if (*(s32 *)((char *)arg0 + 0xC) < 7) {
            sp8 = arg0;
            if (*(s32 *)((char *)arg0 + 0xC) != 7) {
                *(s32 *)((char *)arg0 + 0xC) = 7;
                fn_8035B120(*(s32 *)((char *)*(void **)((char *)sp8 + 0x8) + 0xC), &sp8);
                fn_8035A5C8(*(void **)((char *)*(void **)((char *)sp8 + 0x8) + 0x10), &sp8);
            }
            fn_80377AD0(arg0);
            fn_80373C54(arg0, 0);
            fn_803782F8(arg0);
        }
    } else {
        *(s32 *)((char *)arg0 + 0xC) = 6;
        fn_8037765C();
    }
}
