#pragma force_active on
extern "C" {
void fn_94_1AD0(void* p, short flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_94_1C48(void* p, short flag) {
    if (p != 0) {
        fn_94_1AD0(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
