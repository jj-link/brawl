#pragma force_active on
extern "C" void* fn_121_285C(void* ptr, short count);

extern "C" void* fn_121_12B5C(void* p, short n) {
    if (p != 0) {
        fn_121_285C(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
