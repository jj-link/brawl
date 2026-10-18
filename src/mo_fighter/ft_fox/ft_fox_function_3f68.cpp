#pragma force_active on
extern "C" void fn_97_3C1C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_97_3F68(void* object, short deleting) {
    if (object != 0) {
        fn_97_3C1C(static_cast<unsigned char*>(object) + 0x14, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
