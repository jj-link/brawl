#pragma force_active on
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void* fn_108_6D58(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_108_6CE0(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A15B8(static_cast<char*>(object) + 0x11C, -1);
        if (object != 0) {
            fn_108_6D58(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
