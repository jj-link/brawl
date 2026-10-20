#pragma force_active on
extern "C" void fn_93_1BB4(void* p, short x);

extern "C" void* fn_93_1DE4(void* p, short flags) {
    if (p != 0) {
        fn_93_1BB4(p, 0);
        if (flags > 0) {
            operator delete(p);
        }
    }
    return p;
}
