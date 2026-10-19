#pragma force_active on
void operator delete(void* p);

extern "C" {
void* fn_27_2B1028(void* p, int n);
}

extern "C" void* fn_27_2B1028(void* p, int n) {
    if (p && n > 0) {
        operator delete(p);
    }
    return p;
}
