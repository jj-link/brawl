#pragma force_active on
extern "C" void fn_102_1E8C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_102_3B68(void* object, short deleting) {
    if (object != 0) {
        fn_102_1E8C(static_cast<char*>(object) + 8, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
