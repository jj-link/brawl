#pragma force_active on
extern "C" void* fn_93_5F28(void* p, short n) {
    if (p && n > 0) {
        operator delete(p);
    }
    return p;
}
