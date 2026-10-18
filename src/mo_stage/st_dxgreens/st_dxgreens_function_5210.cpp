#pragma force_active on
extern "C" void* fn_79_5210(void* p, int n) {
    if (p != 0 && n > 0) {
        operator delete(p);
    }
    return p;
}
