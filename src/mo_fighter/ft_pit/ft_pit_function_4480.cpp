#pragma force_active on
extern "C" void* fn_112_4480(void* p, short size) {
    if (p != 0 && size > 0) {
        operator delete(p);
    }
    return p;
}
