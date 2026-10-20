#pragma force_active on
extern "C" void* __dt__20soResourceModuleImplFv(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" {
void* fn_27_2BC770(void* p, int flag);
}

void* fn_27_2BC770(void* p, int flag) {
    if (p) {
        if (p) {
            __dt__20soResourceModuleImplFv(static_cast<unsigned char*>(p) + 0xC, -1);
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
