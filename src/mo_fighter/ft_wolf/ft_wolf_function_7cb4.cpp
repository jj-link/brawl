#pragma force_active on
extern "C" {
void* fn_27_CC7EC(void* member, short deleteFlag);
void __dl__FPv(void* p);
}

extern "C" void* fn_125_7CB4(void* p, short flag) {
    if (p != 0) {
        fn_27_CC7EC(p, -1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
