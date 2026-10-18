#pragma force_active on
extern "C" void* fn_94_4888(void* p, short n) {
    if (p != 0) {
        if (n > 0) {
            ::operator delete(p);
        }
    }
    return p;
}
