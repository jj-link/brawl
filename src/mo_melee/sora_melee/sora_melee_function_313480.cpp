#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
void __dl__FPv(void*);
void fn_27_3135A8(void* p, s32 n);

void* fn_27_313480(void* p, s32 flag) {
    if (p) {
        if (p && (u32)p + 4) {
            fn_27_3135A8((char*)p + 0xc, -1);
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
