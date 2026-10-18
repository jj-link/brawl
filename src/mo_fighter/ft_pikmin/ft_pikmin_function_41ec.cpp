#pragma force_active on
extern "C" void fn_113_424C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_113_41EC(void* object, short deleting) {
    if (object != 0) {
        fn_113_424C(static_cast<char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
