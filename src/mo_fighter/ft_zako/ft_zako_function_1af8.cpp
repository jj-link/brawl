#pragma force_active on
typedef short s16;

extern "C" {
void fn_126_1980(void* p, s16 v);
void __dl__FPv(void* p);

void* fn_126_1AF8(void* p, s16 flag) {
    if (p != 0) {
        fn_126_1980(p, (s16)0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
