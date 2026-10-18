#pragma force_active on
extern "C" void* fn_102_17380(void* p, short flags) {
    if (p != 0 && flags > 0) {
        ::operator delete(p);
    }
    return p;
}
