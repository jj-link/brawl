#pragma force_active on
extern "C" void fn_102_33C0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_102_41DC(void* object, short deleting) {
    if (object != 0) {
        fn_102_33C0(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
