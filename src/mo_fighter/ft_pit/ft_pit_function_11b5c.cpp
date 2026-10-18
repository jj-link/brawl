#pragma force_active on
extern "C" void fn_112_11AFC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_112_11B5C(void* object, short deleting) {
    if (object != 0) {
        fn_112_11AFC(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
