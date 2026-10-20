#pragma force_active on
extern "C" void fn_27_8B600(void* p, short p2);

extern "C" void* fn_27_26F554(void* p, int del) {
    if (p) {
        fn_27_8B600(p, 0);
        if (del > 0) {
            ::operator delete(p);
        }
    }
    return p;
}
