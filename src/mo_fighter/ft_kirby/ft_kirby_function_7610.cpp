#pragma force_active on
extern "C" void* fn_96_75B0(void* object, short deleting);
extern "C" void* fn_96_74D8(void* object, short deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_96_7610(void* object, short deleting) {
    if (object != 0) {
        fn_96_75B0(static_cast<unsigned char*>(object) + 0x4480, -1);
        if (object != 0) {
            fn_96_74D8(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
