#pragma force_active on
extern "C" void* fn_110_451C(void* p, short n) {
    if (p && n > 0) {
        operator delete(p);
    }
    return p;
}
