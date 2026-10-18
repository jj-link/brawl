#pragma force_active on
void operator delete(void* p);

extern "C" void* fn_68_56B4(void* p, int n) {
    if (p != 0 && n > 0) {
        operator delete(p);
    }
    return p;
}
