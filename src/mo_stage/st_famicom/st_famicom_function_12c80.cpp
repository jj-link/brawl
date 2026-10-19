#pragma force_active on
extern "C" void fn_68_23FC(void* self, int flag);

extern "C" void* fn_68_12C80(void* p, int del) {
    if (p) {
        fn_68_23FC(p, 0);
        if (del > 0) {
            ::operator delete(p);
        }
    }
    return p;
}
