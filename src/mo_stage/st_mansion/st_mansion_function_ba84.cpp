#pragma force_active on
extern "C" {
void fn_47_17B4(void* p, int flag);
void __dl__FPv(void* p);

void* fn_47_BA84(void* p, int flag) {
    if (p != 0) {
        fn_47_17B4(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
