#pragma force_active on
extern "C" void* fn_113_EDB0(void* object, short deleting);

extern "C" void* fn_113_EE28(void* p, short flags) {
    if (p != 0) {
        fn_113_EDB0(p, 0);
        if (flags > 0) {
            ::operator delete(p);
        }
    }
    return p;
}
