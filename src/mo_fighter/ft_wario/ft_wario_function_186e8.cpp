#pragma force_active on
void operator delete(void* p);

extern "C" void* fn_110_186E8(void* p, short flags) {
    if (p != 0 && flags > 0) {
        operator delete(p);
    }
    return p;
}
