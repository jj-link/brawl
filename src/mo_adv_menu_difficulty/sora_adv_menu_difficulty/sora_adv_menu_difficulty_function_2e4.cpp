#pragma force_active on
extern "C" {
void operator delete(void* p);
void* fn_32_2E4(void* p, int n);
}

extern "C" void* fn_32_2E4(void* p, int n) {
    if (p != 0 && n > 0) {
        operator delete(p);
    }
    return p;
}
