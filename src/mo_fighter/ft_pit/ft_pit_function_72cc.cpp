#pragma force_active on
extern "C" void* fn_112_7328(void* object, short deleting);

extern "C" void* fn_112_72CC(void* p, short flags) {
    if (p != 0) {
        fn_112_7328(p, 0);
        if (flags > 0) {
            operator delete(p);
        }
    }
    return p;
}
