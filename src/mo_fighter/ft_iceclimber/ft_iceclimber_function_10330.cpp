#pragma force_active on
extern "C" {
void fn_105_10240(void* p, short kind);
void __dl__FPv(void* p);

void* fn_105_10330(void* p, short flag) {
    if (p != 0) {
        fn_105_10240(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
