#pragma force_active on
typedef signed short s16;

extern "C" {
void fn_113_68C(void* p, s16 flag);
}

extern "C" void* fn_113_7A8(void* p, s16 flag) {
    if (p != 0) {
        fn_113_68C(p, 0);
        if (flag > 0) {
            ::operator delete(p);
        }
    }
    return p;
}
