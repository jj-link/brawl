#pragma force_active on
extern "C" void fn_102_3D0C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_102_3CAC(void* object, short deleting) {
    if (object != 0) {
        fn_102_3D0C(static_cast<char*>(object) + 12, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
