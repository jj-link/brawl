#pragma force_active on
extern "C" void fn_113_2D6C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_113_2D0C(void* object, short deleting) {
    if (object != 0) {
        fn_113_2D6C(static_cast<unsigned char*>(object) + 0xC, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
