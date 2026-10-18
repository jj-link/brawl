#pragma force_active on
extern "C" void fn_126_2F34(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_126_3DB0(void* object, short deleting) {
    if (object != 0) {
        fn_126_2F34(static_cast<unsigned char*>(object) + 0x88, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
