#pragma force_active on
extern "C" void* fn_120_2260(void* p, short flags) {
    if (p != 0 && flags > 0) {
        operator delete(p);
    }
    return p;
}
