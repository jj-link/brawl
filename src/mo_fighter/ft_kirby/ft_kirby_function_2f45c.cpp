#pragma force_active on
extern "C" void fn_96_4E2C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_96_2F45C(void* object, short deleting) {
    if (object != 0) {
        fn_96_4E2C(static_cast<unsigned char*>(object) + 0x1C, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
