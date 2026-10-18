#pragma force_active on
extern "C" void* fn_96_67C0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_96_7550(void* object, short deleting) {
    if (object != 0) {
        fn_96_67C0(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
