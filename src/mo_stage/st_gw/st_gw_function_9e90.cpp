#pragma force_active on
extern "C" void* fn_63_9E90(void* p, int n) {
    if (p != 0) {
        if (n > 0) {
            ::operator delete(p);
        }
    }
    return p;
}
