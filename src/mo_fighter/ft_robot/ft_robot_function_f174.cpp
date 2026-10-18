#pragma force_active on
extern "C" void* fn_120_F174(void* p, short n) {
    if (p && n > 0) {
        operator delete(p);
    }
    return p;
}
