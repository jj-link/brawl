#pragma force_active on
extern "C" void* fn_122_7ED0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_7E70(void* object, short deleting) {
    if (object != 0) {
        fn_122_7ED0(static_cast<char*>(object) + 8, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
