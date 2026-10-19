#pragma force_active on
extern "C" {
void fn_88_4D64(void* p, int arg);
}

extern "C" void* fn_88_8040(void* p, int flag) {
    if (p) {
        fn_88_4D64(p, 0);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
