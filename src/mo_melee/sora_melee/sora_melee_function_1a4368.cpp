#pragma force_active on
void operator delete(void*);

extern "C" void* fn_27_1A4368(void* p, int n) {
    if (p != 0 && n > 0) {
        operator delete(p);
    }
    return p;
}
