#pragma force_active on
extern "C" void* fn_102_F27C(void* p, short n) {
    if (p != 0 && n > 0) {
        operator delete(p);
    }
    return p;
}
