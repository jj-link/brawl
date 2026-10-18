#pragma force_active on
extern "C" void operator delete(void* p);

extern "C" void* fn_102_1D30(void* p, short flags) {
    if (p != 0 && flags > 0) {
        operator delete(p);
    }
    return p;
}
