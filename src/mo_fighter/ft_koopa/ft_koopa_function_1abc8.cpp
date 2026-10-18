#pragma force_active on
extern "C" void* fn_27_1A262C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_102_1ABC8(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A262C(static_cast<unsigned char*>(object) + 0x10, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
