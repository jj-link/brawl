#pragma force_active on
extern "C" {
void* fn_27_1A1E70(void*, short);
void fn_100_5258(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_100_51E0(char* object, short flag) {
    if (object != 0) {
        fn_27_1A1E70(object + 0x4B8, static_cast<short>(-1));
        if (object != 0) {
            fn_100_5258(object, static_cast<short>(0));
        }
        if (flag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
