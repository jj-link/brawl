#pragma force_active on
extern "C" void* fn_119_4F44(void* p, short flags);

extern "C" void* fn_119_4EE8(void* p, short flags) {
    if (p != 0) {
        fn_119_4F44(p, 0);
        if (flags > 0) {
            ::operator delete(p);
        }
    }
    return p;
}
