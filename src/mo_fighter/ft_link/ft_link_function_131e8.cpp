#pragma force_active on
extern "C" void fn_93_486C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_93_131E8(void* object, short deleting) {
    if (object != 0) {
        fn_93_486C(static_cast<unsigned char*>(object) + 0x24, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
