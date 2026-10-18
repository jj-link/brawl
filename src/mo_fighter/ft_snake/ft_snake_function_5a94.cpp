#pragma force_active on
extern "C" void* fn_122_5A94(void* p, short flags) {
    if (p != 0 && flags > 0) {
        ::operator delete(p);
    }
    return p;
}
