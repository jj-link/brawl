#pragma force_active on
extern "C" void* fn_96_1C18C(void* p, short n) {
    if (p != 0 && n > 0) {
        operator delete(p);
    }
    return p;
}
