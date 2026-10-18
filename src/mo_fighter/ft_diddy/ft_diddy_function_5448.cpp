#pragma force_active on
extern "C" void* fn_115_3A2C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_5448(void* object, short deleting) {
    if (object != 0) {
        fn_115_3A2C(static_cast<unsigned char*>(object) + 0xF8, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
