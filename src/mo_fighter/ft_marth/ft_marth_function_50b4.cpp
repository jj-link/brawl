#pragma force_active on
typedef short s16;

extern "C" {
void* __dt__20soResourceModuleImplFv(void*, s16);
void* fn_106_512C(void*, s16);
void __dl__FPv(void*);

void* fn_106_50B4(void* p, s16 n) {
    if (p != 0) {
        __dt__20soResourceModuleImplFv((char*)p + 0xC, (s16)-1);
        if (p != 0) {
            fn_106_512C(p, (s16)0);
        }
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
