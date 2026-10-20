#pragma force_active on
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void* fn_102_4BA8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_102_4B30(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A15B8(static_cast<char*>(object) + 0x1FC, -1);
        if (object != 0) {
            fn_102_4BA8(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
