#pragma force_active on
extern "C" void* fn_126_1C0C(void* p, short n) {
    if (p != 0 && n > 0) {
        operator delete(p);
    }
    return p;
}
