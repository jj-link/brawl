#pragma force_active on
extern "C" void* fn_102_AEB4(void* object, short deleting);
extern "C" void* fn_102_AD80(void* object, short deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_102_AF14(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_102_AEB4(storage + 0x204, -1);
        if (object != 0) {
            fn_102_AD80(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
