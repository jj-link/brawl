#pragma force_active on
extern "C" void fn_113_22E38(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_113_1575C(void* object, short deleting) {
    if (object != 0) {
        fn_113_22E38(static_cast<char*>(object) + 0x158, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
