#pragma force_active on
extern "C" void fn_110_B7C8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_110_9D30(void* object, short deleting) {
    if (object != 0) {
        fn_110_B7C8(static_cast<char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
