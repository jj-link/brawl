#pragma force_active on
void operator delete(void* p);

extern "C" {
void* fn_25_C78(void* p, int n);
}

extern "C" void* fn_25_C78(void* p, int n) {
    if (p != 0 && n > 0) {
        operator delete(p);
    }
    return p;
}
