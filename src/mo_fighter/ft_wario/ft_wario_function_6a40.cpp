#pragma force_active on
extern "C" void __dt__25soModelModuleImplVariableFv(void*, short);
extern "C" void* fn_110_6AB8(void*, short);
extern "C" void* fn_27_19A83C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_110_6A40(void* object, short deleting) {
    if (object != 0) {
        __dt__25soModelModuleImplVariableFv(static_cast<unsigned char*>(object) + 0x1F4, -1);
        fn_110_6AB8(static_cast<unsigned char*>(object) + 0x1AC, -1);
        fn_27_19A83C(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
