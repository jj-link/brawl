#pragma force_active on
extern "C" {
void* fn_106_93DC(void* array, short release);
void fn_106_92A8(void* obj, short release);
void __dl__FPv(void* p);
}

extern "C" void* fn_106_943C(void* p, short flag) {
    short neg = -1;
    short zero = 0;
    if (p != 0) {
        fn_106_93DC((char*)p + 0x204, neg);
        if (p != 0) {
            fn_106_92A8(p, zero);
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
