#pragma force_active on
void operator delete(void* p);

extern "C" void* fn_110_4FF4(void* p, short n) {
    if (p != 0 && n > 0) {
        operator delete(p);
    }
    return p;
}
