#pragma force_active on
extern "C" void fn_93_D91C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_93_D97C(void* object, short deleting) {
    if (object != 0) {
        fn_93_D91C(static_cast<char*>(object) + 8, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
