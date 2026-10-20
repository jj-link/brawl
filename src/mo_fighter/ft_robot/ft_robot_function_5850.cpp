#pragma force_active on
extern "C" void* __dt__17soModelModuleImplFv(void*, short);
extern "C" void* fn_120_58C8(void*, short);
extern "C" void* fn_27_19A83C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_5850(void* object, short deleteFlag) {
    if (object != 0) {
        __dt__17soModelModuleImplFv(static_cast<unsigned char*>(object) + 0x1F4, -1);
        fn_120_58C8(static_cast<unsigned char*>(object) + 0x1AC, -1);
        fn_27_19A83C(object, -1);
        if (deleteFlag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
