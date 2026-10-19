#pragma force_active on
extern "C" void* __dt__21ftExtendParamAccesserFv(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" {
void* fn_121_AD90(void* p1, short p2);
}

void* fn_121_AD90(void* p1, short p2) {
    if (p1 != 0) {
        __dt__21ftExtendParamAccesserFv(p1, 0);
        if (p2 > 0) {
            __dl__FPv(p1);
        }
    }
    return p1;
}
