#pragma force_active on
void operator delete(void*);
extern "C" void __dt__17soModelModuleImplFv(void*, short);
extern "C" void* fn_97_7D8C(void*, short);
extern "C" void* fn_27_19A47C(void*, short);

extern "C" void* fn_97_7D14(void* object, short deleteFlag) {
    if (object != 0) {
        unsigned char* self = static_cast<unsigned char*>(object);
        __dt__17soModelModuleImplFv(self + 0x25C, -1);
        fn_97_7D8C(self + 0x214, -1);
        fn_27_19A47C(object, -1);
        if (deleteFlag > 0) {
            operator delete(object);
        }
    }
    return object;
}
