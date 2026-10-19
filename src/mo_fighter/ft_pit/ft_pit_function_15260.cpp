#pragma force_active on
extern "C" void fn_112_15324(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_112_15260(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            fn_112_15324(static_cast<char*>(object) + 4, static_cast<short>(-1));
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
