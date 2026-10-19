#pragma force_active on
void operator delete(void* p);

extern "C" {
void fn_88_4D64(void* p, int flag);
void* fn_88_5760(void* p, int n);
}

extern "C" void* fn_88_5760(void* p, int n) {
    if (p != 0) {
        fn_88_4D64(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
