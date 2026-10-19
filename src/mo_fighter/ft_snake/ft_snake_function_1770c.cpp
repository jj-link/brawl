#pragma force_active on
extern "C" {

void* fn_122_17768(void* p, short flag);
void __dl__FPv(void* p);

void* fn_122_1770C(void* p, short flag) {
    if (p != 0) {
        fn_122_17768(p, 0);
        if ((short)flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

}
