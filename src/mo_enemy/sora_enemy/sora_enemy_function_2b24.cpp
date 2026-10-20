#pragma force_active on
extern "C" void fn_27_D2904(void* member, int deleteFlag);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void* fn_27_CD934(void* object, short flag);
extern "C" void* fn_41_2AC4(void* ptr, short flag);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_2B24(void* p, short flag) {
    if (p) {
        __destroy_arr((char*)p + 0x38, fn_27_D2904, 0x3c, 1);
        fn_27_CD934((char*)p + 0x18, -1);
        fn_41_2AC4(p, 0);
        if (flag > 0)
            __dl__FPv(p);
    }
    return p;
}
