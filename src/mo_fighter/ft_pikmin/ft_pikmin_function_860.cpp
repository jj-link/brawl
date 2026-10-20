#pragma force_active on
typedef short s16;

extern "C" {
void fn_113_68C(void* p, s16 flag);

void* fn_113_860(void* p, s16 n) {
    if (p != 0) {
        fn_113_68C(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
}
