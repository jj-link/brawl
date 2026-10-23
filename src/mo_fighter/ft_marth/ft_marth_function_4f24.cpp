#pragma force_active on
extern "C" {
int fn_106_4F80(void*, short);
void __dl__FPv(void*);

void* fn_106_4F24(void* p, short n) {
    if (p != 0) {
        fn_106_4F80(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
