#pragma force_active on
extern "C" void fn_112_C8D8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_112_C938(void* object, short deleting) {
    if (object != 0) {
        fn_112_C8D8(static_cast<char*>(object) + 8, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
