#pragma force_active on
extern "C" void* fn_113_155E4(void* object, short flag);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_113_15588(void* object, short flag) {
    if (object != 0) {
        fn_113_155E4(object, (short)0);
        if (flag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
