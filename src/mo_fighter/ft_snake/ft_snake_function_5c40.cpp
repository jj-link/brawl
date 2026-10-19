#pragma force_active on
extern "C" void* fn_122_5CBC(void* object, short deleting);
extern "C" void* fn_122_5F08(void* object, short deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_122_5C40(void* object, short deleting) {
    if (object != 0) {
        fn_122_5CBC(static_cast<unsigned char*>(object) + 0x18CB8, -1);
        if (object != 0) {
            fn_122_5F08(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
