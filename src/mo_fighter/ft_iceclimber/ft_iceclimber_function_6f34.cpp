#pragma force_active on
extern "C" void fn_105_3C24(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_105_6F34(void* object, short deleting) {
    if (object != 0) {
        fn_105_3C24(static_cast<unsigned char*>(object) + 0x88, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
