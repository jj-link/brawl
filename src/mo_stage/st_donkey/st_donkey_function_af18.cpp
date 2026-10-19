#pragma force_active on
extern "C" void fn_50_2034(void*, int);

extern "C" void* fn_50_AF18(void* p, int flag) {
    if (p != 0) {
        fn_50_2034(p, 0);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
