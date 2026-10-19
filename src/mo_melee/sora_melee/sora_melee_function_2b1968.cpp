#pragma force_active on
extern "C" void* fn_27_2B1968(void* p, int n) {
    if (p != 0) {
        if (n > 0) {
            ::operator delete(p);
        }
    }
    return p;
}
