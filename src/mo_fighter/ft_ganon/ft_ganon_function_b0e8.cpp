#pragma force_active on
typedef short s16;

extern "C" {
void fn_109_B070(void* p, s16 n);

void* fn_109_B0E8(void* p, s16 flag) {
    if (p != 0) {
        fn_109_B070(p, 0);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
}
