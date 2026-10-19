#pragma force_active on
extern "C" {
typedef short s16;

void __dl__FPv(void*);
void fn_121_1BB4(void*, s16);

void* fn_121_1D88(void* p0, s16 p1) {
    if (p0) {
        fn_121_1BB4(p0, 0);
        if (p1 > 0) {
            __dl__FPv(p0);
        }
    }
    return p0;
}
}
