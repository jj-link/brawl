#pragma force_active on
extern "C" void fn_115_C558(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_C5B8(void* object, short deleting) {
    if (object != 0) {
        fn_115_C558(static_cast<char*>(object) + 8, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
