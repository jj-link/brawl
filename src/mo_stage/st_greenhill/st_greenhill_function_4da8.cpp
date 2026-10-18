#pragma force_active on
extern "C" void* fn_72_4DA8(void* p, int flag) {
    if (p != 0 && flag > 0) {
        operator delete(p);
    }
    return p;
}
