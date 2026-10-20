#pragma force_active on
extern "C" void* fn_112_CACC(void* object, short deleting);
extern "C" void* fn_112_C998(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_112_CB2C(void* object, short deleting) {
    if (object != 0) {
        fn_112_CACC(static_cast<char*>(object) + 0x204, -1);
        if (object != 0) {
            fn_112_C998(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
