#pragma force_active on
extern "C" void fn_96_11F3C(void* object, short deleting);
extern "C" void fn_96_11E08(void* object, short flag);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_96_11F9C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_96_11F3C(storage + 0x134, -1);
        if (object != 0) {
            fn_96_11E08(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
