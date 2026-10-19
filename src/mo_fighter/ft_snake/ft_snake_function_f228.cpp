#pragma force_active on
extern "C" {
void* __dt__21ftExtendParamAccesserFv(void*, short);
void __dl__FPv(void*);

void* fn_122_F228(void* p, short size) {
    if (p != 0) {
        __dt__21ftExtendParamAccesserFv(p, 0);
        if (size > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
