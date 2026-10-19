#pragma force_active on
extern "C" void* fn_27_1A1E70(void*, short);
extern "C" void* fn_107_74E4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_107_7474(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1E70(static_cast<unsigned char*>(object) + 0x1C, -1);
        fn_107_74E4(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
