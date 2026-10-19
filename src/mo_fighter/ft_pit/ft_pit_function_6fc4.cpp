#pragma force_active on
extern "C" void* fn_112_3BA4(void* p, short n);

extern "C" void* fn_112_6FC4(void* p, short flags) {
    if (p != 0) {
        fn_112_3BA4(p, 0);
        if (flags > 0) {
            operator delete(p);
        }
    }
    return p;
}
