#pragma force_active on
extern "C" void* fn_96_2FC8(void* object, short deleteFlag);
extern "C" void* fn_27_19A83C(void* object, short deleteFlag);
extern "C" void __dt__25soModelModuleImplVariableFv(void*, short);

extern "C" void* fn_96_3024(void* object, short deleting) {
    if (object != 0) {
        __dt__25soModelModuleImplVariableFv(static_cast<unsigned char*>(object) + 0x1F4, -1);
        fn_96_2FC8(static_cast<unsigned char*>(object) + 0x1AC, -1);
        fn_27_19A83C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
