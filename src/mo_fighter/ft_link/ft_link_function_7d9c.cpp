#pragma force_active on
extern "C" void* fn_93_7D2C(void* object, short deleting);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_93_7D9C(void* p, short deleting) {
    if (p != 0) {
        fn_93_7D2C(p, -1);
        if (deleting > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
