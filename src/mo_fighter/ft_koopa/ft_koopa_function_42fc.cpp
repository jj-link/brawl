#pragma force_active on
extern "C" void fn_102_3A8C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_102_42FC(void* object, short deleting) {
    if (object != 0) {
        fn_102_3A8C(static_cast<unsigned char*>(object) + 0x1C0, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
