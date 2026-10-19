#pragma force_active on
extern "C" void fn_112_CB2C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_112_CBA4(void* object, short shouldDelete) {
    if (object != 0) {
        fn_112_CB2C(object, 0);
        if (shouldDelete > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
