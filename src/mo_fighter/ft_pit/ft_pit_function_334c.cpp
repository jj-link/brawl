#pragma force_active on
extern "C" void* fn_112_33A8(void* object, short deleting);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_112_334C(void* obj, short deleting) {
    if (obj != 0) {
        fn_112_33A8(obj, 0);
        if (deleting > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}
