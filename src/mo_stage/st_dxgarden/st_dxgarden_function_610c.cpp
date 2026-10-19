#pragma force_active on
extern "C" {
void fn_77_F54(void*, int);
}

extern "C" void* fn_77_610C(void* p, int n) {
    if (p) {
        fn_77_F54(p, 0);
        if (n > 0) {
            ::operator delete(p);
        }
    }
    return p;
}
