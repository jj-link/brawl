#pragma force_active on
typedef int s32;
extern void fn_8035B120(s32, void **);
extern void fn_8035A5C8(void *, void **);
void fn_80374778(void *arg0) {
    void *sp8 = arg0;
    if (*(s32 *)((char *)arg0 + 0xC) != 7) {
        *(s32 *)((char *)arg0 + 0xC) = 7;
        fn_8035B120(*(s32 *)((char *)*(void **)((char *)sp8 + 8) + 0xC), &sp8);
        fn_8035A5C8(*(void **)((char *)*(void **)((char *)sp8 + 8) + 0x10), &sp8);
    }
}
