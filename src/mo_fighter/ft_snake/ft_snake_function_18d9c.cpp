#pragma force_active on
extern "C" void fn_122_5A94(void* p, short flags);

extern "C" void* fn_122_18D9C(void* p, short flags) {
    if (p != 0) {
        fn_122_5A94(p, 0);
        if (flags > 0) {
            operator delete(p);
        }
    }
    return p;
}
