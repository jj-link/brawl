#pragma force_active on
void operator delete(void*);

extern "C" void* fn_102_423C(void* p, short n) {
    if (p != 0 && n > 0) {
        operator delete(p);
    }
    return p;
}
