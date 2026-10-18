#pragma force_active on
extern "C" void* fn_110_168F8(void* p, short flag) {
    if (p != 0 && flag > 0) {
        operator delete(p);
    }
    return p;
}
