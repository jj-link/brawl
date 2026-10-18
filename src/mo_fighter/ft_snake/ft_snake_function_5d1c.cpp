#pragma force_active on
extern "C" void* fn_122_5D7C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_5D1C(void* object, short deleting) {
    if (object != 0) {
        fn_122_5D7C(static_cast<char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
