#pragma force_active on
extern "C" {
void* fn_125_63A0(void* object, short deleting);
void __dl__FPv(void* p);
}

extern "C" void* fn_125_6344(void* p1, short p2) {
    if (p1 != 0) {
        fn_125_63A0(p1, 0);
        if (p2 > 0) {
            __dl__FPv(p1);
        }
    }
    return p1;
}
