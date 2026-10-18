#pragma force_active on
extern "C" void* fn_110_DBF8(void* p, short flags) {
    if (p != 0) {
        if (flags > 0) {
            operator delete(p);
        }
    }
    return p;
}
