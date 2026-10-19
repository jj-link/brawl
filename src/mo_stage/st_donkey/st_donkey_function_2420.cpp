#pragma force_active on
extern "C" void fn_50_2034(void*, int);

extern "C" void* fn_50_2420(void* p, int flags) {
    if (p != 0) {
        fn_50_2034(p, 0);
        if (flags > 0) {
            operator delete(p);
        }
    }
    return p;
}
