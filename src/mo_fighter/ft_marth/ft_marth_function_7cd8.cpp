#pragma force_active on
extern "C" {
extern void* __dt__21ftExtendParamAccesserFv(void*, short);
extern void __dl__FPv(void*);

void* fn_106_7CD8(void* p, short n) {
    if (p != 0) {
        __dt__21ftExtendParamAccesserFv(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
