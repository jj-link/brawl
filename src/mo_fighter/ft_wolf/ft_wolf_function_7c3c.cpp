#pragma force_active on
extern "C" {
void __dt__17soModelModuleImplFv(void*, short);
void* fn_125_7CB4(void*, short);
void* fn_27_19A47C(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_125_7C3C(void* object, short deleteFlag) {
    if (object != 0) {
        __dt__17soModelModuleImplFv(static_cast<char*>(object) + 0x25C, -1);
        fn_125_7CB4(static_cast<char*>(object) + 0x214, -1);
        fn_27_19A47C(object, -1);
        if (deleteFlag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
