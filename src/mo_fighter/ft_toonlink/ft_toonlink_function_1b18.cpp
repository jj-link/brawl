#pragma force_active on
extern "C" {
extern void* fn_121_1AD8(void* p, short n);
extern void __dl__FPv(void* p);

void* fn_121_1B18(void* p, short n) {
    if (p != 0) {
        fn_121_1AD8(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
