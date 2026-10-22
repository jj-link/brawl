#pragma force_active on
extern "C" unsigned char *fn_801A12A0();
extern "C" void fn_801F5448(int arg0, float f0, float f1, float f2, float f3, float f4, float f5);
extern "C" void fn_801F5484(float farg0, float farg1, float farg2, float farg3, float farg4, float farg5);

extern "C" void fn_801A8048(void **arg0) {
    void *obj = *arg0;
    if (obj != 0) {
        unsigned char *ptr = fn_801A12A0();
        if (ptr[0x18]) {
            fn_801F5448(((*(int *)((char *)obj + 0x70)) >> 8) & 1,
                *(float *)((char *)obj + 0xDC),
                *(float *)((char *)obj + 0xE0),
                *(float *)((char *)obj + 0xE4),
                *(float *)((char *)obj + 0xE8),
                *(float *)((char *)obj + 0xEC),
                *(float *)((char *)obj + 0xF0));
        } else {
            fn_801F5484(*(float *)((char *)obj + 0xDC),
                *(float *)((char *)obj + 0xE0),
                *(float *)((char *)obj + 0xE4),
                *(float *)((char *)obj + 0xE8),
                *(float *)((char *)obj + 0xEC),
                *(float *)((char *)obj + 0xF0));
        }
    }
}
