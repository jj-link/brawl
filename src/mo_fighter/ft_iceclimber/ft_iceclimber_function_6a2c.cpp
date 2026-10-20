#pragma force_active on
extern "C" void* fn_27_1A1B88(void*, short);
extern "C" void* fn_105_6AA4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_105_6A2C(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1B88(static_cast<unsigned char*>(object) + 0x218, -1);
        if (object != 0) {
            fn_105_6AA4(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
