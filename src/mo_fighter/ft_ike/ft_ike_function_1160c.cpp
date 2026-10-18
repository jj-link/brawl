#pragma force_active on
extern "C" void* fn_119_1160C(void* p, short flag) {
    if (p != 0 && flag > 0) {
        operator delete(p);
    }
    return p;
}
