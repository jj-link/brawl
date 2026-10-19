#pragma force_active on
extern "C" void* fn_27_3544C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" {
void* fn_41_2F3D4(void* p1, short p2) {
    if (p1 != 0) {
        fn_27_3544C(p1, -1);
        if (p2 > 0) {
            __dl__FPv(p1);
        }
    }
    return p1;
}
}
