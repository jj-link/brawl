#pragma force_active on
extern "C" void* fn_122_48DC(void* p, short size) {
    if (p != 0 && size > 0) {
        operator delete(p);
    }
    return p;
}
